import sqlite3
import sys

def cadastrar_usuario(): 
	conn = sqlite3.connect('Banco_de_dados.db')
	print ('Banco aberto com sucesso...');

	#id_1 = input('Digite o ID: ')
	nome = input('Digite o nome: ')
	matricula = input('Digite a matricula: ')
	ru = 00.00
	acessos = 0

	conn.execute("INSERT INTO CADASTROS (NOME,MATRICULA,RU,ACESSOS) \
    	  VALUES (?, ?, ?, ?)", (nome,matricula,ru,acessos));

	conn.commit()
	print('Dados salvos com sucesso...');
	print('\n')
	conn.close()
	sys.exit(1)

cadastrar_usuario()