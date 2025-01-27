
#include <stdio.h>
#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
typedef struct {
    char codigo[4]; 
    int populacao;  
    float area;    
    float pib;     
    int pontos_turisticos; 
} Cidade;

void cadastrar_cidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
          
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
    cadastrar_cidades(cidades);
    exibir_cidades(cidades);
    return 0;
}