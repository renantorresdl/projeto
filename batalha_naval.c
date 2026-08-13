#include <stdio.h>
#include <windows.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {

    SetConsoleOutputCP(CP_UTF8);


    // 1. DECLARAÇÃO DO TABULEIRO
 
    // Matriz 10x10 que representa o tabuleiro.
    // 0 = água
    // 3 = parte de um navio
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];



    // 2. DECLARAÇÃO DOS NAVIOS
    

    // Cada vetor representa um navio de tamanho 3.
    // Todas as posições recebem o valor 3.
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};


    // 3. COORDENADAS INICIAIS DOS NAVIOS
  
    // Coordenada inicial do navio horizontal.
    int linhaHorizontal = 2;
    int colunaHorizontal = 3;

    // Coordenada inicial do navio vertical.
    int linhaVertical = 5;
    int colunaVertical = 7;

    // 4. INICIALIZAÇÃO DO TABULEIRO

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            tabuleiro[linha][coluna] = 0;
        }
    }

    // 5. VALIDAÇÃO DO NAVIO HORIZONTAL


    if (linhaHorizontal >= 0 &&
        linhaHorizontal < TAMANHO_TABULEIRO &&
        colunaHorizontal >= 0 &&
        colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // O navio pode ser colocado no tabuleiro.

        for (int i = 0; i < TAMANHO_NAVIO; i++) {

            // Verifica se a posição está livre.
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == 0) {

                
                tabuleiro[linhaHorizontal][colunaHorizontal + i] =
                    navioHorizontal[i];

            } else {

                printf("Erro: o navio horizontal sobrepoe outro navio.\n");
                return 1;
            }
        }

    } else {

        printf("Erro: coordenadas do navio horizontal invalidas.\n");
        return 1;
    }



    // 6. VALIDAÇÃO DO NAVIO VERTICAL


    if (linhaVertical >= 0 &&
        linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaVertical >= 0 &&
        colunaVertical < TAMANHO_TABULEIRO) {

      

        for (int i = 0; i < TAMANHO_NAVIO; i++) {

            // Verifica se a posição está livre.
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {

               
                tabuleiro[linhaVertical + i][colunaVertical] =
                    navioVertical[i];

            } else {

                printf("Erro: o navio vertical sobrepoe outro navio.\n");
                return 1;
            }
        }

    } else {

        printf("Erro: coordenadas do navio vertical invalidas.\n");
        return 1;
    }


    // 7. EXIBIÇÃO DO TABULEIRO

    printf("\n");
    printf("========== BATALHA NAVAL ==========\n\n");

    // Mostra os números das colunas.
    printf("    ");

    for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

        printf("%d ", coluna);
    }

    printf("\n");


    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        // Mostra o número da linha.
        printf("%d | ", linha);

        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }


    printf("\n");
    printf("0 = Agua\n");
    printf("3 = Navio\n");

    return 0;
}