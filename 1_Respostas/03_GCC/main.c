

/*
Questão 1 	
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Hello World !\n");
	return 0;
}*/

/*Questão 2 e 3 (a,b,c,d,e e f) 
#include <stdio.h>

int main()
{
    char nome[40];
    printf("Digite seu nome: ");
    scanf("%s",nome);
    printf("Olá %s\n",nome);
    return 0;
}*/

/*Questão 4 e 5 (a,b,c,d,e e f) 
#include <stdio.h>

int main(int argc, char** argv)
{
    char nome[40];
    if(argc>=2)
    {
        printf("Olá %s\n",argv[1]);
        printf("Numero de entradas", argc);
    	}
    return 0;
}*/

/*Questão 7
#include <stdio.h>

int main(int argc, char** argv)
{
    char nome[40];
    if(argc>=2)
    {
       // printf("Olá %s\n",argv[1]);
     	for (int i = 0; i < argc - 1; ++i)
     	{
     		printf("%s ", argv[i + 1]);
     	}
     	printf("\n");
    }
    return 0;
}*/

#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char** argv)
{
    int i;

    if(argc>=2)
    {
        for(i = 0; i < argc; i++)
            printf("Argumento: %s / Numero de caracteres: %d\n",argv[i],Num_Caracs(argv[i]));
    }
    printf("\n");
    return 0;
}