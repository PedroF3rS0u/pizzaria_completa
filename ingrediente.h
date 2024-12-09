#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_NOME 50
#define MAX_INGREDIENTES 100

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
} Ingrediente;

void adicionar_ingrediente();
void listar_ingredientes();
void editar_ingrediente();
void remover_ingrediente();
void exportar_ingredientes();
void importar_ingredientes();

#endif // INGREDIENTE_H
