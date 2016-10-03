#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Length
int elylen(char *s){
  int i = 0;
  while(*(s+i)){
    i++;
  }
  return i;
}
//strncpy
char* elyncpy(char *dest, char *src, int n){
  dest+=n;
  while(n>0){
    *dest=*(src+n);
    n--;
    dest--;
  }
  return dest;
}
//strcpy
char* elycpy(char *dest, char *src){
  return elyncpy(dest, src, elylen(src));
}

//strncat
char* elyncat(char *dest, char *src, int n){
  return elyncpy(dest+elylen(dest), src, n)-elylen(dest);
}

//strcpy
char* elycat(char *dest, char *src){
  return elyncat(dest,src,elylen(src));
}

int elyncmp(char *s1, char *s2, int n){
  int i;
  i=0;
  while(i<n){
    if(*(s1+i)-*(s2+i)){
      return *(s1+i)-*(s2+i);
    }
    i++;
  }
  return 0;
}

int elycmp(char *s1, char *s2){
  if(elylen(s1)>elylen(s2)){
    return elyncmp(s1, s2, elylen(s1));
  }else{
    return elyncmp(s1, s2, elylen(s2));
  }
}

char *elychr(char *s, char c){
  while(*s){
    if(*s==c){
      return s;
    }
    s++;
  }
  return 0;
}

char *elystr(char *big, char *small){
  int i = 0;
  while(*big+i){
    if(elyncmp(big+i, small, elylen(small))){
      return big+i;
    }
    i++;
  }
  return 0;
}

int main(){
  //Length 
  char e[4] = "Ely";
  printf("strlen(Ely): %d\n",strlen(e));
  printf("elylen(Ely): %d\n\n",elylen(e));

  //strncpy
  char d[5] = "Egg";
  char d2[5] = "Egg";
  printf("strncpy(Egg,Ely): %s\n",strncpy(d,e,4));
  printf("elyncpy(Egg,Ely): %s\n\n",elyncpy(d2,e,4));

  //strcpy
  printf("strcpy(Egg,Ely): %s\n",strcpy(d,e));
  printf("elycpy(Egg,Ely): %s\n\n",elycpy(d2,e));

  //strncat
  char catn[10] = "Ely";
  char cattedn[5] = "Ely2";
  printf("strncat(Ely,Ely2): %s\n",strncat(catn,cattedn,4));
  printf("elyncat(Ely,Ely2): %s\n\n",elyncat(catn,cattedn,4));

  //strcat
  char cat[10] = "Ely";
  char catted[5] = "Ely2";
  printf("strcat(Ely,Ely2): %s\n",strcat(cat,catted));
  printf("elycat(Ely,Ely2): %s\n\n",elycat(cat,catted));

  //strncmp
  char ncmp1[5] = "Ely";
  char ncmp2[5] = "Egg";
  printf("strncmp(Ely,Egg): %d\n",strncmp(ncmp1,ncmp2,3));
  printf("elyncmp(Ely,Egg): %d\n\n",elyncmp(ncmp1,ncmp2,3));

  //strcmp
  char cmp1[5] = "Ely";
  char cmp2[20] = "Elysffdgsdghs";
  printf("strcmp(Ely,Elysffdgsdghs): %d\n",strcmp(cmp1,cmp2));
  printf("elycmp(Ely,Elysffdgsdghs): %d\n\n",elycmp(cmp1,cmp2));

  //strchr
  char chr[20] = "Elysffdgsdghs";
  printf("strchr(Elysffdgsdghs,d): %d\n",strchr(chr, 100));
  printf("elychr(Elysffdgsdghs,d): %d\n",elychr(chr, 100));
  printf("strchr(Elysffdgsdghs,e): %d\n",strchr(chr, 101));
  printf("elychr(Elysffdgsdghs,e): %d\n\n",elychr(chr, 101));

  char big[20] = "Elysffdgsdghs";
  char small[4] = "dg";
  char small2[4] = "ely";
  printf("strstr(Elysffdhgsdghs,dg): %d\n",strstr(big, small));
  printf("elystr(Elysffdhgsdghs,dg): %d\n",elystr(big, small));
  printf("strstr(Elysffdhgsdghs,ely): %d\n",strstr(big, small2));
  printf("elystr(Elysffdhgsdghs,ely): %d\n",elystr(big, small2));
  return 0;
}
