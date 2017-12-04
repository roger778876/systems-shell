all: execute.o input.o main.o
	gcc -o shell execute.o input.o main.o

execute.o: 
	gcc -c execute.c

input.o:
	gcc -c input.c

main.c:
	gcc -c main.c

run:all
	./shell
