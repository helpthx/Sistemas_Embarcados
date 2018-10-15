//gcc ex1.c -o ex1 -lpthread 

#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

volatile int cout[10];  
void *thread_print(void *param);

int main(int argc, char const *argv[])
{
int i;
for (i = 0; i <= 10; i++)
{
    cout[i] = i;
}
pthread_t tid;
pthread_create(&tid,NULL, thread_print, NULL);
pthread_join(tid, NULL);


return 0;
}

void *thread_print(void *param){
    int i;
    for (i = 1; i <= 10; i++)
    {
      sleep(1);
      printf("%d\n", cout[i]);
      
    }
pthread_exit(0);
}