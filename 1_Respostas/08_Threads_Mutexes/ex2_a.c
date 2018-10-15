//gcc ex2_a.c -o ex2 -lpthread 

#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

long int v[50000], valor_max[4];
void *seek_vector_0(void *param); //0 - 12499
void *seek_vector_1(void *param); //12500 - 24999
void *seek_vector_2(void *param); //25000 - 37499
void *seek_vector_3(void *param); //37500 - 50000

int main(int argc, char const *argv[])
{
int i,k,j rand_numb;
srand(time(NULL)); // Inicializa gerador de valores aleatorios
for (int i = 0; i < 50000; ++i) // Preenchendo o vetor
{
	rand_numb = rand();
	v[i] = rand_numb;
	printf("%ld\n", v[i]);
}

/*if(v[i]>maior){
        maior= v[i];
        posicao = i;
      }
printf("Maior é: %ld\n", maior);
printf("Na posição: %d\n", posicao);
*/

pthread_t tid[4]; //4 threads tid0, 1, 2 e 3
pthread_create(&tid[0],NULL, seek_vector_0, NULL);
pthread_create(&tid[1],NULL, seek_vector_1, NULL);
pthread_create(&tid[2],NULL, seek_vector_2, NULL);
pthread_create(&tid[3],NULL, seek_vector_3, NULL);
/*for (j = 0; j < 4; ++j) //Criando 4 threads
{
	pthread_create(&tid[j],NULL, seek_vector, NULL);
	printf("Thread: %d criada.\n", j);
}
*/
//pthread_create(&tid,NULL, seek_vector, NULL);
for (k = 0; i < count; ++i) // esperando as threads terminanem
{
	pthread_join(tid[k], NULL);
	printf("Thread: %d terminou.\n", k);

}
//pthread_join(tid, NULL);


return 0;
}

void *seek_vector_0(void *param){ //0 - 12499
for (int i = 0; i < 12500; i++) // Preenchendo o vetor
{
	if(v[i]> maior[0]){
        maior[0]= v[i];
        
      }
}
printf("Maior_0 é: %ld\n", maior[0]);
pthread_exit(0);
}

void *seek_vector_1(void *param){
for (int i = 12500; i < 25000; i++)
{
	if(v[i]> maior[1]){
        maior[1]= v[i];
        
      }
}
printf("Maior_1 é: %ld\n", maior[1]);
pthread_exit(0);
}

void *seek_vector_2(void *param){
for (int i = 25000; i < 37500; i++)
{
	if(v[i]> maior[2]){
        maior[2]= v[i];
       }
}
printf("Maior_2 é: %ld\n", maior[2]);
pthread_exit(0);
}

void *seek_vector_3(void *param){
for (int i = 37500; i < 50000; i++)
{
	if(v[i]> maior[3]){
        maior[3]= v[i];
       }
}
printf("Maior_3 é: %ld\n", maior[3]);
pthread_exit(0);}
