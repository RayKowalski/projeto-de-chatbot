
#include <stdio.h>
#include <string.h>

int main() {
    int opcao;
    int produto;
    int quantidade;
    int carrinho[6] = {0};
    int i;

    int retirada;
    int pagamento;
    char troco;

    char rua[100];
    char numero_casa[20];
    char cep[20];
    char complemento[100];

    double precos[6] = {
        12.00, 15.00, 12.00, 12.00, 8.00, 15.00
    };

    char *nomes[6] = {
        "Morango com brigadeiro",
        "Ninho com Nutella",
        "Doce de leite com coco",
        "Chocolate com maracuja",
        "Pudim",
        "Cookie recheado com Nutella"
    };

    double subtotal;
    double total_item;
    double frete;
    double total;
    double valor_troco;

    printf("=== Chatbot FAQ ===\n");
    printf("Seu assistente para perguntas frequentes.\n");
    printf("Ola! Seja bem-vinda. Como posso ajudar?\n\n");

    while (1) {
        printf("\n1 - Realizar encomenda\n");
        printf("2 - Consultar cardapio\n");
        printf("3 - Horario de funcionamento\n");
        printf("4 - Encerrar atendimento\n");

        printf("Digite o numero da opcao desejada: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");

            while (getchar() != '\n');
            continue;
        }

        if (opcao == 1) {
            printf("\nVoce escolheu: Realizar encomenda.\n");

            for (i = 0; i < 6; i++) {
                carrinho[i] = 0;
            }

            while (1) {
                printf("\n=== Cardapio ===\n");

                for (i = 0; i < 6; i++) {
                    printf("%d - %s: R$ %.2f\n",
                           i + 1, nomes[i], precos[i]);
                }

                printf("Digite 0 para finalizar o pedido.\n");
                printf("Escolha o numero do produto: ");

                if (scanf("%d", &produto) != 1) {
                    printf("Entrada invalida. Digite um numero.\n");

                    while (getchar() != '\n');
                    continue;
                }

                if (produto == 0) {
                    break;
                }

                if (produto < 1 || produto > 6) {
                    printf("Produto invalido. Tente novamente.\n");
                    continue;
                }

                printf("Quantas unidades deseja? ");

                if (scanf("%d", &quantidade) != 1) {
                    printf("Entrada invalida. Digite um numero.\n");

                    while (getchar() != '\n');
                    continue;
                }

                if (quantidade <= 0) {
                    printf("A quantidade deve ser maior que zero.\n");
                    continue;
                }

                carrinho[produto - 1] += quantidade;

                printf("Produto adicionado ao carrinho!\n");
            }

            subtotal = 0;

            printf("\n=== Resumo do pedido ===\n");

            for (i = 0; i < 6; i++) {
                if (carrinho[i] > 0) {
                    total_item = precos[i] * carrinho[i];
                    subtotal += total_item;

                    printf("%s x %d: R$ %.2f\n",
                           nomes[i], carrinho[i], total_item);
                }
            }

            if (subtotal == 0) {
                printf("Nenhum produto foi selecionado.\n");
                continue;
            }

            printf("Subtotal: R$ %.2f\n", subtotal);

            printf("\nComo deseja receber o pedido?\n");
            printf("1 - Entrega (taxa de R$ 5,00)\n");
            printf("2 - Retirada no local\n");
            printf("Escolha uma opcao: ");

            if (scanf("%d", &retirada) != 1) {
                printf("Entrada invalida.\n");

                while (getchar() != '\n');
                continue;
            }

            frete = 0;

            if (retirada == 1) {
                frete = 5.00;

                printf("\nInforme o endereco para entrega:\n");

                printf("Rua: ");
                scanf(" %99[^\n]", rua);

                printf("Numero: ");
                scanf(" %19[^\n]", numero_casa);

                printf("CEP: ");
                scanf(" %19[^\n]", cep);

                printf("Complemento (ou digite nenhum): ");
                scanf(" %99[^\n]", complemento);

            } else if (retirada == 2) {
                printf("Voce escolheu retirar no local.\n");

            } else {
                printf("Opcao invalida. Pedido nao finalizado.\n");
                continue;
            }

            total = subtotal + frete;

            printf("\nComo deseja pagar?\n");
            printf("1 - Pix\n");
            printf("2 - Dinheiro\n");
            printf("3 - Cartao na entrega\n");
            printf("Escolha a forma de pagamento: ");

            if (scanf("%d", &pagamento) != 1) {
                printf("Entrada invalida.\n");

                while (getchar() != '\n');
                continue;
            }

            if (pagamento == 1) {
                printf("\nPagamento via Pix.\n");
                printf("Chave Pix: SUA_CHAVE_PIX_AQUI\n");
                printf("Apos realizar o pagamento, favor enviar ");
                printf("o comprovante. Obrigado!\n");

            } else if (pagamento == 2) {
                printf("Precisa de troco? (s/n): ");
                scanf(" %c", &troco);

                if (troco == 's' || troco == 'S') {
                    printf("Troco para quanto? R$ ");
                    
                    if (scanf("%lf", &valor_troco) != 1) {
                        printf("Valor invalido.\n");

                        while (getchar() != '\n');
                        continue;
                    }

                    if (valor_troco < total) {
                        printf("O valor deve ser maior ou igual ");
                        printf("ao total do pedido.\n");
                        continue;
                    }

                    printf("Separaremos o troco para R$ %.2f.\n",
                           valor_troco);
                }

            } else if (pagamento == 3) {
                printf("O pagamento sera feito na entrega.\n");

            } else {
                printf("Forma de pagamento invalida. ");
                printf("Pedido nao finalizado.\n");
                continue;
            }

            printf("\n=== Pedido finalizado ===\n");
            printf("Subtotal: R$ %.2f\n", subtotal);
            printf("Frete: R$ %.2f\n", frete);
            printf("Total: R$ %.2f\n", total);

            if (retirada == 1) {
                printf("Endereco: %s, %s, CEP %s\n",
                       rua, numero_casa, cep);
                printf("Complemento: %s\n", complemento);
            }

            printf("Obrigado por comprar na Jardim de Acucar!\n");

            break;

        } else if (opcao == 2) {
            printf("\nVoce escolheu: Consultar cardapio.\n");
            printf("Aqui esta o nosso cardapio:\n");

            printf("\nBolos de pote:\n");
            for (i = 0; i < 4; i++) {
                printf("%d. %s - R$ %.2f\n",
                       i + 1, nomes[i], precos[i]);
            }

            printf("\nDoces em fatias:\n");
            for (i = 4; i < 6; i++) {
                printf("%d. %s - R$ %.2f\n",
                       i - 3, nomes[i], precos[i]);
            }

        } else if (opcao == 3) {
            printf("\nVoce escolheu: Horario de funcionamento.\n");
            printf("Nosso horario de funcionamento e:\n");
            printf("De terca-feira a sabado: das 10h as 18h.\n");
            printf("Domingo: das 8h as 16h.\n");
            printf("Segunda-feira: fechado.\n");

        } else if (opcao == 4) {
            printf("\nVoce escolheu: Encerrar atendimento.\n");
            printf("Obrigado por utilizar nosso servico.\n");
            printf("Tenha um otimo dia! <3\n");
            break;

        } else {
            printf("Opcao invalida. Por favor, tente novamente.\n");
        }
    }

    printf("\nSistema encerrado.\n");

    return 0;
}
