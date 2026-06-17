#include <stdio.h>

int main() {
    char estado1, estado2;
    char codigo1, codigo2;
    char nomeCidade1, nomeCidade2;
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, pibPerCapita1;
    float densidade2, pibPerCapita2;

    int atributoEscolha1, atributoEscolha2;
    float valorCarta1_Atributo1, valorCarta2_Atributo1;
    float valorCarta1_Atributo2, valorCarta2_Atributo2;
    int resultadoAtributo1 = 0, resultadoAtributo2 = 0;

    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("Digite a População: ");
    scanf("%lu", &populacao1);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a População: ");
    scanf("%lu", &populacao2);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = pib1 / (float)populacao1;
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = pib2 / (float)populacao2;

    printf("\n===================================\n");
    printf("   MENU SELEÇÃO DE ATRIBUTOS\n");
    printf("===================================\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    printf("Escolha o PRIMEIRO atributo para comparar: ");
    scanf("%d", &atributoEscolha1);
    printf("Escolha o SEGUNDO atributo para comparar (deve ser diferente): ");
    scanf("%d", &atributoEscolha2);

    switch(atributoEscolha1) {
        case 1: valorCarta1_Atributo1 = (float)populacao1; valorCarta2_Atributo1 = (float)populacao2; break;
        case 2: valorCarta1_Atributo1 = area1; valorCarta2_Atributo1 = area2; break;
        case 3: valorCarta1_Atributo1 = pib1; valorCarta2_Atributo1 = pib2; break;
        case 4: valorCarta1_Atributo1 = (float)pontosTuristicos1; valorCarta2_Atributo1 = (float)pontosTuristicos2; break;
        case 5: valorCarta1_Atributo1 = densidade1; valorCarta2_Atributo1 = densidade2; break;
        case 6: valorCarta1_Atributo1 = pibPerCapita1; valorCarta2_Atributo1 = pibPerCapita2; break;
        default: valorCarta1_Atributo1 = 0; valorCarta2_Atributo1 = 0;
    }

    switch(atributoEscolha2) {
        case 1: valorCarta1_Atributo2 = (float)populacao1; valorCarta2_Atributo2 = (float)populacao2; break;
        case 2: valorCarta1_Atributo2 = area1; valorCarta2_Atributo2 = area2; break;
        case 3: valorCarta1_Atributo2 = pib1; valorCarta2_Atributo2 = pib2; break;
        case 4: valorCarta1_Atributo2 = (float)pontosTuristicos1; valorCarta2_Atributo2 = (float)pontosTuristicos2; break;
        case 5: valorCarta1_Atributo2 = densidade1; valorCarta2_Atributo2 = densidade2; break;
        case 6: valorCarta1_Atributo2 = pibPerCapita1; valorCarta2_Atributo2 = pibPerCapita2; break;
        default: valorCarta1_Atributo2 = 0; valorCarta2_Atributo2 = 0;
    }

    if(atributoEscolha1 == 5) {
        resultadoAtributo1 = (valorCarta1_Atributo1 < valorCarta2_Atributo1) ? 1 : 2;
    } else {
        resultadoAtributo1 = (valorCarta1_Atributo1 > valorCarta2_Atributo1) ? 1 : 2;
    }

    if(atributoEscolha2 == 5) {
        resultadoAtributo2 = (valorCarta1_Atributo2 < valorCarta2_Atributo2) ? 1 : 2;
    } else {
        resultadoAtributo2 = (valorCarta1_Atributo2 > valorCarta2_Atributo2) ? 1 : 2;
    }

    printf("\n===================================\n");
    printf("--- RESULTADO DO CONFRONTO ---\n");
    printf("Cidade 1: %s | Cidade 2: %s\n\n", nomeCidade1, nomeCidade2);
    
    printf("Resultado Atributo 1: ");
    if(resultadoAtributo1 == 1) printf("Carta 1 (%s) VENCEU!\n", nomeCidade1);
    else printf("Carta 2 (%s) VENCEU!\n", nomeCidade2);

    printf("Resultado Atributo 2: ");
    if(resultadoAtributo2 == 1) printf("Carta 1 (%s) VENCEU!\n", nomeCidade1);
    else printf("Carta 2 (%s) VENCEU!\n", nomeCidade2);

    printf("\n--- RESULTADO FINAL ---\n");
    if(resultadoAtributo1 == resultadoAtributo2) {
        if(resultadoAtributo1 == 1) printf("VENCEDOR GERAL: Carta 1 (%s)!\n", nomeCidade1);
        else printf("VENCEDOR GERAL: Carta 2 (%s)!\n", nomeCidade2);
    } else {
        printf("RESULTADO GERAL: EMPATE (Cada carta venceu em um atributo)!\n");
    }
    printf("===================================\n");

    return 0;
}
