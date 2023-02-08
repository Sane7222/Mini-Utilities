#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

void my_sed(char *, char *, char*);

void main(int argc, char *argv[]) {
    
    // check for valid args
    if (argc < 3) {
        printf("my-sed: find_term replace_term [file ...]\n");
        exit(1);
    }

    if (argc < 4) {
        // need to read from STDIN...
        my_sed(NULL, argv[1], argv[2]);
    } else {
        // need to read from files...
        int arg_i = 3;
        for (arg_i; arg_i < argc; arg_i ++) {
            my_sed(argv[arg_i], argv[1], argv[2]);
        }
    }

    exit(0);
}

void my_sed(char *input, char *find_term, char *replace_term) {
    // open the input stream
    FILE *stream = NULL;
    if (input == NULL) {
        stream = stdin;
    } else {
        stream = fopen(input, "r");
        if (stream == NULL) {
            printf("cannot open the file\n");
            exit(1);
        }
    }
    
    // get the lengths of the terms
    int find_term_len = strlen(find_term);
    int replace_term_len = strlen(replace_term);

    // get ready to read lines using getline()
    char *line = NULL;           // the original line
    char *newline = NULL;        // the new line
    size_t len = 0;
    ssize_t nread = 0;
    
    // begin reading lines
    while ((nread = getline(&line, &len, stream)) != -1) {
        int original_i = 0;      // for indexing into original line 
        int new_i = 0;           // for indexing into new line
        int found_flag = 0;      // to let us know if we've found the find_term or not

        newline = malloc((len + replace_term_len + 1) * sizeof(char));
        if (newline == NULL) {
            // yikes, issue with malloc
            // better clean up...
            free(line);
            fclose(stream);
            exit(1);
        }

        // begin checking chars in original line one by one
        for (original_i; original_i < nread; original_i++) {
            if (found_flag == FALSE && line[original_i] == find_term[0]) {
                // possible find_term located...
                int find_offset = 0;
                int replace_offset = 0;

                found_flag = TRUE;
                for (find_offset; find_offset < find_term_len; find_offset++) {
                    if (original_i + find_offset >= nread) {
                        // reached the end of the original string, stop
                        found_flag = FALSE;
                        break;
                    }
                    
                    if (line[original_i + find_offset] != find_term[find_offset]) {
                        // not the actual find_term, stop
                        found_flag = FALSE;
                        break;
                    }
                }

                if (found_flag == TRUE) {
                    // found! start adding the replaced chars to the new string
                    for (replace_offset = 0; replace_offset < replace_term_len; replace_offset++) {
                        newline[new_i + replace_offset] = replace_term[replace_offset];
                    }

                    // adjust the character pointers to compensate for find/replace offsets
                    new_i = original_i + replace_offset;
                    original_i = original_i + find_offset;
                }
            }
            
            // copy char into new line
            newline[new_i++] = line[original_i];
        }

        // terminate the newline with null char and print the output
        newline[new_i++] = '\0';
        printf("%s", newline);

        // set up for the next getline()
        free(newline);
        newline = NULL;
        free(line);
        line = NULL;
        len = 0;
    }

    // free getline in case we've reached this point without already freeing...
    if (line) {
        free(line);
    }

    // close the stream...
    fclose(stream);
}
