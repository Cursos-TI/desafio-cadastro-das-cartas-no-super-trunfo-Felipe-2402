
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 100

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Cidade;

void calcular_propriedades(Cidade *cidade) {
    cidade->densidade_populacional = (cidade->area > 0) ? cidade->populacao / cidade->area : 0;
    cidade->pib_per_capita = (cidade->populacao > 0) ? cidade->pib / cidade->populacao : 0;
    cidade->super_poder = cidade->populacao + cidade->area + cidade->pib + cidade->pontos_turisticos;
}

void exibir_cidade(Cidade cidade) {
    printf("Código: %s\n", cidade.codigo);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f\n", cidade.area);
    printf("PIB: %.2f\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", cidade.densidade_populacional);
    printf("PIB per Capita: %.2f\n", cidade.pib_per_capita);
    printf("Super Poder: %.2f\n\n", cidade.super_poder);
}

void comparar_cidades(Cidade c1, Cidade c2) {
    printf("\nComparação de Cidades:\n");
    printf("Densidade Populacional: Vencedor - %s\n", (c1.densidade_populacional < c2.densidade_populacional) ? c1.codigo : c2.codigo);
    printf("População: Vencedor - %s\n", (c1.populacao > c2.populacao) ? c1.codigo : c2.codigo);
    printf("Área: Vencedor - %s\n", (c1.area > c2.area) ? c1.codigo : c2.codigo);
    printf("PIB: Vencedor - %s\n", (c1.pib > c2.pib) ? c1.codigo : c2.codigo);
    printf("Pontos Turísticos: Vencedor - %s\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.codigo : c2.codigo);
    printf("PIB per Capita: Vencedor - %s\n", (c1.pib_per_capita > c2.pib_per_capita) ? c1.codigo : c2.codigo);
    printf("Super Poder: Vencedor - %s\n", (c1.super_poder > c2.super_poder) ? c1.codigo : c2.codigo);
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int count = 0;

    while (count < MAX_CIDADES) {
        printf("Digite o código da cidade (ou 'sair' para finalizar): ");
        scanf("%s", cidades[count].codigo);
        if (strcmp(cidades[count].codigo, "sair") == 0) {
            break;
        }
        printf("População: ");
        scanf("%d", &cidades[count].populacao);
        printf("Área: ");
        scanf("%f", &cidades[count].area);
        printf("PIB: ");
        scanf("%f", &cidades[count].pib);
        printf("Número de pontos turísticos: ");
        scanf("%d", &cidades[count].pontos_turisticos);
        
        calcular_propriedades(&cidades[count]);
        count++;
        printf("Cidade cadastrada com sucesso!\n\n");
    }

    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < count; i++) {
        exibir_cidade(cidades[i]);
    }

    if (count >= 2) {
        int escolha1, escolha2;
        printf("\nComparação de cartas:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, cidades[i].codigo);
        }
        printf("Escolha o número da primeira carta: ");
        scanf("%d", &escolha1);
        printf("Escolha o número da segunda carta: ");
        scanf("%d", &escolha2);

        if (escolha1 > 0 && escolha2 > 0 && escolha1 <= count && escolha2 <= count && escolha1 != escolha2) {
            comparar_cidades(cidades[escolha1 - 1], cidades[escolha2 - 1]);
        } else {
            printf("Escolha inválida.\n");
        }
    }

    return 0;
}