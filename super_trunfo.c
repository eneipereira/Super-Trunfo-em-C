#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações da carta
struct Carta {
    char sigla[3];
    char codigo[4];
    char pais[50];
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
        "AR", "A01", "Argentina",
        45380000, 2780000.0, 5000.0, 30
    };

    // Carta 2 com dados pré-definidos
    struct Carta carta2 = {
        "BR", "B01", "Brasil",
        213000000, 8515767.0, 18000.0, 50
    };

    // Cálculo de Densidade Populacional e PIB per capita
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;

    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;

    int opcao;

    // Menu interativo
    printf("===== Super Trunfo - Comparador de Cartas =====\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Populacional\n");
    printf("\nEscolha um atributo para comparar: ");
    scanf("%d", &opcao);

    if (opcao >= 1 && opcao <= 5) {
        printf("\nComparando %s (%s) vs %s (%s)\n", carta1.pais, carta1.sigla, carta2.pais, carta2.sigla);
    }

    switch(opcao) {
        case 1:
            printf("\nPopulacao: %lu vs %lu\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("\n%s venceu!\n", carta1.pais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("\n%s venceu!\n", carta2.pais);
            } else {
                printf("\nEmpate!\n");
            }
            break;
        case 2:
            printf("Area: %.2f vs %.2f\n", carta1.area, carta2.area);
            if (carta1.area > carta2.area) {
                printf("\n%s venceu!\n", carta1.pais);
            } else if (carta2.area > carta1.area) {
                printf("\n%s venceu!\n", carta2.pais);
            } else {
                printf("\nEmpate!\n");
            }
            break;
        case 3:
            printf("PIB: %.2f vs %.2f\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("\n%s venceu!\n", carta1.pais);
            } else if (carta2.pib > carta1.pib) {
                printf("\n%s venceu!\n", carta2.pais);
            } else {
                printf("\nEmpate!\n");
            }
            break;
        case 4:
            printf("Pontos Turisticos: %d vs %d\n", carta1.pontos_turisticos, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("\n%s venceu!\n", carta1.pais);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("\n%s venceu!\n", carta2.pais);
            } else {
                printf("\nEmpate!\n");
            }
            break;
        case 5:
            printf("Densidade Populacional: %.2f vs %.2f\n", carta1.densidade_populacional, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("\n%s venceu!\n", carta1.pais);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("\n%s venceu!\n", carta2.pais);
            } else {
                printf("\nEmpate!\n");
            }
            break;
        default:
            printf("\nOpcao invalida. Por favor, escolha uma opcao de 1 a 5.\n");
            break;
    }

    return 0;
}
