#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações da carta
struct Carta {
    char estado[3];
    char codigo[4];
    char nome_cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

int main() {
    // Carta 1 com dados pré-definidos
    struct Carta carta1 = {
        "SP", "C01", "São Paulo",
        12300000, 1521.11
    };

    // Carta 2 com dados pré-definidos
    struct Carta carta2 = {
        "RJ", "C02", "Rio de Janeiro",
        6748000, 1200.27, 400.0, 10
    };

    // Cálculo de Densidade Populacional e PIB per capita
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;

    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;

    // Comparação de atributo escolhido: Densidade Populacional
    printf("\nComparação de cartas (Atributo: Densidade Populacional):\n");
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, carta1.densidade_populacional);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, carta2.densidade_populacional);

    // Comparação usando if-else
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    }

    return 0;
}
