#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    int prev_char = EOF;
    int count_consecutive = 0;

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            printf("wzip: cannot open the file %s\n", argv[i]);
            return 1;
        }

        int current_char;

        while ((current_char = fgetc(fp)) != EOF) {

            if (current_char == prev_char) {
                count_consecutive++;
            } else if (prev_char == EOF) {
                prev_char = current_char;
                count_consecutive = 1;
            } else {
                char c = (char)prev_char;
                fwrite(&count_consecutive, sizeof(int), 1, stdout);
                fwrite(&c, sizeof(char), 1, stdout);
                prev_char = current_char;
                count_consecutive = 1;
            }
        }
        fclose(fp);
    }
    if (prev_char != EOF) {
        char c = (char)prev_char;
        fwrite(&count_consecutive, sizeof(int), 1, stdout);
        fwrite(&c, sizeof(char), 1, stdout);
    }
}
