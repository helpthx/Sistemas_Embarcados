#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	if (argc > 1){
	
	int i;
	int a;
	
	for (i = 1; argv[i]; ++i)
	{
		a = system(argv[i]);
		printf("\n");
	}
	}

	else{
		printf("OPS... Ocorreu algum erro !\n");
		exit(-1);
	}
	return 0;
}