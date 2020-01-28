#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    else {
        for (int i = 1; i < argc; ++i) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wunzip: cannot open file\n");
                exit(1);
            }
            else {
                int counter = 0;
                char current ;
                size_t counterSize = fread(&counter, 4, 1, fp);
                fread(&current, 1, 1, fp);

                while(counterSize == 1) {
                    for (int j = 0; j < counter; ++j) {
                        printf("%c", current);
                    }

                    counterSize = fread(&counter, 4, 1, fp);
                    fread(&current, 1, 1, fp);
                }


            }
            fclose(fp);
        }
    }
    return 0;

}
