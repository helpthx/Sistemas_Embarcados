#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *f;
	char nome[] = "Nome: ", idade[] = "Idade: "; 
	
	if(argc>=2)
    {
    	if (!(f = fopen(argv[1], "w")))
		{
		printf("Erro ao abrir o arquivo !\n");
		exit(1);
		}

		fputs(nome, f);
		fputs(argv[1], f);
		fputs("\n", f);
		fputs(idade, f);
		fputs(argv[2], f);
		fclose(f);
       	}
    return 0;
}
