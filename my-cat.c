#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024

void main(int argc, char* argv[]){
    char buffer[BUFFER_SIZE];
    int file, num;

    for(int i = 1; i < argc; i++){
        if((file = open(argv[i], O_RDONLY, 0)) == -1){
            fprintf(stderr, "my-cat: cannot open file\n");
            exit(1);
        }
        else{
            lseek(file, 0, SEEK_SET);
            while((num = read(file, buffer, BUFFER_SIZE)) > 0) write(1, buffer, num);
            close(file);
        }
        fprintf(stdout, "\n");
    }
    exit(0);
}