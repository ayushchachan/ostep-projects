#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// wcat - concatenate files and print to stdout
int main(int argc, char *argv[]) {
    if (argc < 2) {
        // printf("Usage: wcat <filename1> [<filename2> ...]\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) {

        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        fclose(file);
    }

    return 0;
}
