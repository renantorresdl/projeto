#include <stdio.h>

int main() {

    // Carta 1
    char estado1;
    char codigo1[5];
    char nome1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos1;

    // Carta 2
    char estado2;
    char codigo2[5];
    char nome2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos2;

    // Variáveis de cálculo
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // =========================
    // Leitura Carta 1
    // =========================

    printf("=== CARTA 1 ===\n");

    printf("Estado: ");
    scanf(" %c", &estado1);

    printf("Codigo: ");
    scanf("%s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Pontos Turisticos: ");
    scanf("%d", &pontos1);

    // =========================
    // Leitura Carta 2
    // =========================

    printf("\n=== CARTA 2 ===\n");

    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Codigo: ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // =========================
    // Cálculos
    // =========================

    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    superPoder1 =
        (float)populacao1 +
        area1 +
        pib1 +
        pontos1 +
        pibPerCapita1 +
        (1.0 / densidade1);

    superPoder2 =
        (float)populacao2 +
        area2 +
        pib2 +
        pontos2 +
        pibPerCapita2 +
        (1.0 / densidade2);

    // =========================
    // Exibição das Cartas
    // =========================

    printf("\n===== CARTA 1 =====\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", nome1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f\n", densidade1);
    printf("PIB per Capita: %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n===== CARTA 2 =====\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", nome2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f\n", densidade2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // =========================
    // Comparações
    // =========================

    printf("\n===== COMPARACAO DE CARTAS =====\n");

    printf("Populacao: %d\n", populacao1 > populacao2);
    printf("Area: %d\n", area1 > area2);
    printf("PIB: %d\n", pib1 > pib2);
    printf("Pontos Turisticos: %d\n", pontos1 > pontos2);

    // Menor densidade vence
    printf("Densidade Populacional: %d\n", densidade1 < densidade2);

    printf("PIB per Capita: %d\n", pibPerCapita1 > pibPerCapita2);
    printf("Super Poder: %d\n", superPoder1 > superPoder2);

    return 0;
}