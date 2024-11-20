#include <unistd.h>


int main(){
   int a = 5;
  
   int pid = fork();
  
  
   if(pid == 0){
       printf("Soy el proceso hijo, a = %d\n", a);
       execl("./hello", "hello", "Jozef", "Yo", (char *) NULL);
       printf("ESTO NO DEBERIA DE IMPRIMIRSE");
       return 0;
   }


   printf("Soy el proceso padre, a = %d\n", a);
   sleep(20);
   return 0;
}
