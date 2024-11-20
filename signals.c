#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void noMeMates(int signum){
   printf("Recibi la señal %d", signum);
   printf("No me puedes matar");
}


int condicion;
void terminarCiclo(int signum){
   condicion = 0;
}




int main(){
   signal(2, noMeMates);
   signal(10, terminarCiclo);
   condicion = 1;
   while(condicion == 1){
       printf("Trabajando ");
       sleep(2);
   }
   printf("Terminando");
   return 0;
}
