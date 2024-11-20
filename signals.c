#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
volatile sig_atomic_t stop = 0;

void no_me_mates(int signum) {
    printf("RECIBI LA SEÑAL %d\n", signum);
    printf("NO ME PUEDES MATAR\n");
}

void me_matas(int signum) {
    printf("SEÑAL RECIBDA %d\n", signum);
    printf("ME MATARON\n");
    stop = 1;
}

int main() {
    signal(2, no_me_mates);
    signal(10, me_matas);
    while (stop==0) {  
        printf("TRABAJANDO\n");
        sleep(1);
    }

    printf("FIN DEL PROGRAMA\n");
    return 0;
}
