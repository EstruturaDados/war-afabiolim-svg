#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Estrutura de dados: Território
// Representa um território com nome, cor e quantidade de tropas.
struct Territorio {
    char nome[30];
    char cor[15];
    int tropas;
};


// Cadastrar os territórios dinamicamente
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
        getchar(); // limpa o buffer
        printf("\n");
    }
}


// Estado atual do mapa
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
void simularBatalha(struct Territorio *atacante, struct Territorio *defensor) {
    if (atacante->tropas <= 0) {
        printf("⚠️  O território atacante não possui tropas suficientes!\n");
        return;
    }
    if (defensor->tropas <= 0) {
        printf("⚠️  O território defensor já foi conquistado!\n");
        return;
    }

    int dadoAtacante = (rand() % 6) + 1; // gera número entre 1 e 6
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n🎲 Dados lançados!\n");
    printf("%s (Atacante) tirou: %d\n", atacante->nome, dadoAtacante);
    printf("%s (Defensor) tirou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante >= dadoDefensor) {
        // atacante vence
        defensor->tropas--;
        printf("💥 O atacante venceu a rodada! O defensor perdeu 1 tropa.\n");

        if (defensor->tropas <= 0) {
            printf("🏴‍☠️ O território %s foi conquistado por %s!\n",
                   defensor->nome, atacante->nome);
             // ocupa com 1 tropa mínima      
            defensor->tropas = 1; 
            strcpy(defensor->cor, atacante->cor);
        }
    } else {
        // defensor vence
        atacante->tropas--;
        printf("🛡️  O defensor resistiu! O atacante perdeu 1 tropa.\n");
    }
}


// Função principal
int main() {
    int qtd = 5;
    srand(time(NULL)); // inicializa gerador aleatório

    //dinâmica dos territórios
    struct Territorio *territorios = (struct Territorio *)calloc(qtd, sizeof(struct Territorio));
    if (territorios == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("=====================================\n");
    printf("   NÍVEL AVENTUREIRO\n");
    printf("=====================================\n\n");

    cadastrarTerritorios(territorios, qtd);
    exibirMapa(territorios, qtd);

    int opcao;
    do {
        printf("\n=== Menu de Ações ===\n");
        printf("1 - Atacar\n");
        printf("2 - Mostrar mapa\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        if (opcao == 1) {
            int at, def;
            printf("\nEscolha o número do território atacante (1 a %d): ", qtd);
            scanf("%d", &at);
            printf("Escolha o número do território defensor (1 a %d): ", qtd);
            scanf("%d", &def);
            getchar();

            if (at < 1 || at > qtd || def < 1 || def > qtd || at == def) {
                printf("⚠️  Escolha inválida!\n");
            } else {
                simularBatalha(&territorios[at - 1], &territorios[def - 1]);
            }
        } else if (opcao == 2) {
            exibirMapa(territorios, qtd);
        }

    } while (opcao != 0);

    printf("\n👋 Encerrando o jogo. Até a próxima batalha!\n");

    // Libera a memória alocada
    free(territorios);
    return 0;
}
