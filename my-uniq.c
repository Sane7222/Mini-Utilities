#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 2048

void main(int argc, char *argv[]){

    if(argc > 1){ // Files given
        for(int i = 1; i < argc; i++){

            FILE *f = fopen(argv[i], "r"); // Open file
            if(f == NULL){ // Error opening
                fprintf(stderr, "my-uniq: cannot open file\n");
                exit(1);
            }

            char *l1 = malloc(BUFFER_SIZE * sizeof(char)), *l2 = malloc(BUFFER_SIZE * sizeof(char));
            l2[0] = '\0';

            while(fgets(l1, BUFFER_SIZE, f) != NULL){ // While get lines from FILE
                if(strcmp(l1, l2) != 0) fprintf(stdout, "%s", l1); // If not the same print
                free(l2);
                l2 = strdup(l1);
            }
            fclose(f); // Close file
            free(l1); free(l2); // Free memory
        }
        exit(0);
    }

    // No files given
    char *l1 = malloc(BUFFER_SIZE * sizeof(char)), *l2 = malloc(BUFFER_SIZE * sizeof(char));
    l2[0] = '\0';

    while(fgets(l1, BUFFER_SIZE, stdin) != NULL){ // While get lines from STDIN
        if(strcmp(l1, l2) != 0) fprintf(stdout, "%s", l1); // If not the same print
        free(l2);
        l2 = strdup(l1);
    }
    free(l1); free(l2); // Free memory
    exit(0);
}