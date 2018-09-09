bib_arqs: main7.o bib_arqs.o
	gcc $(CFLAGS) -o bib_arqs main7.o bib_arqs.o

bib_arqs.o: bib_arqs.c bib_arqs.h
	gcc $(CFLAGS) -c bib_arqs.c
	
main5.o: main7.c bib_arqs.h
	gcc $(CFLAGS) -c main7.c



clean:
	rm -f *.o bib_arqs
