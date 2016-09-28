#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char s[]){
  int i = 0;
  while(s[i]){
    i++;
  }
  return i;
}
