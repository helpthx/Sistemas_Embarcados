/*Generalize o código acima para qualquer frequência possível.*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int fd;
//função para fechar corretamente e unexportar os pinos
void close(){
	close(fd);
	fd = open("/sys/class/gpio/unexport",O_WRONLY);
	write(fd,"4",2);
	printf("Fechando programa\n");
	close(fd);
	sleep(1);
	exit(0);
}




int main(){

	float frequencia;
	float periodo;
	
	signal(SIGINT,fechar);

	printf("Qual a frequência (em Hz)?\n");
	scanf("%f",&frequencia); //Entrada da freq pelo usuario
	periodo = 1000000/(2*(frequencia)); //Conversão de Hz para S


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
	printf("Iniciando o blink com a frequência de %.2f Hz\n",frequencia);
	while(1){
		write(fd,"1",2);
		usleep(periodo);
		write(fd,"0",2);
		usleep(periodo);
	}

	return 0;
}
