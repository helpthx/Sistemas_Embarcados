#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
	printf("\n");
}

int main ()
{
	
	pid_t child_pid;
	pid_t child_pid1;
	pid_t child_pid2;
		
	child_pid = fork();
	if (child_pid == 0)
	{
	
		
		printf("********************************************************************\n");
		printf("* Este texto foi escrito no terminal pelo processo FILHO (ID=%d) *\n", (int) getpid());
		printf("********************************************************************\n");
		printf("\n");
		Incrementa_Variavel_Global((int) getpid());

		child_pid1 = fork();
		if (child_pid1 == 0)
		{
			
			
			printf("********************************************************************\n");
			printf("* Este texto foi escrito no terminal pelo processo FILHO 1 (ID=%d) *\n", (int) getpid());
			printf("********************************************************************\n");
			printf("\n");
			Incrementa_Variavel_Global((int) getpid());

			child_pid2 = fork();
			if (child_pid2 == 0)
			{
			
				printf("********************************************************************\n");
				printf("* Este texto foi escrito no terminal pelo processo FILHO 2 (ID=%d) *\n", (int) getpid());
				printf("********************************************************************\n");
				printf("\n");
				Incrementa_Variavel_Global((int) getpid());

				}
	
		}
	
	}
	else
	{
		sleep(1);
		printf("******************************************************************\n");
		printf("* Este texto foi escrito no terminal pelo processo PAI (ID=%d) *\n", (int) getpid());
		printf("******************************************************************\n");
		printf("\n");

	}
	
	return 0;
}

/* Filho execultam sempre a mesma variavel */
