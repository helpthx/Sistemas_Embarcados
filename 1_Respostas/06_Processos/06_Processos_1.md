1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?
```bash
ps -A
```

(b) Mostrar os processos de um usuário?
```bash
ps -u usuário
```

(c) Ordenar todos os processos de acordo com o uso da CPU?
```bash
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head
```
(d) Mostrar a quanto tempo cada processo está rodando?
```bash
ps -at
```
2. De onde vem o nome `fork()`?
Bifurcação ou garfo em inglês.

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?
* Execultar comandos no shell do linux no proprio diretorio. 
* Permite executar um comando dentro de um programa, criando um sub-processo. Necessita da biblioteca stdlib.h

(b) `fork()` e `exec()`?
* fork() cria uma copia do processo atual e em seguida a função exec() substitui o conteudo do novo processo por um novo programa.

4. É possível utilizar o `exec()` sem executar o `fork()` antes?
* Não, pois o exec() necessita da criação de um novo processo filho.

5. Quais são as características básicas das seguintes funções:

(a) `execp()`?
Aceitam que o nome ou procura do programa estejam no "caminho atual". Devem conter o caminho completo do programa a ser executado. 

(b) `execv()`?
Aceitam que a lista de argumentos do novo programa seja nula.
(c) `exece()`?
Substitui op rograma em execução por um outro, ele não retorna valor algum, exceto quando um erro ocorre.
(d) `execvp()`?
Combinação emtre a lista de argumentos do novo programa seja nula e especificar o caminho completo do programa a ser executado.
(e) `execve()`?
Aceitam argumentos adicinal.
(f) `execle()`?
Aceitam argumentos adicinal.