#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int i;
    char * dizi[6];// kullanıcının girdileri dizinin elemanlarına atanır.
    int islem;	
    dizi[0] = argv[1];
    dizi[1] = argv[2];
    dizi[2] = argv[3];
    dizi[3] = argv[4];
    dizi[4] = NULL;
    int tekrar_input = atoi(argv[1]); // argv[1] ile aldığımız kullanıcı girdisi (programın kaç defa çağıralacağını belirten string) integer degere cevrilir
    for (i = 0; i < tekrar_input; i++) {
     	int forkInt = fork();// fork islemi yapılır.
    	if (forkInt == 0) {
      		islem = execv(argv[2], dizi);// cagırılcak programa gidilir. writef
    	} else if (forkInt < 0) {
      		exit(EXIT_FAILURE);
    	} else {
      		wait(&islem);// parent process bekletilir. Çocuk processin önce bitmesi sağlanır.
    	} 
    }
  
  return 0;
}

