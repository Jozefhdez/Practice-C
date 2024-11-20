#include <stdio.h>
#include <pthread.h>

void * printHola(void * arg){
    int pid = *((int * )arg);
    printf("HOLA DESDE EL HILO %d\n", pid);
    pthread_exit(NULL);
}


int saldo;
void *incrementaSaldo(void * arg){
    saldo += 100;
    pthread_exit(NULL);
}

int main(){
    int NUM_THREADS = 20;
    pthread_t hilosStatus[NUM_THREADS];
    int pids[NUM_THREADS];

    saldo = 0;

    for(int i = 0; i < NUM_THREADS; i++){
        pids[i] = i;
        pthread_create(&hilosStatus[i], NULL, incrementaSaldo, NULL);
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(hilosStatus[i], NULL);
    }

    printf("Saldo final: %d\n", saldo);
    pthread_exit(NULL);

    return 0;
}