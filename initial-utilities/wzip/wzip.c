#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    else {
        int globalCounter = -1;
        char globalCurrent;

        for (int i = 1; i < argc; ++i) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wzip: cannot open file\n");
                exit(1);
            }
            else {
                char current;
                int counter;
                if(globalCounter < 0) {
                    current = fgetc(fp);
                    counter = 1;
                }
                else {
                    current = globalCurrent;
                    counter = globalCounter;
                }
                while(current != EOF) {

                    char next;
                    while((((next = fgetc(fp)) == current) && next != EOF)) {
                        counter++;
                    }
                    if (next != EOF || (i == (argc - 1))) {
                        fwrite(&counter, 4, 1, stdout);
                        fputc(current, stdout);
                        globalCounter = -1;
                        counter = 1;
                    }
                    else {
                        globalCurrent = current;
                        globalCounter = counter;
                    }
                    current = next;
                }

            }
            fclose(fp);
        }
    }
    return 0;
}