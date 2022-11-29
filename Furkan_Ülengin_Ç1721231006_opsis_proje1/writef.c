#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* args[]){
	time_t t;
    	time(&t);
	if(args[2]!=NULL){
		
		printf("pid = %d. parent ppid = %d. Time is = %s",getpid(),getppid(),ctime(&t)); // konsola process id, parent process id ve sistemin anlık olarak tarih ve zaman bilgisini alır.
		
		FILE *dosya = fopen(strcat(args[3],".txt"), "a"); // girdi olarak alınan dosya ismini alır ve dosya ismiyle bir text dosyası oluşturur ve açar. Aynı dosyadan var ise yeni dosya oluşturmaz.
  		fprintf(dosya,"pid = %d. parent ppid = %d. Time is = %s",getpid(),getppid(),ctime(&t));// açılan dosya içerisine process id, parent process id ve tarih zaman bilgisini yazar.

  		fclose(dosya);// açılan dosyayı kapatır.
  		

	}else{
	
		printf("pid = %d. parent ppid = %d. Time is = %s",getpid(),getppid(),ctime(&t));;
		
		FILE *dosya = fopen("dosya.txt", "a"); // dosya.txt olarak bir dosya oluşturulur ve açılır. Aynı isimli dosya varsa dosya sadece açılır.

  		fprintf(dosya,"pid = %d. parent ppid = %d. Time is = %s",getpid(),getppid(),ctime(&t));

  		fclose(dosya);
  		  		
  		
	}
	return 0;
}
