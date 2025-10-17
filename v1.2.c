#include <stdio.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <errno.h>
 #include <string.h>
 #include <unistd.h>
 
 int main(int argc, char *argv[]) {
    // Preverjanje, ali je podan pravilen argument
    if (argc != 2) {
        fprintf(stderr, "Uporaba: %s <ime_datoteke>\n", argv[0]);
        return 1;
    }
 
    const char *ime_datoteke = argv[1];

    // Ustvarjanje datoteke z uporabo sistemskega klica open
    int fd = open(ime_datoteke, O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IXOTH);
    if (fd == -1) {
        if (errno == EEXIST) {
            printf("zbirka %s ze obstaja\n", ime_datoteke);
        } else {
            printf("napaka pri odpiranju %s\n", ime_datoteke);
        }
        return 1;
    }
    
    close(fd);
    
    printf("Datoteka %s uspešno ustvarjena.\n", ime_datoteke);
    return 0;
 }