import sqlite3
import sys


def criar_tabela():
	conn = sqlite3.connect('Banco_de_dados.db')
	print('Banco aberto com sucesso...');

	conn.execute('''CREATE TABLE CADASTROS
         (ID INTEGER PRIMARY KEY AUTOINCREMENT,
         NOME           TEXT    NOT NULL,
         MATRICULA            INT     NOT NULL,
         RU        	REAL NOT NULL,
         ACESSOS         INT NOT NULL);''')

	print('Tabela criada com sucesso...');
	print('\n')
	conn.close()
	sys.exit(1)

def recarregar_ru():
	conn = sqlite3.connect('Banco_de_dados.db')
	print('Banco aberto com sucesso...');
	
	matricula = input('Qual a matricula ?:  ')
	dinheiro = input('Quanto de dinheiro colocar ?:')
	float(dinheiro)
	conn.execute("UPDATE CADASTROS set RU = RU +" +dinheiro+ " WHERE  MATRICULA = "+ matricula);
	conn.commit()
	print('Numero total de colunas atualizadas: ', conn.total_changes)
	print('Alterado com sucesso...');
	print('\n')
	conn.close()
	sys.exit(1)

def contador_acessos():
	conn = sqlite3.connect('Banco_de_dados.db')
	print('Banco aberto com sucesso...');

	MATRICULA1 = input('Digite a matricula: ')
	#int(MATRICULA1)
	conn.execute('UPDATE CADASTROS set ACESSOS = ACESSOS+1 WHERE  MATRICULA='+MATRICULA1);
	conn.commit()
	print('Numero total de colunas atualizadas: ', conn.total_changes)
	print('Alterado com sucesso...');
	print('\n')
	conn.close()
	sys.exit(1)

def loop_principal():
	a = input("1 - Criar Tabela, 2 - Cadastrar novo usuario, 3 - Recarregar Ru, 4 - contador de acessos e 5 para sair...")
	x = 1


	while(x):

		if int(a) == 1:
			criar_tabela()
			a = 0
	
		elif int(a) == 3:
			recarregar_ru()
			a = 0
		elif int(a) == 4:
			contador_acessos()
			a = 0

		elif int(a) == 5:
			print('Saindo...')
			x = 0

		else:
			loop_principal()


loop_principal()
#criar_tabela()
#cadastrar_usuario()
#recarregar_ru()
#contador_acessos()