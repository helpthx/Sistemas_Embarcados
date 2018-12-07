1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?
```
Cria mais recursos para cada processo, ou seja, pode ser usado quando existe uma demanda de mais processamento no processos. Porem precisa de criação de pipes, sinais e semafaros para fazer a comunicação entre processos. 
```

(b) threads?

```
Os unicos recursos que não são compartilhadores são os registradores de kernel e a stack, podem comunicar-se via variaveis globais. A criação é mais rapida com maior facilidade de escalonamento e a comunicação mais simples. Porem como compartilha diversos recursos é menos eficiente no processamento do que um processo.  
```

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

```
Serão criadas duas threads, e a sequencia do main, que coexistirão até a thread 1 finalizar a função funcao_thread_1.
```

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
```
Serão criadas duas threads, e a sequencia do main, porem a thread t1 coexistirar com o processo do main até finalizar a função funcao_thread_1, então a thread t1 será finalizada e será criado a thread t2 que coexistirar com o processo main até finalizar a função funcao_thread_2.
```

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`
```
Controla o comportamento de um thread causada pela chama da função pthread_cancel(). Os estados de cancelamento podem ser PTHREAD_CANCEL_ENABLE, coloca o estatus de cancelamento na função pthread_setcanceltype, e PTHREAD_CANCEL_DISABLE onde a thread não pode ser cancelada. 	
```


(b) `pthread_setcanceltype()`
```
Controla quando uma requisição de cancelamento agiu sob o codigo. Pode ser PTHREAD_CANCEL_ASYNCHRONOUS, a thread pode ser cancelada a qualquer momento, ou PTHREAD_CANCEL_DEFERRED a thread só pode ser cancelada ao invocar uma função especifica. 
 ```
(DICA: elas são relacionadas à função pthread_cancel().)
