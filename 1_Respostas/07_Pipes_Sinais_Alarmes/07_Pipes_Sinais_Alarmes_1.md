1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```
```
Aqui são criado dois, pois a função fork cria exatamente as mesmas variaveis para o processo filho e o processo pai, os pipe com a posição de leitura[0] e escrita[1].
```

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```
```
Aqui é criado um pipe pois depois do fork o codigo criara apenas um pipe para o filho ou o pai.
```

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?
```

	*`SIGKILL` Mata todos os processos. Destruição.*
	*`SIGQUIT` Ao apertar CTRL+d, emite um sinal para abandonar um processo.*
	*`SIGILL` Instrução ilgeal é detectada.*
	*`SIGIOT` Problemas de hardware.* 
	*`SIGSYS` Argumento incorreto de uma chamada de sistema.* 
```

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?
Tem uma otima precisão, porem o maior problema sempre sera no inicio da contagem que se perde pelo menos 3 segundos de informações, em determinadas aplicações isso pode ser um problema grande. Porem ainda assim, pode-se confiar bastante nesse desenvolvimento em aplicações em tempo real.
