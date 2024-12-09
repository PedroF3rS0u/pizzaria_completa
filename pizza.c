#include <stdio.h>
#include <string.h>
#include "pizza.h"

Pizza cardapio[MAX_PIZZAS];
int qtd_pizzas = 0;

void adicionar_pizza() {
    if (qtd_pizzas < MAX_PIZZAS) {
        Pizza nova_pizza;
        printf("ID da Pizza: ");
        scanf("%d", &nova_pizza.id);
        printf("Nome da Pizza: ");
        scanf(" %[^\n]", nova_pizza.nome);
        printf("Tamanho (P/M/G): ");
        scanf(" %c", &nova_pizza.tamanho);
        printf("Preco Base: ");
        scanf("%f", &nova_pizza.preco_base);

        nova_pizza.qtd_ingredientes = 0;
        cardapio[qtd_pizzas++] = nova_pizza;
        printf("Pizza adicionada com sucesso!\n");
    } else {
        printf("Cardapio cheio!\n");
    }
}

void listar_pizzas() {
    printf("=== Pizzas no Cardapio ===\n");
    for (int i = 0; i < qtd_pizzas; i++) {
        printf("ID: %d, Nome: %s, Tamanho: %c, Preco Base: %.2f\n",
               cardapio[i].id, cardapio[i].nome, cardapio[i].tamanho, cardapio[i].preco_base);
    }
}

void exportar_pizzas() {
    FILE *arquivo = fopen("pizzas.txt", "w");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para exportação!\n");
        return;
    }
    for (int i = 0; i < qtd_pizzas; i++) {
        fprintf(arquivo, "%d,%s,%c,%.2f\n",
                cardapio[i].id, cardapio[i].nome, cardapio[i].tamanho, cardapio[i].preco_base);
    }
    fclose(arquivo);
    printf("Pizzas exportadas com sucesso!\n");
}

void importar_pizzas() {
    FILE *arquivo = fopen("pizzas.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para importacao!\n");
        return;
    }
    qtd_pizzas = 0;
    while (fscanf(arquivo, "%d,%[^,],%c,%f\n",
                  &cardapio[qtd_pizzas].id, cardapio[qtd_pizzas].nome,
                  &cardapio[qtd_pizzas].tamanho, &cardapio[qtd_pizzas].preco_base) != EOF) {
        qtd_pizzas++;
    }
    fclose(arquivo);
    printf("Pizzas importadas com sucesso!\n");
}
