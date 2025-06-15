#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// Função para exibir o menu de atributos disponíveis

void exibir_menu(int ignorar, int ordem) {
    printf("\n===== Atributos Disponíveis =====\n\n");
    if (ignorar != 1) printf("1. População\n");
    if (ignorar != 2) printf("2. Área\n");
    if (ignorar != 3) printf("3. PIB\n");
    if (ignorar != 4) printf("4. Pontos Turísticos\n");
    if (ignorar != 5) printf("5. Densidade Populacional\n");
    
    ordem == 1 ? printf("\nEscolha o primeiro atributo para comparar: ") : printf("\nEscolha o segundo atributo para comparar: ");
}

// Função para comparar as cartas

float obter_valor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade_populacional;
        default: return 0;
    }
}

// Função para obter o nome do atributo com base no número do atributo

const char* nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função para comparar dois valores de acordo com o atributo escolhido

int comparar(float v1, float v2, int atributo) {
    int resultado;
    if (atributo == 5) {
        if (v1 < v2) resultado = 1;
        else if (v2 < v1) resultado = 2;
        else resultado = 0;
    } else {
        if (v1 > v2) resultado = 1;
        else if (v2 > v1) resultado = 2;
        else resultado = 0;
    }
    return resultado;
}

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

    // Variáveis para armazenar os atributos escolhidos pelo usuário
    int atributo1, atributo2;

    // Exibição do menu e leitura dos atributos escolhidos

    printf("\n===== Super Trunfo - Comparador de Cartas =====\n");
    exibir_menu(0, 1);

    while (scanf("%d", &atributo1) != 1 || atributo1 < 1 || atributo1 > 5) {
        while (getchar() != '\n'); // Limpa o buffer de entrada
        printf("\nOpção inválida. Por favor, escolha uma opção válida (1-5).\n");
        exibir_menu(0, 1);
    }

    exibir_menu(atributo1, 0);

    while (scanf("%d", &atributo2)!= 1 || atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        while (getchar() != '\n'); // Limpa o buffer de entrada
        printf("\nOpção inválida. Por favor, escolha uma opção válida (1-5).\n");
        exibir_menu(atributo1, 0);
    }

    // Exibição dos resultados da comparação

    float valor1_a1 = obter_valor(carta1, atributo1);
    float valor2_a1 = obter_valor(carta2, atributo1);
    float valor1_a2 = obter_valor(carta1, atributo2);
    float valor2_a2 = obter_valor(carta2, atributo2);

    printf("\n===== Comparando: %s (%s) x %s (%s) =====\n\n", carta1.pais, carta1.sigla, carta2.pais, carta2.sigla);

    printf("---> Atributo 1: %s\n\n", nome_atributo(atributo1));
    printf("%s (%s): %.2f\n", carta1.pais, carta1.sigla, valor1_a1);
    printf("%s (%s): %.2f\n\n", carta2.pais, carta2.sigla, valor2_a1);
    int resultado1 = comparar(valor1_a1, valor2_a1, atributo1);
    if (resultado1 == 1) printf("Resultado do atributo 1: %s (%s) venceu!\n\n", carta1.pais, carta1.sigla);
    else if (resultado1 == 2) printf("Resultado do atributo 1: %s (%s) venceu!\n\n", carta2.pais, carta2.sigla);
    else printf("Resultado do atributo 1: Empate!\n\n");

    printf("---> Atributo 2: %s\n\n", nome_atributo(atributo2));
    printf("%s (%s): %.2f\n", carta1.pais, carta1.sigla, valor1_a2);
    printf("%s (%s): %.2f\n\n", carta2.pais, carta2.sigla, valor2_a2);
    int resultado2 = comparar(valor1_a2, valor2_a2, atributo2);
    if (resultado2 == 1) printf("Resultado do atributo 2: %s (%s) venceu!\n\n", carta1.pais, carta1.sigla);
    else if (resultado2 == 2) printf("Resultado do atributo 2: %s (%s) venceu!\n\n", carta2.pais, carta2.sigla);
    else printf("Resultado do atributo 2: Empate!\n\n");

    // Cálculo da soma dos atributos escolhidos

    float soma1 = valor1_a1 + valor1_a2;
    float soma2 = valor2_a1 + valor2_a2;

    printf("===== Soma dos atributos =====\n\n");
    printf("%s (%s): %.2f\n", carta1.pais, carta1.sigla, soma1);
    printf("%s (%s): %.2f\n", carta2.pais, carta2.sigla, soma2);

    printf("\nResultado final: ");
    if (soma1 > soma2)
        printf("%s (%s) venceu!\n", carta1.pais, carta1.sigla);
    else if (soma2 > soma1)
        printf("%s (%s) venceu!\n", carta2.pais, carta2.sigla);
    else
        printf("Empate!\n");

    return 0;
}
