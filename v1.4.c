#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Uporaba: %s <ime_datoteke>\n", argv[0]);
        return 1;
    }

    const char *ime_datoteke = argv[1];

    FILE *fp = fopen(ime_datoteke, "a");
    if (fp == NULL) {
        perror("Napaka pri odpiranju datoteke");
        return 1;
    }

    fprintf(fp, "\nKONEC\n");
    fclose(fp);

    printf("V datoteko '%s' je bila dodana vrstica 'KONEC'\n", ime_datoteke);
    return 0;
}