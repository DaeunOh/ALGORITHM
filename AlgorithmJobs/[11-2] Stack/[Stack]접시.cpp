#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

const int MAX = 36;

int main() {
  char str[MAX];
  scanf("%s", str);
  
  int str_len = strlen(str);
  
  stack<char> s;
  char alpha = 'a';
  bool is_push[1000] = {false, };
  int idx = 0;
  
  for(int i=0; i<str_len; i++) {
    while(s.empty() || s.top() != str[i]) {
      if(alpha >= 'a' + str_len) {
        printf("impossible");
        return 0;
      }
      
      s.push(alpha++);
      is_push[idx++] = true;
    }
    
    s.pop();
    is_push[idx++] = false;
  }
  
  for(int i=0; i<idx; i++) {
    if(is_push[i]) printf("push\n");
    else printf("pop\n");
  }

  return 0;
}