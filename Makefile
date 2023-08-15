CC=gcc


run: main.o tree.o
	$(CC) -o run main.o tree.o && rm *.o && clear && ./run

main.o: main.c
	$(CC) -c main.c

tree.o: tree.c
	$(CC) -c tree.c

cl:
	rm run *.o