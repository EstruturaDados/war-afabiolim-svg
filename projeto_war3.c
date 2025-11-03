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


// InicializaTerritorios
void inicializaTerritorios(struct Territorio *territorios, int qtd) {
    const char *nomes[] = {"Brasil", "Argentina", "Chile", "Peru", "México"};
    const char *cores[] = {"Verde", "Azul", "Vermelho", "Amarelo", "Preto"};
    int tropasIniciais[] = {5, 4, 3, 6, 5};

    for (int i = 0; i < qtd; i++) {
        strcpy(territorios[i].nome, nomes[i]);
        strcpy(territorios[i].cor, cores[i]);
        territorios[i].tropas = tropasIniciais[i];
    }
}



// Estado atual de todos os territórios
void exibirMapa(const struct Territorio *territorios, int qtd) {
    printf("\n===  MAPA ATUAL ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s | Cor: %s | Tropas: %d\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
    printf("=========================\n");
}
