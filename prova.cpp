
#include <iostream>

using namespace std;
int foo(void x);
int main(){
  int a = 5, b = 10; int *p1, *p2;
  p1 = &a;
  p2 = &b;
  *p1 = *p1*2*(*p2);
  p1 = p2;
  *p1 = 20;
  printf("a = %d\n", a); printf("b = %d\n", b);  
}


//9,8,7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7,8,9,
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
//certo 0,1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1,0,
//9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,

