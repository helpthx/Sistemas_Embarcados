// Questão 2

#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()
#include <string.h>
int main(int argc, const char * argv[])
{

int fp;

char nome[30], idade[4], NomeS[] = "Nome: ", Idade1[] = "Idade: ";
char nome1[30]; 
int i;
printf("Digite seu nome: ");
scanf("%s", nome);
printf("Digite sua idade: ");
scanf("%s", idade);
for (int i = 0; i < 30; ++i)
 {
 	nome1[i] = nome[i];
 	 } 
strcat(nome1, ".txt");
	
	fp = open(nome1,  O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
for (int i = 0; NomeS[i]; ++i)
{
	write(fp, &(NomeS[i]), 1);
}

for(i=0; nome[i]; i++){
		write(fp, &(nome[i]), 1); // Grava a string, caractere a caractere	
		
}
write(fp, "\n", 1);
for(i=0; Idade1[i]; i++){
		write(fp, &(Idade1[i]), 1); // Grava a string, caractere a caractere	
		
}

for(i=0; idade[i]; i++){
		write(fp, &(idade[i]), 1); // Grava a string, caractere a caractere	
		
}
write(fp, "\n", 1);
close(fp);

return 0;
}
