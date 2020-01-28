#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
    }
    else {
        int globalCounter = -2;
        char globalCurrent;

        for (int i = 1; i < argc; ++i) {
            FILE *fp = fopen(argv[i], "rb");
            if (fp == NULL) {
                printf("wzip: cannot open file\n");
            }
            else {
                char current;
                int counter;
                while(current != EOF) {
                    if(globalCounter < 0) {
                        current = fgetc(fp);
                        counter = 1;
                    }
                    else {
                        current = globalCurrent;
                        counter = globalCounter;
                    }
                    char next;
                    while((((next = fgetc(fp)) == current) && next != EOF)) {
                        counter++;
                    }
                    if (next != EOF || (argc == (i+1))) {
                        fwrite(&counter, 4, 1, stdout);
                        fwrite(&current, 1, 1, stdout);
                        globalCounter = -1;
                    }
                    else {
                        globalCurrent = current;
                        globalCounter = counter;
                    }
                    current = next;

                }

            }
        }
    }
}