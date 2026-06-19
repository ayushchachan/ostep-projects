#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep_stream(FILE *fp, char *pattern);

// A simple grep-like utility that searches for a pattern in a file
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    char *searchterm = argv[1];


    if (argc == 2) {
        grep_stream(stdin, searchterm);
        exit(0);
    }

    for (int i = 2; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        grep_stream(fp, searchterm);
        fclose(fp);
    }
    return 0;
}

/**
 * Searches for a pattern in a file stream and prints matching lines to stdout.
 */
void grep_stream(FILE *fp, char *pattern) {
    char *line = NULL;
    size_t buffer_size = 0;
    ssize_t read;

    while ((read = getline(&line, &buffer_size, fp)) != -1) {
        if (strstr(line, pattern) == NULL) {
            continue;
        }
        printf("%s", line);
    }



}
