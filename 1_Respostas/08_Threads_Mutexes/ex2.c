//gcc ex2.c -o ex2 -lpthread 

#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

long int v[50000], maior;
void *seek_vector(void *param);

int main(int argc, char const *argv[])
{
int i, rand_numb, posicao;
srand(time(NULL)); // Inicializa gerador de valores aleatorios
for (int i = 0; i < 50000; ++i)
{
	rand_numb = rand();
	v[i] = rand_numb;
	printf("%ld\n", v[i]);
	if(v[i]>maior){
        maior= v[i];
        posicao = i;
      }
}
printf("Maior é: %ld\n", maior);
printf("Na posição: %d\n", posicao);


pthread_t tid;
pthread_create(&tid,NULL, seek_vector, NULL);
pthread_join(tid, NULL);


return 0;
}

void *seek_vector(void *param){
pthread_exit(0);
}