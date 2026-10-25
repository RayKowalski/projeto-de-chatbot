
print("=== Chatbot FAQ ===")
print("Seu assistente para perguntas frequentes.")
print("Olá! Seja bem-vinda. Como posso ajudar?")


menu = {
    1: 'Realizar encomenda',
    2: 'Consultar cardápio',
    3: 'Horário de funcionamento',
    4: 'Encerrar atendimento'
}

cardapio = {
    1: ("Morango com brigadeiro", 12.00),
    2: ("Ninho com Nutella", 15.00),
    3: ("Doce de leite com coco", 12.00),
    4: ("Chocolate com maracujá", 12.00),
    5: ("Pudim", 8.00),
    6: ("Cookie recheado com Nutella", 15.00)
}

while True:

  for numero, descricao in menu.items():
    print(numero, "-", descricao)

  opcao = int(input("Digite o numero da opção desejada: "))

  if opcao == 1:

      print("Você escolheu: Realizar encomenda.")

      carrinho = {}

      while True:
          print("\n=== Cardápio ===")
          for numero, (nome, preco) in cardapio.items():
              print(f"{numero} - {nome}: R$ {preco:.2f}")

          print("Digite 0 para finalizar o pedido.")
          produto = int(input("Escolha o número do produto: "))

          if produto == 0:
              break

          if produto not in cardapio:
              print("Produto inválido. Tente novamente.")
              continue

          quantidade = int(input("Quantas unidades deseja? "))

          if quantidade <= 0:
              print("A quantidade deve ser maior que zero.")
              continue

          carrinho[produto] = carrinho.get(produto, 0) + quantidade

      subtotal = 0

      print("\n=== Resumo do pedido ===")
      for produto, quantidade in carrinho.items():
          nome, preco = cardapio[produto]
          total_item = preco * quantidade
          subtotal += total_item
          print(f"{nome} x {quantidade}: R$ {total_item:.2f}")

      print(f"Subtotal: R$ {subtotal:.2f}")

      
      print("\nComo deseja receber o pedido?")
      print("1 - Entrega (taxa de R$ 5,00)")
      print("2 - Retirada no local")

      retirada = input("Escolha uma opção: ")

      frete = 0

      if retirada == "1":
          frete = 5.00

          print("\nInforme o endereço para entrega:")
          rua = input("Rua: ")
          numero_casa = input("Número: ")
          cep = input("CEP: ")
          complemento = input("Complemento (se houver): ")

      elif retirada == "2":
          print("Você escolheu retirar no local.")

      else:
          print("Opção inválida. Pedido não finalizado.")
          continue

      total = subtotal + frete

      print("\nComo deseja pagar?")
      print("1 - Pix")
      print("2 - Dinheiro")
      print("3 - Cartão na entrega")

      pagamento = input("Escolha a forma de pagamento: ")

      if pagamento == "1":
          print("\nPagamento via Pix.")
          print("Chave Pix: SUA_CHAVE_PIX_AQUI")
          print("Após realizar o pagamento, favor enviar o comprovante. Obrigado!")

      elif pagamento == "2":
          troco = input("Precisa de troco? (s/n): ").strip().lower()

          if troco == "s":
              valor_troco = float(input("Troco para quanto? R$ "))
              if valor_troco < total:
                  print("O valor informado precisa ser maior ou igual ao total.")
                  continue
              print(f"Separaremos o troco para R$ {valor_troco:.2f}.")

      elif pagamento == "3":
          print("O pagamento será feito na entrega.")

      else:
          print("Forma de pagamento inválida. Pedido não finalizado.")
          continue

      print("\n=== Pedido finalizado ===")
      print(f"Subtotal: R$ {subtotal:.2f}")
      print(f"Frete: R$ {frete:.2f}")
      print(f"Total: R$ {total:.2f}")
      print("Obrigado por comprar na Jardim de Açúcar!")

      break



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