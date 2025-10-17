#include <stdio.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <errno.h>
 #include <string.h>
 
 int main(int argc, char *argv[]) {
 // Preverjanje, ali je podan pravilen argument
 if (argc != 2) {
 fprintf(stderr, "Uporaba: %s <ime_datoteke>\n", argv[0]);
 return 1;
 }
 
 // Ustvarjanje datoteke z uporabo sistemskega klica open
 int fd = open(argv[1], O_CREAT | O_WRONLY, S_IWUSR | S_IRGRP | S_IXOTH);
 if (fd == -1) {
 fprintf(stderr, "Napaka pri ustvarjanju datoteke %s: %s\n", argv[1], strerror(errno));
 return 1;
 }
 
 // Zapiranje datoteke
 if (close(fd) == -1) {
 fprintf(stderr, "Napaka pri zapiranju datoteke %s: %s\n", argv[1], strerror(errno));
 return 1;
 }
 
 printf("Datoteka %s uspešno ustvarjena.\n", argv[1]);
 printf("To je sprememba v main veji\n");
 return 0;
 }
