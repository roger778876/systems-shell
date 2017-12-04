all: execute.o input.o main.o
	gcc -o shell execute.o input.o main.o

execute.o: execute.c
	gcc -c execute.c

input.o: input.c
	gcc -c input.c

main.c: main.c
	gcc -c main.c

run:all
	./shell
