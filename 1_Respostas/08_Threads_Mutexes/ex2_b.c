//gcc ex2_b.c -o ex2 -lpthread 

#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

long int v[50000], valor_max[5];
void *seek_vector_0(void *param); //0 - 12499
void *seek_vector_1(void *param); //12500 - 24999
void *seek_vector_2(void *param); //25000 - 37499
void *seek_vector_3(void *param); //37500 - 50000

int main(int argc, char const *argv[])
{
int i,k,j, rand_numb;
srand(time(NULL)); // Inicializa gerador de valores aleatorios
for (int i = 0; i < 50000; ++i) // Preenchendo o vetor
{
	rand_numb = rand();
	v[i] = rand_numb;
	//printf("%ld\n", v[i]);
}

pthread_t tid[4]; //4 threads tid0, 1, 2 e 3
pthread_create(&tid[0],NULL, seek_vector_0, NULL);
pthread_create(&tid[1],NULL, seek_vector_1, NULL);
pthread_create(&tid[2],NULL, seek_vector_2, NULL);
pthread_create(&tid[3],NULL, seek_vector_3, NULL);

for (k = 0; k < 4; k++) // esperando as threads terminanem
{
	pthread_join(tid[k], NULL);
	printf("Thread: %d terminou.\n", k);
	if(valor_max[k]> valor_max[5]){
        valor_max[5]= valor_max[k];
       }

}

printf("Maior numero do vetor é: %ld\n", valor_max[5]);
return 0;
}

void *seek_vector_0(void *param){ //0 - 12499
for (int i = 0; i < 12500; i++) // Preenchendo o vetor
{
	if(v[i]> valor_max[0]){
        valor_max[0]= v[i];
        
      }
}
printf("Maior_0 é: %ld\n", valor_max[0]);
pthread_exit(0);
}

void *seek_vector_1(void *param){
for (int i = 12500; i < 25000; i++)
{
	if(v[i]> valor_max[1]){
        valor_max[1]= v[i];
        
      }
}
printf("Maior_1 é: %ld\n", valor_max[1]);
pthread_exit(0);
}

void *seek_vector_2(void *param){
for (int i = 25000; i < 37500; i++)
{
	if(v[i]> valor_max[2]){
        valor_max[2]= v[i];
       }
}
printf("Maior_2 é: %ld\n", valor_max[2]);
pthread_exit(0);
}

void *seek_vector_3(void *param){
for (int i = 37500; i < 50000; i++)
{
	if(v[i]> valor_max[3]){
        valor_max[3]= v[i];
       }
}
printf("Maior_3 é: %ld\n", valor_max[3]);
pthread_exit(0);}
