#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *p;
	char Ola[] = "Ola mundo !";

	if((p = fopen("Exemplo.txt", "w")) == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	}

	for (int i = 0; Ola[i]; i++)
	{
		if (fwrite(&Ola[i], sizeof(char), 1 , p) != 1) 
		{
		printf("Erro ao escrever no arquivo\n");
		exit(1);
		}
	}
	
	fclose(p);
	return 0;
}
