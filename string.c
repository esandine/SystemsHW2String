#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Length
int elylen(char s[]){
  int i = 0;
  while(s[i]){
    i++;
  }
  return i;
}
//strncpy
char* elyncpy(char *dest, char *src, int n){
  dest+=n;
  while(n>0){
    dest=src+n;
    n--;
    dest--;
  }
}
//strcpy
char* elycpy(char *dest, char *src){
  elyncpy(dest, src, elylen(src));
}

//strncat
char* elyncat(char *dest, char *src, int n){
  elyncpy(dest+elylen(src), src, n);
}
int main(){
  //Length 
  char e[4] = "Ely";
  printf("strlen(Ely): %d\n",strlen(e));
  printf("elylen(Ely): %d\n\n",elylen(e));

  //strncpy
  char d[4] = "Egg";
  char d2[4] = "Egg";
  printf("strncpy(Egg,Ely): %s\n",strncpy(d,e,4));
  printf("elyncpy(Egg,Ely): %s\n\n",strncpy(d2,e,4));

  //strcpy
  printf("strcpy(Egg,Ely): %s\n",strcpy(d,e));
  printf("elycpy(Egg,Ely): %s\n\n",strcpy(d2,e));

  //strncat
  char cat[10] = "Ely";
  char catted[5] = "Ely2";
  printf("strcat(Ely,Ely2): %s\n",strcat(cat,catted));
  printf("elycat(Ely,Ely2): %s\n\n",strcat(cat,catted));

}
