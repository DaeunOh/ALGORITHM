#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

const int MAX = 60;

int main() {
  char str[MAX];
  scanf("%s", str);
  
  int str_len = strlen(str);
  
  stack<char> s;
  for(int i=0; i<str_len; i++) {
    if(str[i] == '(') {
      s.push('(');
    }
    else if(str[i] == ')') {
      if(!s.empty()) {
        s.pop();
      }
      else {
        printf("NO\n");
        return 0;
      }
    }
  }
  
  if(!s.empty()) printf("NO\n");
  else printf("YES\n");
  
  return 0;
}