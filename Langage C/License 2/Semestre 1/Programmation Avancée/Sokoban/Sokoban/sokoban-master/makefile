CFLAGS = -g -Wall -ansi -pedantic 

all : plateau.o main.o partie.o liste.o 
	   gcc $(CFLAGS) plateau.o partie.o liste.o main.o -o main

plateau.o: plateau.c
	 gcc -c $(CFLAGS) plateau.c
liste.o: liste.c
	 gcc -c $(CFLAGS) liste.c
partie.o: partie.c 
	gcc -c $(CFLAGS) partie.c

main.o: main.c
	gcc -c $(CFLAGS) main.c

