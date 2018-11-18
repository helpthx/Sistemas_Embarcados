/*Escreva um código em C para gerar uma onda quadrada de 1 Hz em um pino GPIO do Raspberry Pi*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int fd;

void fechar(){
	close(fd);
	fd = open("/sys/class/gpio/unexport",O_WRONLY); //unexportanto o GPIO para n ter problemas.
	write(fd,"16",2);
	printf("Fechando programa\n");
	close(fd);
	sleep(1);
	exit(0);
}


int main(){
	//Sinal para fechar corretamente o programa.
	signal(SIGINT,fechar);

	//Setando como export
	printf("Realizando o export\n");
	fd = open("/sys/class/gpio/export",O_WRONLY);
	write(fd,"4",2);
	close(fd);
	sleep(1);

	//Setando como saída
	printf("Iniciando o pin como saída\n");
	fd = open("/sys/class/gpio/gpio4/direction",O_WRONLY);
	write(fd,"out",4);
	close(fd);
	sleep(1);



	fd = open("/sys/class/gpio/gpio4/value",O_WRONLY);
	printf("Iniciando o blink\n");
	/*Função que ira ficar sobescrevendo o gpio 4 acada 1/1s = 1hz */
	while(1){
		write(fd,"1",2);
		usleep(500000); // 0.5s 
		write(fd,"0",2);
		usleep(500000); // 0.5s
	}

	return 0;
}

