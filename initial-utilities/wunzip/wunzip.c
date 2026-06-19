#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wunzip: cannot open the file %s\n", argv[i]);
            return 1;
        }

        int length;
        char c;
        while (fread(&length, sizeof(int), 1, fp) != 0) {
            // pintf("length = %d\n", length);
            fread(&c, sizeof(char), 1, fp);
            for (int i = 0; i < length; i++) {
                printf("%c", c);
            }
        }
        fclose(fp);
    }
}
