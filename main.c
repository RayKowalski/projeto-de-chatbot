
#include <stdio.h>

int main() {
    int opcao;

    printf("=== Chatbot FAQ ===\n");
    printf("Seu assistente para perguntas frequentes.\n");
    printf("Olá! Seja bem-vinda. Como posso ajudar?\n\n");

    while (1) {
        printf("1 - Realizar encomenda\n");
        printf("2 - Consultar cardápio\n");
        printf("3 - Horário de funcionamento\n");
        printf("4 - Encerrar atendimento\n");

        printf("Digite o numero da opção desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Você escolheu: Realizar encomenda.\n");
            printf("Por favor, informe os itens desejados e a quantidade.\n");
            printf("Informe o método de retirada (entrega ou retirada no local).\n");
            printf("Digite 'finalizar' para concluir o pedido.\n");
        }
        else if (opcao == 2) {
            printf("Você escolheu: Consultar cardápio.\n");
            printf("Aqui está o nosso cardápio:\n");
            printf("Bolos de pote:\n");
            printf("1. Morango com brigadeiro - R$ 12,00\n");
            printf("2. Ninho com Nutella - R$ 15,00\n");
            printf("3. Doce de leite com coco - R$ 12,00\n");
            printf("4. Chocolate com maracujá - R$ 12,00\n");
            printf("Doces em fatias:\n");
            printf("1. Pudim - R$ 8,00\n");
            printf("2. Cookie recheado com Nutella - R$ 15,00\n");
        }
        else if (opcao == 3) {
            printf("Você escolheu: Horário de funcionamento.\n");
            printf("Nosso horário de funcionamento é:\n");
            printf("De terça-feira a sábado: das 10h às 18h.\n");
            printf("Domingo: das 8h às 16h.\n");
            printf("Segunda-feira: fechado.\n");
        }
        else if (opcao == 4) {
            printf("Você escolheu: Encerrar atendimento.\n");
            printf("Obrigado por utilizar nosso serviço.\n");
            printf("Tenha um ótimo dia! <3\n");
            break;
        }
        else {
            printf("Opção inválida. Por favor, tente novamente.\n");
        }

        printf("\n");
    }

    return 0;
}
