#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura de dados: Território
struct Territorio {
    char nome[30];
    char cor[15];
    int tropas;
};


// cadastrar os territórios
void cadastrarTerritorios(struct Territorio *territorios, int qtd) {
    printf("=== Cadastro de Territórios ===\n\n");
    for (int i = 0; i < qtd; i++) {
        printf("Cadastro do Território %d:\n", i + 1);

        printf("Nome: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        // limpa o buffer
        getchar();
        printf("\n");
    }
}


// Exibir o estado do mapa
void exibirMapa(struct Territorio *territorios, int qtd) {
    printf("\n=== Estado Atual do Mapa ===\n\n");
    for (int i = 0; i < qtd; i++) {
         printf("Território %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }
}

// Batalha entre dois territórios
void simularBatalha(struct Territorio *atacante, struct Territorio *defensor){
    if (atacante->tropas <= 0){
        printf("O território atacante não possui tropas suficientes!\n");
        return;

    }if (defensor->tropas <= 0){
        printf(" O território defensor já foi conquistado! \n");
        return;

    }
    {
    // gera número entre 1 e 6
    int dadoAtacante = (rand() % 6) + 1; 
    int dadoDefensor = (rand() % 6) + 1;
    }
    
    {
        /* code */
    }
    
}
{
    /* data */
};

{
    /* data */
};
)