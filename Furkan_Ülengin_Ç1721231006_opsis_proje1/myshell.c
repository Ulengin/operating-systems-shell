#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int program_ayir(char * inp, char ** kelimedizi);
void caliscaklar(char * dizin[]);
int temizle(int a);
int* catLen = 0;


int main() {
  char* komutlar[20];
  char* yazilanlar[20];
  char* giris[650];

  while (1) {
    memset( &komutlar, 0, sizeof(komutlar));// &komutlar = 0 karakterin kopyalanacağı belleği gösteren işaretçidir.
    					    // &komutlar adresine kopyalanacak karakterdir.
    					    // sizeof(komutlar) kopyalancak maksimum karakter sayisidir.
	
    memset( &yazilanlar, 0, sizeof(yazilanlar));// &yazilanlar = 0 karakterin kopyalanacağı belleği gösteren işaretçidir.
    						// &yazilanlar adresine kopyalanacak karakterdir.
    						// sizeof(yazilanlar) kopyalancak maksimum karakter sayisidir.

    printf("\nmyshell>>");
    scanf("%[^\n]%*c", giris);// boşluklar da dahil olmak üzere, enter düğmesine basana kadar girdi olarak girilen tüm 
    			      // karakterlerin, giris değişkeninde saklanır.
    if (strcmp(giris, "exit") == 0) { 
      printf("\nProgram sonlandırıldı\n");
      exit(0);
      return 0;
    }    
    int uzunluk = program_ayir(giris, yazilanlar); 
    catLen = &uzunluk;
    caliscaklar(yazilanlar);
    }
    return 0;
  }

  int program_ayir(char* giris, char** kelimedizi) { // girdileri boşluk karaketerine göre ayırır.
    int i;
    for (i = 0; i < 20; i++) {
      kelimedizi[i] = strsep(&giris," ");

      if (kelimedizi[i] == NULL) {
        break;
      }
      if (strlen(kelimedizi[i]) == 0) {// Strlen() fonksiyonu ile kelimedizi[i] karakter dizisinin uzunluğunu geri döndürür
        i--;
      }
    }
    return i;
  }
int temizle(int a) { // clear komutunu cagiran fonksiyon
  a = execvp("clear", (char *const []) {
   "clear",NULL});
  return a;
}

void caliscaklar(char * dizinarray[]) { // girdiye göre ilgili programlar çalıştırılır.
  char * args[6];
  int i;
  args[0] = dizinarray[1];
  args[1] = dizinarray[2];
  args[2] = dizinarray[3];
  args[3] = dizinarray[4];
  args[4] = dizinarray[5];
  args[5] = NULL;

  int f = fork();

    if (f == 0) {

    if (strcmp(dizinarray[0], "clear") == 0) {
      temizle(i);
      printf("Yanlış Komut Girdiniz\n");
    } else if (strcmp(dizinarray[0], "ls") == 0) {
       i = execv("/bin/ls", dizinarray);
       perror("Yanlış Komut Girdiniz\n");
    }
    else if (strcmp(dizinarray[0], "cat") == 0) {
       i = execv("/bin/cat", dizinarray);
    }
    else if (strcmp(dizinarray[0], "bash") == 0) {
       i = execv("/bin/bash", dizinarray);
       perror("Yanlış Komut Girdiniz\n");
    }  
    else if (strcmp(dizinarray[0], "execx") == 0){
        i = execv(dizinarray[0], args);
        perror("Yanlış Komut Girdiniz\n");
    }else{
        printf("Yanlış Komut Girdiniz\n");
        exit(EXIT_FAILURE);
    }
  } else  if (f < 0) {
    printf("\nçocuk fork hata");
    exit(EXIT_FAILURE);
  } else {
    wait(&i);   
  }
}

