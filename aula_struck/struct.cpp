#include <iostream>
#include <string>
// #include <vector>
// #include <sstream>
// #include <iterator>
// #include <fstream>

using namespace std;

struct estado{
  int id;
  string nome;
  string sigla;

};

string formataNomeEstado(estado e){
  return e.nome << "-" << e.sigla;
}

int main(){
  estado mg;
  mg.id = 1;
  mg.nome = "Minas Gerais";
  mg.sigla = "MG";
}
