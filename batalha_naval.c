#include <stdio.h>
#include <windows.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

int main() {

    SetConsoleOutputCP(CP_UTF8);


    // 1. DECLARAÇÃO DO TABULEIRO


    // 0 = água
    // 3 = navio
    // 5 = área afetada por uma habilidade
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];


    // 2. DECLARAÇÃO DOS NAVIOS


    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};


    // 3. COORDENADAS INICIAIS DOS NAVIOS


    int linhaHorizontal = 2;
    int colunaHorizontal = 3;

    int linhaVertical = 5;
    int colunaVertical = 7;



    // 4. COORDENADAS DE ORIGEM DAS HABILIDADES


    // A matriz 5x5 será centralizada nessas coordenadas.
    int linhaCone = 5;
    int colunaCone = 2;

    int linhaCruz = 5;
    int colunaCruz = 5;

    int linhaOctaedro = 5;
    int colunaOctaedro = 8;



    // 5. DECLARAÇÃO DAS MATRIZES DE HABILIDADE

    int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];


    // 6. INICIALIZAÇÃO DO TABULEIRO

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            tabuleiro[linha][coluna] = 0;
        }
    }

    // 7. POSICIONAMENTO DO NAVIO HORIZONTAL

    if (linhaHorizontal >= 0 &&
        linhaHorizontal < TAMANHO_TABULEIRO &&
        colunaHorizontal >= 0 &&
        colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        for (int i = 0; i < TAMANHO_NAVIO; i++) {

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


    // 8. POSICIONAMENTO DO NAVIO VERTICAL

    if (linhaVertical >= 0 &&
        linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaVertical >= 0 &&
        colunaVertical < TAMANHO_TABULEIRO) {

        for (int i = 0; i < TAMANHO_NAVIO; i++) {

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


    // 9. CRIAÇÃO DA MATRIZ DO CONE


    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            // Calcula a distância da coluna em relação ao centro.
            int distancia = coluna - TAMANHO_HABILIDADE / 2;

            if (distancia < 0) {
                distancia = -distancia;
            }

            // Conforme a linha aumenta, o cone fica mais largo.
            if (distancia <= linha) {

                matrizCone[linha][coluna] = 1;

            } else {

                matrizCone[linha][coluna] = 0;
            }
        }
    }


    // 10. CRIAÇÃO DA MATRIZ DA CRUZ


    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            // A posição central da matriz.
            int centro = TAMANHO_HABILIDADE / 2;

            // Se estiver na linha ou coluna central,
            // a posição será afetada.
            if (linha == centro || coluna == centro) {

                matrizCruz[linha][coluna] = 1;

            } else {

                matrizCruz[linha][coluna] = 0;
            }
        }
    }


    // 11. CRIAÇÃO DA MATRIZ DO OCTAEDRO


    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            int centro = TAMANHO_HABILIDADE / 2;

            // Calcula a distância da posição até o centro.
            int distanciaLinha = linha - centro;
            int distanciaColuna = coluna - centro;

            if (distanciaLinha < 0) {
                distanciaLinha = -distanciaLinha;
            }

            if (distanciaColuna < 0) {
                distanciaColuna = -distanciaColuna;
            }

            // Se a distância das duas coordenadas somada
            // for menor ou igual ao centro, pertence ao losango.
            if (distanciaLinha + distanciaColuna <= centro) {

                matrizOctaedro[linha][coluna] = 1;

            } else {

                matrizOctaedro[linha][coluna] = 0;
            }
        }
    }


    // 12. SOBREPOSIÇÃO DO CONE NO TABULEIRO
 

    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            if (matrizCone[linha][coluna] == 1) {

                // Calcula a posição correspondente no tabuleiro.
                int linhaTabuleiro =
                    linhaCone - TAMANHO_HABILIDADE / 2 + linha;

                int colunaTabuleiro =
                    colunaCone - TAMANHO_HABILIDADE / 2 + coluna;

                // Verifica se a posição está dentro do tabuleiro.
                if (linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAMANHO_TABULEIRO) {

                    // Não substitui um navio.
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }



    // 13. SOBREPOSIÇÃO DA CRUZ NO TABULEIRO


    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            if (matrizCruz[linha][coluna] == 1) {

                int linhaTabuleiro =
                    linhaCruz - TAMANHO_HABILIDADE / 2 + linha;

                int colunaTabuleiro =
                    colunaCruz - TAMANHO_HABILIDADE / 2 + coluna;

                if (linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAMANHO_TABULEIRO) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }


    // 14. SOBREPOSIÇÃO DO OCTAEDRO NO TABULEIRO
 

    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            if (matrizOctaedro[linha][coluna] == 1) {

                int linhaTabuleiro =
                    linhaOctaedro - TAMANHO_HABILIDADE / 2 + linha;

                int colunaTabuleiro =
                    colunaOctaedro - TAMANHO_HABILIDADE / 2 + coluna;

                if (linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAMANHO_TABULEIRO) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }


    // 15. EXIBIÇÃO DO TABULEIRO
  

    printf("\n");
    printf("========== BATALHA NAVAL ==========\n\n");

    // Mostra os números das colunas.
    printf("    ");

    for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

        printf("%d ", coluna);
    }

    printf("\n");


    // Mostra o tabuleiro.
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        printf("%d | ", linha);

        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }


    // 16. LEGENDA
 
    printf("\n");
    printf("0 = Agua\n");
    printf("3 = Navio\n");
    printf("5 = Area afetada pela habilidade\n");


    return 0;
}