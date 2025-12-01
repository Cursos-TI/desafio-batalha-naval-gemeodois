#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Matriz que representa o tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Vetores que representam os navios (tamanho 3)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios (0-based: linhas e colunas de 0 a 9)
    // Você pode mudar esses valores se quiser testar outros posicionamentos
    int linhaInicialHorizontal = 2; // terceira linha
    int colunaInicialHorizontal = 1; // segunda coluna

    int linhaInicialVertical = 5; // sexta linha
    int colunaInicialVertical = 7; // oitava coluna

    // Variáveis auxiliares
    int i, j;
    int valido = 1; // flag para saber se deu tudo certo

    /* ============================
       1) Inicializa o tabuleiro
       ============================ */
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // 0 = água
        }
    }

    /* =====================================
       2) Validação do navio horizontal
          - confere se ele cabe no tabuleiro
       ===================================== */
    if (colunaInicialHorizontal + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio horizontal nao cabe no tabuleiro nessas coordenadas.\n");
        valido = 0;
    }

    /* ===================================
       3) Validação do navio vertical
          - confere se ele cabe no tabuleiro
       =================================== */
    if (linhaInicialVertical + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio vertical nao cabe no tabuleiro nessas coordenadas.\n");
        valido = 0;
    }

    // Se já deu erro até aqui, nem tenta posicionar
    if (!valido) {
        return 1; // encerra o programa com erro
    }

    /* ==========================================
       4) Posiciona o navio horizontal no tabuleiro
       ========================================== */
    for (i = 0; i < TAM_NAVIO; i++) {
        int linha = linhaInicialHorizontal;
        int coluna = colunaInicialHorizontal + i;

        // Como o tabuleiro está vazio, aqui não precisa checar sobreposição ainda
        tabuleiro[linha][coluna] = navioHorizontal[i];
    }

    /* ==========================================================
       5) Validação de sobreposição para o navio vertical
          - antes de posicionar, confere se já tem navio lá
       ========================================================== */
    for (i = 0; i < TAM_NAVIO; i++) {
        int linha = linhaInicialVertical + i;
        int coluna = colunaInicialVertical;

        if (tabuleiro[linha][coluna] == NAVIO) {
            printf("Erro: sobreposicao detectada ao posicionar o navio vertical.\n");
            valido = 0;
            break;
        }
    }

    if (!valido) {
        return 1;
    }

    /* ==========================================
       6) Posiciona o navio vertical no tabuleiro
       ========================================== */
    for (i = 0; i < TAM_NAVIO; i++) {
        int linha = linhaInicialVertical + i;
        int coluna = colunaInicialVertical;

        tabuleiro[linha][coluna] = navioVertical[i];
    }

    /* ==========================================
       7) Exibe as coordenadas de cada parte dos navios
       (usando índice 0-based mesmo, como em matriz)
       ========================================== */
    printf("Coordenadas dos navios:\n\n");

    printf("Navio horizontal (tamanho %d):\n", TAM_NAVIO);
    for (i = 0; i < TAM_NAVIO; i++) {
        int linha = linhaInicialHorizontal;
        int coluna = colunaInicialHorizontal + i;
        printf("  Parte %d -> linha %d, coluna %d\n", i + 1, linha, coluna);
    }

    printf("\nNavio vertical (tamanho %d):\n", TAM_NAVIO);
    for (i = 0; i < TAM_NAVIO; i++) {
        int linha = linhaInicialVertical + i;
        int coluna = colunaInicialVertical;
        printf("  Parte %d -> linha %d, coluna %d\n", i + 1, linha, coluna);
    }

    /* ============================
       8) Exibir o tabuleiro 10x10
       ============================ */
    printf("\nTabuleiro (0 = agua, 3 = navio):\n\n");

    // Cabeçalho de colunas
    printf("   ");
    for (j = 0; j < TAM_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {
        // Número da linha na esquerda
        printf("%2d ", i);
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
