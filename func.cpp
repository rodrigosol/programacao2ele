#include <iostream>
extern int c = 1; 
int f(){
  c = 1;
  int a = 2; 
  int b = 2;
  {
    int x = 0;
    x = 1;
  }
  return 0;
}

int main(){
  
  f();
}

