#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --------------------------------------------------------------
// Estrutura de dados: Território
// --------------------------------------------------------------
struct Territorio {
    char nome[30];
    char cor[15];
    int tropas;
};

// --------------------------------------------------------------
// Função: inicializaTerritorios
// Cria automaticamente alguns territórios iniciais
// --------------------------------------------------------------
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

// --------------------------------------------------------------
// Função: exibirMapa
// Mostra o estado atual de todos os territórios
// --------------------------------------------------------------
void exibirMapa(const struct Territorio *territorios, int qtd) {
    printf("\n===  MAPA ATUAL ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s | Cor: %s | Tropas: %d\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
    printf("=========================\n");
}

// --------------------------------------------------------------
// Função: simularBatalha
// Executa o ataque de um território contra outro
// --------------------------------------------------------------
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
        printf(" %s venceu a rodada! O defensor perdeu 1 tropa.\n", atacante->nome);

        if (defensor->tropas <= 0) {
            printf(" %s conquistou o território %s!\n",
                   atacante->nome, defensor->nome);
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1;
        }
    } else {
        atacante->tropas--;
        printf("🛡️  O defensor %s resistiu! O atacante perdeu 1 tropa.\n", defensor->nome);
    }
}

// --------------------------------------------------------------
// Função: verificarMissao
// Verifica se a missão foi cumprida
// --------------------------------------------------------------
int verificarMissao(const struct Territorio *territorios, int qtd, const char *missao, const char *corJogador) {
    if (strcmp(missao, "Destruir o exército Verde") == 0) {
        for (int i = 0; i < qtd; i++) {
            if (strcmp(territorios[i].cor, "Verde") == 0 && territorios[i].tropas > 0) {
                return 0; // Ainda não venceu
            }
        }
        return 1; // Vitória
    }

    if (strcmp(missao, "Conquistar 3 territórios") == 0) {
        int conquistas = 0;
        for (int i = 0; i < qtd; i++) {
            if (strcmp(territorios[i].cor, corJogador) == 0) {
                conquistas++;
            }
        }
        return (conquistas >= 3);
    }

    return 0; // Missão desconhecida
}

// --------------------------------------------------------------
// Função principal
// --------------------------------------------------------------
int main() {
    srand(time(NULL));
    const int qtd = 5;

    struct Territorio *territorios = (struct Territorio *)calloc(qtd, sizeof(struct Territorio));
    if (territorios == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    inicializaTerritorios(territorios, qtd);

    // Sorteia missão e define cor do jogador
    const char *missoes[] = {"Destruir o exército Verde", "Conquistar 3 territórios"};
    const char *corJogador = "Vermelho";
    const char *missaoAtual = missoes[rand() % 2];

    printf("===========================================\n");
    printf("          NÍVEL MESTRE\n");
    printf("===========================================\n");
    printf("Sua cor: %s\n", corJogador);
    printf("Missão: %s\n", missaoAtual);
    exibirMapa(territorios, qtd);

    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Atacar\n");
        printf("2 - Verificar Missão\n");
        printf("3 - Mostrar Mapa\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                int a, d;
                printf("\nEscolha o número do território atacante (1 a %d): ", qtd);
                scanf("%d", &a);
                printf("Escolha o número do território defensor (1 a %d): ", qtd);
                scanf("%d", &d);
                getchar();

                if (a < 1 || a > qtd || d < 1 || d > qtd || a == d) {
                    printf(" Escolha inválida!\n");
                } else {
                    simularBatalha(&territorios[a - 1], &territorios[d - 1]);
                }
                break;
            }
            case 2:
                if (verificarMissao(territorios, qtd, missaoAtual, corJogador)) {
                    printf("\n PARABÉNS! Você cumpriu sua missão: %s!\n", missaoAtual);
                    opcao = 0; // encerra o jogo
                } else {
                    printf("\n Missão ainda não concluída. Continue lutando!\n");
                }
                break;

            case 3:
                exibirMapa(territorios, qtd);
                break;

            case 0:
                printf("\n Saindo do jogo. Até a próxima batalha!\n");
                break;

            default:
                printf(" Opção inválida!\n");
        }

    } while (opcao != 0);

    free(territorios);
    return 0;
}
