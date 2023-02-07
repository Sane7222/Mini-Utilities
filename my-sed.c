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
    FILE *stream;

    if (argc < 4) {
        // need to read from STDIN...
        stream = stdin;
    } else {
	// need to read from files...
	// TODO: functionality for more than 1 file.
	stream = fopen(argv[3], "r");
	if (stream == NULL) {
	    printf("cannot open the file\n");
	    exit(1);
	}
    }

    // read lines...
    char *line = NULL;
    size_t len = 0;
    size_t characters;
    ssize_t nread;
    
    while ((nread = getline(&line, &len, stream)) != -1) {
	// just printing for now, need to actually process the lines
        printf("<%zd> %s", nread, line);
    }

    // free the line buffer and close the file...
    free(line);
    fclose(stream);

    printf("DONE!\n");

    exit(0);
}
