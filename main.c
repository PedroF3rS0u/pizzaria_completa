#include <stdio.h>
#include "pizza.h"
#include "ingrediente.h"

void menu_principal() {
    int opcao;
    do {
        printf("=== Menu Principal ===\n");
        printf("1. Gerenciar Pizzas\n");
        printf("2. Gerenciar Ingredientes\n");
        printf("3. Exportar Dados\n");
        printf("4. Importar Dados\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listar_pizzas();
                adicionar_pizza();
                break;
            case 2:
                listar_ingredientes();
                adicionar_ingrediente();
                break;
            case 3:
                exportar_pizzas();
                exportar_ingredientes();
                break;
            case 4:
                importar_pizzas();
                importar_ingredientes();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu_principal();
    return 0;
}
