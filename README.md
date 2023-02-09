
Project 1: Mini Unix Utilities

1. my-cat
Defined a buffer of size 1024. 
Program will only open files from the command line that are passed in as arguments to main
Opens each file one at a time and reads from and prints out until EOF

2. my-sed
Our implementation of my-sed locates and replaces the first occurrence of user-specified strings/terms line by line in text either via STDIN (if no filepath arguments are provided) or via an arbitrary number of files (specified via filepaths in the command line). Usage for my-sed should match the project specifications exactly.
For my-sed, we used getline() to copy lines from either STDIN or file streams because getline() would allocate a buffer of large enough size for us in order to parse the original line. We then allocated another buffer equal to the size of the first buffer plus some extra space to accommodate the replace term if the replace term ended up being significantly larger than the original line. We then parsed through the original line character by character, copying the characters from the original line into the replacement line. If the find_term was found in the original line, the replace_term would be copied into the replace line instead, and the rest of the original line would be copied as is.

3. my-uniq
Defined buffer size of 2048
If args are present my-uniq opens each arg as a file
Mallocs 2 buffers to store the current and previous lines
Compares lines, frees the old one and duplicates the new one to the old one
Repeats this process for all files in the command line args
If there are no command line args then the program read from STDIN
Two identical lines where one ends with a newline and the other does not are considered not identical