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
            case 1: {
                int opcao_pizza;
                do {
                    printf("=== Gerenciar Pizzas ===\n");
                    printf("1. Adicionar Pizza\n");
                    printf("2. Listar Pizzas\n");
                    printf("3. Editar Pizza\n");
                    printf("4. Remover Pizza\n");
                    printf("0. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao_pizza);

                    switch (opcao_pizza) {
                        case 1: adicionar_pizza(); break;
                        case 2: listar_pizzas(); break;
                        case 3: editar_pizza(); break;
                        case 4: remover_pizza(); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while (opcao_pizza != 0);
                break;
            }
            case 2: {
                int opcao_ingrediente;
                do {
                    printf("=== Gerenciar Ingredientes ===\n");
                    printf("1. Adicionar Ingrediente\n");
                    printf("2. Listar Ingredientes\n");
                    printf("3. Editar Ingrediente\n");
                    printf("4. Remover Ingrediente\n");
                    printf("0. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao_ingrediente);

                    switch (opcao_ingrediente) {
                        case 1: adicionar_ingrediente(); break;
                        case 2: listar_ingredientes(); break;
                        case 3: editar_ingrediente(); break;
                        case 4: remover_ingrediente(); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while (opcao_ingrediente != 0);
                break;
            }
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
