
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	
	int i;
	
	for (i = 1; argv[i]; ++i){
	char * lista_de_argumentos[] = {"argv[i]", NULL};	
	pid_t pid_filho[i]; 
	pid_filho[i] = fork();
		if (pid_filho[i] == 0)
		{
		printf("*********************************************\n");
		printf("* Este é o processo FILHO, executando '%s'. *\n", argv[i]);
		printf("*********************************************\n");
		printf("\n");
		execvp(argv[i], lista_de_argumentos);
		printf("*******************************************\n");
		printf("* Este printf() so eh executado se houver *\n");
		printf("* um erro de execucao em execvp().        *\n");
		printf("*******************************************\n");
		printf("\n");
		}
	
		else
		{	sleep(1);
			printf("\n");
			}
	}
	
	return 0;
}