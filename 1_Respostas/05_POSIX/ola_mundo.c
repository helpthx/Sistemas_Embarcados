// Codigo para criar um arquivo txt escrito Ola mundo!

#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()

int main(int argc, const char * argv[])
{

int fp;
	
	fp = open("ola_mundo.txt", O_CREAT);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}

	system("echo Ola mundo! >> ola_mundo.txt");
	close(fp);


return 0;
}
