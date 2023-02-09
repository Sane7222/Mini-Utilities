#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1024

void main(int argc, char *argv[]){

    size_t len = 0;
    char *l1 = NULL;

    if(argc > 1){ // Files given
        for(int i = 1; i < argc; i++){

            FILE *f = fopen(argv[i], "r"); // Open file
            if(f == NULL){ // Error opening
                fprintf(stderr, "my-uniq: cannot open file\n");
                exit(1);
            }

            char *l2 = malloc(BUFFER_SIZE * sizeof(char));
            l2[0] = '\0';

            while(getline(&l1, &len, f) != -1){ // While get lines from FILE
                if(strcmp(l1, l2) != 0) fprintf(stdout, "%s", l1); // If not the same print
                free(l2);
                l2 = strdup(l1);
                free(l1);
                l1 = NULL;
            }
            fclose(f); // Close file
            free(l2); // Free memory
        }
        free(l1); 
        exit(0);
    }

    char *l2 = malloc(BUFFER_SIZE * sizeof(char));
    l2[0] = '\0';

    // No files given
    while(getline(&l1, &len, stdin) != -1){ // While get lines from STDIN
        if(strcmp(l1, l2) != 0) fprintf(stdout, "%s", l1); // If not the same print
        free(l2);
        l2 = strdup(l1);
        free(l1);
        l1 = NULL;
    }
    free(l2); // Free memory
    exit(0);
}