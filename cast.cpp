#include <iostream>

using namespace std;

int main(){
  int a = 15;
  int *b;
  long c;
  b = &a;
  
  c = (long) b;
  
  cout << "Valor de A:" << a << endl;
  cout << "Endereco de A:" << &a << endl;  
  cout << "Valor de B:" << b << endl;
  cout << "Endereco de B:" << &b << endl;
  cout << "Valor que aponta B:" << *b << endl;
  cout << "Valor de C:" << c << endl;          

}

