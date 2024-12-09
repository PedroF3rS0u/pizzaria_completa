#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"

#define MAX_INGREDIENTES 10
#define MAX_NOME 50
#define MAX_PIZZAS 100

typedef struct {
    int id;
    char nome[MAX_NOME];
    char tamanho; // 'P', 'M', 'G'
    float preco_base;
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int qtd_ingredientes;
} Pizza;

void adicionar_pizza();
void listar_pizzas();
void editar_pizza();
void remover_pizza();
void exportar_pizzas();
void importar_pizzas();

#endif // PIZZA_H
