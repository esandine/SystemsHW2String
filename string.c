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
  while(n>=0){
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
  elyncpy(dest+elylen(dest), src, n);
}

//strcpy
char* elycat(char *dest, char *src){
  elyncat(dest,src,elylen(src));
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
  printf("elyncpy(Egg,Ely): %s\n\n",elyncpy(d2,e,4));

  //strcpy
  printf("strcpy(Egg,Ely): %s\n",strcpy(d,e));
  printf("elycpy(Egg,Ely): %s\n\n",elycpy(d2,e));

  //strncat
  char catn[10] = "Ely";
  char cattedn[5] = "Ely2";
  printf("strcat(Ely,Ely2): %s\n",strncat(catn,cattedn,4));
  printf("elycat(Ely,Ely2): %s\n\n",elyncat(catn,cattedn,4));

  //strcat
  char cat[10] = "Ely";
  char catted[5] = "Ely2";
  printf("strcat(Ely,Ely2): %s\n",strcat(cat,catted));
  printf("elycat(Ely,Ely2): %s\n\n",elycat(cat,catted));

}
