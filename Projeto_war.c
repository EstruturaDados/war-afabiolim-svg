#include <stdio.h>
#include <string.h>

// ----------------------------------------------------------
// Estrutura de dados: Território
// Armazena o nome do território, a cor do exército e a quantidade de tropas.
// ----------------------------------------------------------
struct Territorio {
    char nome[30];
    char cor[15];
    int tropas;
};



 // Vetor para armazenar 5 territórios
int main() {
    struct Territorio territorios[5];


    // Painel
    printf("=====================================\n");
    printf("   🗺️  DESAFIO WAR ESTRUTURADO - NIVEL NOVATO\n");
    printf("=====================================\n\n");

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

 // Exibição dos dados
    printf("\n=== Territórios Cadastrados ===\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    printf("\nFim do programa.\n");
    return 0;
}    