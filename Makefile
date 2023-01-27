all: my-cat

my-cat: my-cat.o
	gcc -o my-cat my-cat.o -Wall -Werror

my-cat.o: my-cat.c
	gcc -c my-cat.c

clean:
	rm *.o my-cat