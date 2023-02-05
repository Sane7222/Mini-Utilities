all: my-cat my-uniq

my-cat: my-cat.o
	gcc -o my-cat my-cat.o -Wall -Werror

my-cat.o: my-cat.c
	gcc -c my-cat.c

my-uniq: my-uniq.o
	gcc -o my-uniq my-uniq.o -Wall -Werror

my-uniq.o: my-uniq.c
	gcc -c my-uniq.c

clean:
	rm *.o my-cat my-uniq