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


// Ataque de um território contra out
void simularBatalha(struct Territorio *atacante, struct Territorio *defensor) {
    if (atacante->tropas <= 0) {
        printf(" O atacante não possui tropas suficientes!\n");
        return;
    }

    if (defensor->tropas <= 0) {
        printf(" O território %s já foi conquistado!\n", defensor->nome);
        return;
    }

    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n Dados lançados!\n");
    printf("Atacante (%s) tirou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor (%s) tirou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante >= dadoDefensor) {
        defensor->tropas--;
        printf("%s venceu a rodada! O defensor perdeu 1 tropa.\n", atacante->nome);

        if (defensor->tropas <= 0) {
            printf("%s conquistou o território %s!\n",
                   atacante->nome, defensor->nome);
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1;
        }
    } else {
        atacante->tropas--;
        printf(" O defensor %s resistiu! O atacante perdeu 1 tropa.\n", defensor->nome);
    }
}