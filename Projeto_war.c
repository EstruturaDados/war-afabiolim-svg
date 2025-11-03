#include <stdio.h>
#include <string.h>

// ----------------------------------------------------------
// Estrutura de dados: Território
// Armazena o nome do território, a cor do exército e a quantidade de tropas.
// ----------------------------------------------------------
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

 // Vetor para armazenar 5 territórios
int main() {
    struct Territorio territorios[5];

      // Entrada de Territorio
    printf("=== Cadastro de Territórios ===\n\n");    
    