#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uporaba: %s <ime_datoteke>\n", argv[0]);
        return 1;
    }


    const char *ime_datoteke = argv[1];

    int fd = open(ime_datoteke, O_WRONLY | O_TRUNC);
    if (fd == -1) {
        fprintf(stderr, "Napaka pri odpiranju %s: %s\n", ime_datoteke, strerror(errno));
        return 1;
    }

    const char *besedilo = "CENZURA\n";

    __ssize_t zapisano = write(fd, besedilo, strlen(besedilo));
    if (zapisano == -1) {
        fprintf(stderr, "Napaka pri pisanju v %s: %s\n", ime_datoteke, strerror(errno));
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}