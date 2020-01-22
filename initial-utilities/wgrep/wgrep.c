#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    else if (argc == 2) {
        char* key = argv[1];
        char* result = malloc(20 * sizeof(char));
        size_t buffSize = 10;
        ssize_t size;
        while (((size = getline(&result, &buffSize, stdin)) > 0)) {
            char* linePtr = strstr(result, key);
            if(linePtr != NULL) {
                printf("%s", result);
            }
        }
        free(result);
    }
    else {
        for (int i = 2; i < argc; ++i) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            char* key = argv[1];
            char* result = malloc(20 * sizeof(char));
            size_t buffSize = 10;
            ssize_t size;
            while (((size = getline(&result, &buffSize, fp)) > 0)) {
                char* linePtr = strstr(result, key);
                if(linePtr != NULL) {
                    printf("%s", result);
                }
            }
            free(result);
        }
        
    }
    return 0;
}