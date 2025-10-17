#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Uporaba: %s <ime_datoteke>\n", argv[0]);
        return 1;
    }

    const char *ime_datoteke = argv[1];

    FILE *fp = fopen(ime_datoteke, "r");
    if (fp == NULL) {
        perror("Napaka pri odpiranju datoteke");
        return 1;
    }

    char buffer[5];
    size_t prebrano;

    while ((prebrano = fread(buffer, 1, 4, fp)) > 0) {
        for (size_t i = 0; i < prebrano; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = ' ';
            }
        }
        buffer[prebrano] = '\0';
        printf("%s\n", buffer);
    }
    
    fclose(fp);

    return 0;
}