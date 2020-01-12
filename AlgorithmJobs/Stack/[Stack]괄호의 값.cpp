#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main() {
  char str[40];
  scanf("%s", str);
  
  int str_len = strlen(str);
  
  int res = 0;
  int temp = 1;
  stack<char> s;
  
  for(int i=0; i<str_len; i++) {
    if(str[i] == '(') {
      s.push('(');
      temp *= 2;
    }
    else if(str[i] == '[') {
      s.push('[');
      temp *= 3;
    }
    else if(str[i] == ')' && (s.empty() || s.top() == '[')) {
      printf("0\n");
      return 0;
    }
    else if(str[i] == ']' && (s.empty() || s.top() == '(')) {
      printf("0\n");
      return 0;
    }
    else if(str[i] == ')') {
      if(str[i-1] == '(') res += temp;
      s.pop();
      temp /= 2;
    }
    else if(str[i] == ']') {
      if(str[i-1] == '[') res += temp;
      s.pop();
      temp /= 3;
    }
  }
  
  if(!s.empty()) printf("0\n");
  else printf("%d\n", res);
  
  return 0;
}