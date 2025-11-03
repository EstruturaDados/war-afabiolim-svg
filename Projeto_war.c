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
    
    
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do território %d:\n", i + 1);
        

        // lê até 29 caracteres, incluindo espaços
        printf("Digite o nome do território: ");
        scanf(" %29[^\n]", territorios[i].nome); 

        // lê até 9 caracteres (sem espaços)
        printf("Digite a cor do exército: ");
        scanf(" %9s", territorios[i].cor); 

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        // pula uma linha entre cadastros
        printf("\n"); 
    }