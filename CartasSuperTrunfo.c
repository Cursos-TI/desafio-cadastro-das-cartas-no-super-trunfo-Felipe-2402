super trunfo completo
#include <stdio.h>
#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para armazenar os dados de uma cidade
typedef struct {
    char codigo[4]; // Código da carta, ex: "A01"
    int populacao;  // População da cidade
    float area;     // Área da cidade em km²
    float pib;      // PIB da cidade em milhões
    int pontos_turisticos; // Número de pontos turísticos
} Cidade;

void cadastrar_cidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            // Gerar código da carta
            sprintf(cidades[i][j].codigo, "%c%02d", 'A' + i, j + 1);

            printf("\n--- Cadastro da cidade %s ---\n", cidades[i][j].codigo);
            printf("População: ");
            scanf("%d", &cidades[i][j].populacao);

            printf("Área (em km²): ");
            scanf("%f", &cidades[i][j].area);

            printf("PIB (em milhões): ");
            scanf("%f", &cidades[i][j].pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);
        }
    }
}

void exibir_cidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    printf("\n--- Dados cadastrados ---\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            printf("\nCódigo: %s\n", cidades[i][j].codigo);
            printf("População: %d\n", cidades[i][j].populacao);
            printf("Área: %.2f km²\n", cidades[i][j].area);
            printf("PIB: %.2f milhões\n", cidades[i][j].pib);
            printf("Pontos turísticos: %d\n", cidades[i][j].pontos_turisticos);
        }
    }
}

int main() {
    Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO];

    printf("Bem-vindo ao sistema de cadastro de cartas do Super Trunfo - Países!\n");

    // Cadastro das cidades
    cadastrar_cidades(cidades);

    // Exibição dos dados cadastrados
    exibir_cidades(cidades);

    return 0;
}