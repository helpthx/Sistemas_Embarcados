//gcc ex3.c -o ex3 -lpthread 

#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

long int v[50000], media[4];
void *media_vector_0(void *param); //0 - 12499
void *media_vector_1(void *param); //12500 - 24999
void *media_vector_2(void *param); //25000 - 37499
void *media_vector_3(void *param); //37500 - 50000

int main(int argc, char const *argv[])
{
int i,k,j, rand_numb;
float media_final;
srand(time(NULL)); // Inicializa gerador de valores aleatorios
for (int i = 0; i < 50000; ++i) // Preenchendo o vetor
{
	rand_numb = rand();
	v[i] = rand_numb;
	//printf("%ld\n", v[i]);
}

pthread_t tid[4]; //4 threads tid0, 1, 2 e 3
pthread_create(&tid[0],NULL, media_vector_0, NULL);
pthread_create(&tid[1],NULL, media_vector_1, NULL);
pthread_create(&tid[2],NULL, media_vector_2, NULL);
pthread_create(&tid[3],NULL, media_vector_3, NULL);

for (k = 0; k < 4; k++) // esperando as threads terminanem
{
	pthread_join(tid[k], NULL);
	printf("Thread: %d terminou.\n", k);
}

media_final = (media[0] + media[1] + media[2] + media[3])/4;
printf("Média do vetor é: %f\n", media_final);
return 0;
}

void *media_vector_0(void *param){ //0 - 12499
long int media_0;
for (int i = 0; i < 12500; i++) // Preenchendo o vetor
{
	media_0 = v[i] + v[i];
}
media[0] = media_0 / 12500;
printf("Média_0 é: %ld\n", media[0]);
pthread_exit(0);
}

void *media_vector_1(void *param){
long int media_1;
for (int i = 12500; i < 25000; i++)
{
	media_1 = v[i] + v[i];
}
media[1] = media_1 / 12500;
printf("Média_1 é: %ld\n", media[1]);
pthread_exit(0);
}

void *media_vector_2(void *param){
long int media_2;
for (int i = 25000; i < 37500; i++)
{
	media_2 = v[i] + v[i];
}
media[2] = media_2 / 12500;
printf("Média_2 é: %ld\n", media[2]);
pthread_exit(0);
}

void *media_vector_3(void *param){
long int media_3;
for (int i = 37500; i < 50000; i++)
{
	media_3 = v[i] + v[i];
}
media[3] = media_3 / 12500;
printf("Média_3 é: %ld\n", media[3]);
pthread_exit(0);}
