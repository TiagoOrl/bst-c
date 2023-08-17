CC=gcc


run: main.o tree.o
	$(CC) -o run main.o tree.o && rm *.o && clear && ./run

main.o: main.c
	$(CC) -c main.c

tree.o: src/tree.c
	$(CC) -c src/tree.c

cl:
	rm run *.o