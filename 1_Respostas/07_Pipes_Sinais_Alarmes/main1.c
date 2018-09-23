#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main ()
{
	int a = 1, b = 2, c = 3, fd[2], valor[2] = {1,0}, i;
	char mensagem[30];
	pid_t child_pid;

	if (pipe(fd) < 0)
 	{ 
 	printf("erro na criacao do pipe\n");
	}
	child_pid = fork();
	if (child_pid == 0) /* processo filho */
	{
		a=7;
		b=8;
		c=9;

		for (int i = 1; i <= 10; ++i)
		{

		if (read(fd[0], valor, sizeof(valor)) < 0){
			printf("erro na leitura\n");
			}
		else{
 			printf("valor lido pelo filho = %d\n", valor[0]); 
		}
		
		}
	
 		
			
	}
	
	
	else /* Processo pai */
	{
		
		printf("******************************************************************\n");
		printf("* Este texto foi escrito no terminal pelo processo PAI (ID=%d) *\n", (int) getpid());
		printf("* Seu filho tem o ID %d.                                       *\n", child_pid);
		printf("******************************************************************\n");
		printf("\n");

	 
		for (i = 0; i <= 10; ++i)
		{
			    
			    if (write(fd[1], valor, sizeof(valor)) < 0){
		 		printf("erro na escrita\n");
 				exit(-1);
				}
				valor[0]++;
				alarm(1);
		}

 		

	}
	
	return 0;
}
