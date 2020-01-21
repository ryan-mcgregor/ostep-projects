//
// Created by Ryan on 1/15/2020.
//

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc == 1) {
        return 0;
    }
    else if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wcat: cannot open file\n");
                exit(1);
            }
            else {
                char buffer[100];
                while(fgets(buffer, 100, fp) != NULL) {
                    printf("%s", buffer);
                }
            }
            fclose(fp);
        }
    }

    return 0;
}