#include <stdio.h>
#include <string.h>

const int MAX = 1010;

int main() {
  char str[MAX];
  fgets(str, MAX, stdin);
  
  int strLen = strlen(str);
  
  for(int i=0; i<strLen; i++) {
    if(str[i] >= 97 && str[i] <= 122) printf("%c", str[i] - 32);
    else if(str[i] >= 65 && str[i] <= 90) printf("%c", str[i] + 32);
    else printf("%c", str[i]);
  }
  
  return 0;
}