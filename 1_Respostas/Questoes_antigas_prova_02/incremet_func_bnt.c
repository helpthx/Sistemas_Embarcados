/* Crie dois processos, e faça com que o processo-filho gere uma onda quadrada, enquanto o processo-pai lê um botão no GPIO, 
aumentando a frequência da onda sempre que o botão for pressionado. A frequência da onda quadrada deve começar em 1 Hz, 
e dobrar cada vez que o botão for pressionado.A frequência máxima é de 64 Hz, devendo retornar a 1 Hz se o botão for 
pressionado novamente.*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>

int fd;
int frequencia = 1;


//Sinal para fechar corretamente unexportanto os pinos de forma correta
void close(){
	close(fd);
	fd = open("/sys/class/gpio/unexport",O_WRONLY);
	write(fd,"20",2);
	write(fd,"21",2);
	close(fd);
	printf("Fechando programa\n");
	sleep(1);
	exit(0);
}

//dobrador de freq
void dobra_freq(){
	frequencia = frequencia * 2;
	if(frequencia == 128) frequencia = 1; //Ao chegar na freq maxima retorna para a freq 1hz
}

int main(){
	//Criando os processos para trabalharem de forma paralela.
	pid_t pid_id;
	pid_id = fork();

	signal(SIGINT,close);
	if(pid_id == 0){
		//processo filho
		char btn; //buffer de leitura do botão

		//Setando como export
		printf("Realizando o export 7\n");
		fd = open("/sys/class/gpio/export",O_WRONLY);
		write(fd,"7",2);
		close(fd);

		//Setando como saída
		printf("Iniciando o pin como saída 7\n");
		fd = open("/sys/class/gpio/gpio7/direction",O_WRONLY);
		write(fd,"in",4);
		close(fd);

		fd = open("/sys/class/gpio/gpio7/value",O_RDWR);
		printf("Pronto para capturar gpio7\n");
		while(1){
			lseek(fd,0,SEEK_SET);
			read(fd,&btn,2);
			printf("BTN = %c\n",btn);
			if(btn == '1'){
				kill(pid_id,SIGUSR1);
			}
			usleep(500000);
		}
		
	}

	else{

		//processo pai
		char bf='0'; //buffer de leitura 

		signal(SIGUSR1,dobra_freq);
		// Trabalhando com o botão 4 ser usado para ligar o led
		//Setando como export
		printf("Realizando o export 4\n");
		fd = open("/sys/class/gpio/export",O_WRONLY);
		write(fd,"4",2);
		close(fd);

		//Setando como saída
		printf("Iniciando o pin 4 como saída\n");
		fd = open("/sys/class/gpio/gpio4/direction",O_WRONLY);
		write(fd,"out",4);
		close(fd);


		fd = open("/sys/class/gpio/gpio4/value",O_WRONLY);
		printf("Iniciando o blink em 4\n");
		while(1){
			printf("Frequencia = %d BF = %c\n",frequencia,bf);
			write(fd,"1",2);
			usleep(500000/frequencia);
			write(fd,"0",2);
			usleep(500000/frequencia);
		}

	}

	return 0;
}
