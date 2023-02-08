all: my-cat my-sed my-uniq

my-cat: my-cat.o
	gcc -o my-cat my-cat.o -Wall -Werror

my-cat.o: my-cat.c
	gcc -c my-cat.c

my-sed: my-sed.o
	gcc -o my-sed my-sed.o -Wall -Werror

my-sed.o: my-sed.c
	gcc -c my-sed.c

my-uniq: my-uniq.o
	gcc -o my-uniq my-uniq.o -Wall -Werror

my-uniq.o: my-uniq.c
	gcc -c my-uniq.c

clean:
	rm *.o my-cat my-sed my-uniq