all: main.c
	gcc -o shell main.c

run: all
	./shell

clean:
	rm -f *.o
	rm -f *~
	rm -f shell
	rm -f a.out