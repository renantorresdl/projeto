    char estado1[20], cidade1[30], codigo1[10];
    int habitantes1, turistico1;
    float area1, pib1;

    char estado2[20], cidade2[30], codigo2[10];
    int habitantes2, turistico2;
    float area2, pib2;

    // CARTA 1
    printf("CARTA1\n");
    printf("Digite o estado: ");
    scanf("%s", estado1);

    printf("Digite o código: ");
    scanf("%s", codigo1);

    printf("Digite a cidade: ");
    scanf("%s", cidade1);

    printf("Quantidade de habitantes: ");
    scanf("%d", &habitantes1);

    printf("Digite a área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o valor do PIB: ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &turistico1);

    printf("\n--------------CARTA1--------------\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %d\n", habitantes1);
    printf("Área: %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turísticos: %d\n", turistico1);

    // CARTA 2
    printf("\nCARTA2\n");
    printf("Digite o estado: ");
    scanf("%s", estado2);

    printf("Digite o código: ");
    scanf("%s", codigo2);

    printf("Digite a cidade: ");
    scanf("%s", cidade2);

    printf("Quantidade de habitantes: ");
    scanf("%d", &habitantes2);

    printf("Digite a área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o valor do PIB: ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &turistico2);

    printf("\n--------------CARTA2--------------\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %d\n", habitantes2);
    printf("Área: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turísticos: %d\n", turistico2);
