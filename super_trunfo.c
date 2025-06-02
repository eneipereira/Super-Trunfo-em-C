#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis da Carta 1
    char estado1, codigo1[4], nome_cidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos_turisticos1;
    float densidade_populacional1, pib_per_capita1, super_poder1;

    // Variáveis da Carta 2
    char estado2, codigo2[4], nome_cidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos_turisticos2;
    float densidade_populacional2, pib_per_capita2, super_poder2;

    // Entrada de dados da Carta 1
    printf("Carta 1:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    getchar(); // Limpa o \n do buffer
    printf("Nome da Cidade: ");
    fgets(nome_cidade1, sizeof(nome_cidade1), stdin);
    nome_cidade1[strcspn(nome_cidade1, "\n")] = '\0'; // Remove o \n final

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Entrada de dados da Carta 2
    printf("\nCarta 2:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    getchar(); // Limpa o \n do buffer
    printf("Nome da Cidade: ");
    fgets(nome_cidade2, sizeof(nome_cidade2), stdin);
    nome_cidade2[strcspn(nome_cidade2, "\n")] = '\0'; // Remove o \n final

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculo de Densidade Populacional, PIB per capita e Super Poder
    densidade_populacional1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    super_poder1 = (float)populacao1 + area1 + (pib1 * 1000000000) + pontos_turisticos1 + pib_per_capita1 + (1 / densidade_populacional1);

    densidade_populacional2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;
    super_poder2 = (float)populacao2 + area2 + (pib2 * 1000000000) + pontos_turisticos2 + pib_per_capita2 + (1 / densidade_populacional2);

    // Saída formatada
    printf("\nComparação de Cartas:\n");
    printf("População: %s venceu (%d)\n", (populacao1 > populacao2 ? "Carta 1" : "Carta 2"), populacao1 > populacao2);
    printf("Área: %s venceu (%d)\n", (area1 > area2 ? "Carta 1" : "Carta 2"), area1 > area2);
    printf("PIB: %s venceu (%d)\n", (pib1 > pib2 ? "Carta 1" : "Carta 2"), pib1 > pib2);
    printf("Pontos Turísticos: %s venceu (%d)\n", (pontos_turisticos1 > pontos_turisticos2 ? "Carta 1" : "Carta 2"), pontos_turisticos1 > pontos_turisticos2);
    printf("Densidade Populacional: %s venceu (%d)\n", (densidade_populacional1 < densidade_populacional2 ? "Carta 1" : "Carta 2"), densidade_populacional1 < densidade_populacional2);
    printf("PIB per Capita: %s venceu (%d)\n", (pib_per_capita1 > pib_per_capita2 ? "Carta 1" : "Carta 2"), pib_per_capita1 > pib_per_capita2);
    printf("Super Poder: %s venceu (%d)\n", (super_poder1 > super_poder2 ? "Carta 1" : "Carta 2"), super_poder1 > super_poder2);

    return 0;
}
