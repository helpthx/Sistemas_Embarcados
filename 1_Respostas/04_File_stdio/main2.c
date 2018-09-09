#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	FILE *f;
	char str1[30], str[30], nome[] = "Nome: ", frase[] = "Idade: "; 
	char idade[4], txt[] = ".txt";

	printf("\nDigite seu nome: ");
	fgets(str, 29, stdin);
	for (int i = 0; str[i]; i++)
	{
		if(str[i] == '\n'){
			str[i] = 0;
		}
	}

	printf("Digite sua idade: ");
	fgets(idade, 3, stdin);
	for (int i = 0; idade[i]; i++)
	{
		if(idade[i] == '\n'){
			idade[i] = 0;
		}
	}
	
	
	if (!(f = fopen(str, "w")))
	{
		printf("Erro ao abrir o arquivo !\n");
		exit(1);
	}

	fputs(nome, f);
	fputs(str, f);
	fputs("\n", f);
	fputs(frase, f);
	fputs(idade, f);
	fclose(f);

	return 0;
}



