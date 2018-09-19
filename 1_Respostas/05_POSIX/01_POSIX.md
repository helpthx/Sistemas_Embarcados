1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?
#	FILE **fopen(char **nome_do_arquivo, char **modo);
#	int fclose(FILE **ponteiro_para_arquivo);

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?
#	int fputc(int ch, FILE **fp);

(c) Quais são as funções (e seus protótipos) para ler arquivos?
#	int getc(FILE **fp);

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?
# int fseek(FILE **stream, long int offset, int origin);

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
# <stdio.h> e <stdlib.h>


2. O que é a norma POSIX?
	Norma para manipulação de arquivos de entradas e saida, de preferencia, para trabalhar com hardware.
3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?
#	int open(const char* path, int oflag,...);
#	int close(int fildes);

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?
#	ssize_t write(int fildes, const void **buf, size_t nbyte);

(c) Quais são as funções (e seus protótipos) para ler arquivos?
#	ssize_t read(int fildes, void **buf, size_t nbytes);

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?
#	off_t lseek(int fd, off_t offset, int whence);

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
#	<fcntl.h>