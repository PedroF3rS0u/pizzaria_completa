#include <stdio.h>
#include <string.h>
#include "ingrediente.h"

Ingrediente ingredientes[MAX_INGREDIENTES];
int qtd_ingredientes = 0;

void adicionar_ingrediente() {
    if (qtd_ingredientes < MAX_INGREDIENTES) {
        Ingrediente novo_ingrediente;
        printf("ID do Ingrediente: ");
        scanf("%d", &novo_ingrediente.id);
        printf("Nome do Ingrediente: ");
        scanf(" %[^\n]", novo_ingrediente.nome);
        printf("Preco do Ingrediente: ");
        scanf("%f", &novo_ingrediente.preco);

        ingredientes[qtd_ingredientes++] = novo_ingrediente;
        printf("Ingrediente adicionado com sucesso!\n");
    } else {
        printf("Lista de ingredientes cheia!\n");
    }
}

void listar_ingredientes() {
    printf("=== Ingredientes Disponíveis ===\n");
    for (int i = 0; i < qtd_ingredientes; i++) {
        printf("ID: %d, Nome: %s, Preço: %.2f\n",
               ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

void exportar_ingredientes() {
    FILE *arquivo = fopen("ingredientes.txt", "w");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para exportacao!\n");
        return;
    }
    for (int i = 0; i < qtd_ingredientes; i++) {
        fprintf(arquivo, "%d,%s,%.2f\n",
                ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
    fclose(arquivo);
    printf("Ingredientes exportados com sucesso!\n");
}

void importar_ingredientes() {
    FILE *arquivo = fopen("ingredientes.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para importacao!\n");
        return;
    }
    qtd_ingredientes = 0;
    while (fscanf(arquivo, "%d,%[^,],%f\n",
                  &ingredientes[qtd_ingredientes].id, ingredientes[qtd_ingredientes].nome,
                  &ingredientes[qtd_ingredientes].preco) != EOF) {
        qtd_ingredientes++;
    }
    fclose(arquivo);
    printf("Ingredientes importados com sucesso!\n");
}
