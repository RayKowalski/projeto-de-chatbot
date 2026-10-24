
print("=== Chatbot FAQ ===")
print("Seu assistente para perguntas frequentes.")
print("Olá! Seja bem-vinda. Como posso ajudar?")


menu = {
    1: 'Realizar encomenda',
    2: 'Consultar cardápio',
    3: 'Horário de funcionamento',
    4: 'Encerrar atendimento'
}

while True:

  for numero, descricao in menu.items():
    print(numero, "-", descricao)

  opcao = int(input("Digite o numero da opção desejada: "))

  if opcao == 1:
      print("Você escolheu: Realizar encomenda.")
      print("Por favor, informe os itens desejados e a quantidade.")
      print("informe o método de retirada (entrega ou retirada no local).")
      print("Digite 'finalizar' para concluir o pedido.")

  elif opcao == 2:
      print("Você escolheu: Consultar cardápio.")
      print("Aqui está o nosso cardápio:")
      print("Bolos de pote:\n"
    "1. Morango com brigadeiro - R$ 12,00\n"
    "2. Ninho com Nutella - R$ 15,00\n"
    "3. Doce de leite com coco - R$ 12,00\n"
    "4. Chocolate com maracujá - R$ 12,00\n"
        "Doces em fatias:\n"
        "1. Pudim - R$ 8,00\n"
        "2. Cookie recheado com Nutella - R$ 15,00")

  elif opcao == 3:
      print("Você escolheu: Horário de funcionamento.")
      print("Nosso horário de funcionamento é: \n"
    "De terça-feira a sábado: das 10h às 18h.\n"
    "Domingo: das 8h às 16h.\n"
    "Segunda-feira: fechado.")

  elif opcao == 4:
      print("Você escolheu: Encerrar atendimento.")
      print("Obrigado por utilizar nosso serviço.\n"
        "Tenha um ótimo dia! <3")
      break

  else:
      print("Opção inválida. Por favor, tente novamente.") 