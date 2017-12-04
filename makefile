all: main.o execute.o input.o 
	gcc -o shell main.o execute.o input.o 

main.o: main.c
	gcc -c main.c

execute.o: execute.c
	gcc -c execute.c

input.o: input.c
	gcc -c input.c

run:all
	./shell
