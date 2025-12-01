#include <stdio.h>
#include <string.h> // Para manipulacao de strings (como o strlen)

// Define o numero total de territorios que o mapa tera
#define NUM_TERRITORIOS 5 
#define TAM_NOME 50

// Declaracao da estrutura para representar cada territorio no jogo
struct Territorio {
    char nome[TAM_NOME]; // Nome do local (pode ter espacos)
    char cor[TAM_NOME];  // Cor do exercito que o domina
    int tropas;          // Quantidade de tropas presentes
};

int main() {
    // Cria um vetor 'mapa' para armazenar NUM_TERRITORIOS structs
    struct Territorio mapa[NUM_TERRITORIOS];
    int i; // Variavel de controle para os loops

    printf("=========================================\n");
    printf("      SISTEMA DE CADASTRO DE JOGO\n");
    printf("=========================================\n\n");

    // --- 1. ETAPA DE CADASTRO DE DADOS ---
    // Loop para ler e preencher os dados de cada territorio (do indice 0 ao 4)
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("--- TERRITORIO %d ---\n", i + 1);

        // Uso fgets para permitir que o nome do territorio tenha espacos
        printf("Nome do Territorio: ");
        fgets(mapa[i].nome, TAM_NOME, stdin);
        
        // Remove o '\n' (Enter) que o fgets adiciona ao final da string
        if (mapa[i].nome[strlen(mapa[i].nome) - 1] == '\n') {
            mapa[i].nome[strlen(mapa[i].nome) - 1] = '\0';
        }

        // Leitura da cor e das tropas usando o scanf tradicional
        printf("Cor do Exercito (ex: Vermelho): ");
        scanf("%s", mapa[i].cor);

        printf("Numero de Tropas: ");
        scanf("%d", &mapa[i].tropas);
        
        // Limpa o buffer de entrada (stdin) depois de ler o inteiro.
        // Isso evita que o 'Enter' digitado interfira no proximo fgets.
        while(getchar() != '\n');
        
        printf("\n");
    }

    // --- 2. ETAPA DE EXIBICAO DE DADOS ---
    printf("\n=========================================\n");
    printf("      MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("=========================================\n");

    // Loop para exibir todos os dados que foram armazenados
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf(">> DETALHES DO TERRITORIO %d:\n", i + 1);
        printf("   - Nome: %s\n", mapa[i].nome);
        printf("   - Dominado por: Exercito %s\n", mapa[i].cor);
        printf("   - Tropas: %d unidades\n", mapa[i].tropas);
        printf("-----------------------------------------\n");
    }

    return 0; // Indica que o programa terminou com sucesso
}