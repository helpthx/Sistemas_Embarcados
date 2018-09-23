#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int x = 1;
	while(x){
	int inteiro = 0;
	printf("Bem vindo ao reconhecimento facial !\n");
	printf("Digite 1 - Novo Cadastro, 2 - Reconhecimento ou 3 - Sair: ");
	scanf("%d", &inteiro);

	/* processos principal */

	if (inteiro == 1)
	{
		system("python3 01_face_dataset.py");
		system("python3 02_face_training.py");
	}
	else if (inteiro == 2)
	{
		system("python3 reconhecimento_facial_teste.py");
	}

	else if(inteiro == 3){
		printf("Finalizando programa...\n");
		x = 0;
	}


}
	
	return 0;
}