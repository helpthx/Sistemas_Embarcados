compile: main.o num_caracs.o
	gcc $(CFLAGS) -o num_caracs main.o num_caracs.o

num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS) -c num_caracs.c
	
main.o: main.c num_caracs.h
	gcc $(CFLAGS) -c main.c



clean:
	rm -f *.o num_caracs