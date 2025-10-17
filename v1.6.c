#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Uporaba: %s <ime_datoteke>\n", argv[0]);
        return 1;
    }

    const char *sporocilo = "Pozdravljen svet!";


    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Napaka pri odpiranju datoteke");
        return 1;
    }

    char buffer[5];
    size_t prebrano;

    if (fprintf(fp, "%s\n", sporocilo) < 0) {
        perror("Napaka pri pisanju v datoteko");
    } else {
        printf("Pisanje v datoteko %s uspesno.\n", argv[1]);
    }
    
    fclose(fp);

    return 0;
}