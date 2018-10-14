import sys, traceback

def loop_principal():
	print('------------------------------------------------------------------------------------------------------------------')
	print('1 -> Cria Tabela; 2 -> Cadastra um novo usuario; 3 -> Adiona creditos no RU; 4 -> Contador de pessoas; 5 -> Sair: ')
	print('------------------------------------------------------------------------------------------------------------------')
	a = input()
	x = 1

	while(x):
		if int(a) == 1:
			#criar_tabela()
			print('\nCria tabela...\n\n')
			a = 0;

		elif int(a) == 2:
			#recarregar_ru()
			print('\nAdiciona Novo Usuario\n\n')
			a = 0;
			
		elif int(a) == 3:
			#recarregar_ru()
			print('\nAdiciona crédito no RU...\n\n')
			a = 0;

		elif int(a) == 4:
			#contador_acessos()
			print('\nContador de acessos...\n\n')
			a = 0;

		elif int(a) == 5:
			print('\nSaindo...\n\n')
			sys.exit(0)
			
		else:
			print('\nVoltando para o começo\n\n')
			loop_principal()


loop_principal();