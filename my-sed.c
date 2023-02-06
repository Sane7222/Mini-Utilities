#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 2048

void main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("my-sed: find_term replace_term [file ...]\n");
        exit(1);
    }

    char *find_term = argv[1];
    char *replace_term = argv[2];

    if (argc < 4) {
        // need to read from STDIN...
    }

    // to be continued...

    exit(0);
}