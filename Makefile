CC=gcc
FL=-g

run: main.o tree.o
	$(CC) -o run main.o tree.o && rm *.o && clear && ./run

comp: main.o tree.o
	$(CC) -o run main.o tree.o && rm *.o

main.o: main.c
	$(CC) -c main.c $(FL)

tree.o: src/tree.c
	$(CC) -c src/tree.c $(FL)

cl:
	rm run debug *.o