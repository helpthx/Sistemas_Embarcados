/*Controle 6 LEDs de uma árvore de natal utilizando charlieplexing. Pisque os LEDs numa frequência de 100 Hz. 
Acenda os LEDs de forma que um ser humano veja dois LEDs acesos juntos por um tempo, depois outros dois LEDs,
e depois os últimos 2 LEDs juntos. Permaneça em cada estado durante 0,5 segundos.*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>

//pinos utilizados: 16,20 e 21

void open_gpio(){

	int fd;
	int status;

	fd = open("/sys/class/gpio/export",O_WRONLY);

	status = write(fd,"16",2);
	status = write(fd,"20",2);
	status = write(fd,"21",2);
	if(status == -1){
	printf("Erro de abertura dos arquivos. Execulte como SUDO")
	}
	close(fd);

}

void close_gpio(){

	int fd;
	int status;
	fd = open("/sys/class/gpio/unexport",O_WRONLY);
	status = write(fd,"16",2);
	status = write(fd,"20",2);
	status = write(fd,"21",2);
	if(status == -1){
	printf("Erro ao fechar os arquivos. Execulte como SUDO")
	}


	close(fd);
	exit(0);
}

void set_direction(int pin, int mode){

	int fd;
	int status;
	char archive[50];

	sprintf(archive,"/sys/class/gpio/gpio%d/direction",pin);
//	printf("Setando direction = %s\n",archive);

	fd = open(archive,O_WRONLY);

	// 0 para out
	if(mode == 0){
		status = write(fd,"out",3);
//		printf("Set Direction %d\n",status);
	}
	// 1 para in
	else{
		status = write(fd,"in",2);
//		printf("Set Direction %d\n",status);
	}

	close(fd);
}
//Função para alternar os valores dos GPIOS
void set_value(int pin, int value){

	int fd;
	char archive[50];
	int status;

	sprintf(archive,"/sys/class/gpio/gpio%d/value",pin);

	fd = open(archive,O_WRONLY);

	// 0 para baixo
	if(value == 0){
		status = write(fd,"0",1);

	}
	// 1 para alto
	else{
		status = write(fd,"1",1);

	}

	close(fd);

}

void meuamigocharlie(int led){

	switch (led){
		case 1:
			set_direction(16,0);
			set_direction(20,0);
			set_direction(21,1);

			set_value(16,1);
			set_value(20,0);

			break;

		case 2:
			set_direction(16,0);
			set_direction(20,0);
			set_direction(21,1);

			set_value(16,0);
			set_value(20,1);

			break;

		case 3:
			set_direction(16,0);
			set_direction(20,1);
			set_direction(21,0);

			set_value(16,1);
			set_value(21,0);

			break;

		case 4:
			set_direction(16,0);
			set_direction(20,1);
			set_direction(21,0);

			set_value(16,0);
			set_value(21,1);

			break;

		case 5:
			set_direction(16,1);
			set_direction(20,0);
			set_direction(21,0);

			set_value(20,1);
			set_value(21,0);

			break;

		case 6:

			set_direction(16,1);
			set_direction(20,0);
			set_direction(21,0);

			set_value(20,0);
			set_value(21,1);

			break;
		}
}

int main(){

	//setando gpio
	int n; //contador de freq

	signal(SIGINT,close_gpio);

	open_gpio();

	while(1){

		n=0;
		while(n!=100){
			meuamigocharlie(1);
			usleep(10000/2);
			meuamigocharlie(2);
			if(usleep(10000/2)==0) n++;
		}

		n=0;
		while(n!=100){

			meuamigocharlie(3);
			usleep(10000/2);
			meuamigocharlie(4);
			if(usleep(10000/2)==0) n++;
		}

		n=0;
		while(n!=100){

			meuamigocharlie(5);
			usleep(10000/2);
			meuamigocharlie(6);
			if(usleep(10000/2)==0) n++;
		}
	}

	close_gpio();

	return 0;
}

