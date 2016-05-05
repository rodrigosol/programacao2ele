#include <iostream>

using namespace std;

class Capsula{
  private:
    string nome;
    int quantidadeAgua;
    int quantidadeAcucar;
    float pressao;
    
  public:
    Capsula(string nome, int quantidadeAgua, int quantidadeAcucar, float pressao);
    Capsula();
    string getNome();
    int getQuantidadeAgua();
    int getQuantidadeAcucar();
    float getPressao();
};


Capsula::Capsula(string nome, int quantidadeAgua, int quantidadeAcucar, float pressao){
  this->nome = nome;
  this->quantidadeAgua = quantidadeAgua;
  this->quantidadeAcucar = quantidadeAcucar;
  this->pressao = pressao;
}

string Capsula::getNome(){
  return this->nome;
}

int Capsula::getQuantidadeAgua(){
  return this->quantidadeAgua;
}

int Capsula::getQuantidadeAcucar(){
  return this->quantidadeAcucar;
}

float Capsula::getPressao(){
  return this->pressao;
}

// class Expresso : Capsula{
//   public:
//     Expresso() : Capsula(string,int,int,float);
// };

// Expresso::Expresso(){
//   Capsula("Expresso",80,5,20);
// }

class Maquina{

  private:
    int reservatorioAgua;
    int reservatorioAcucar;
    bool ligada;
    
  public:
    Maquina();
    void ligarDesligar();
    void preparar(Capsula capsula);
};

Maquina::Maquina(){
  this->reservatorioAgua = 200;
  this->reservatorioAcucar = 5;
}

void Maquina::preparar(Capsula capsula){
  if(!this->ligada){
    cout << "Nao eh possivel fazer cafe com a maquina desligada" << endl;
  }else{
    if(this->reservatorioAgua - capsula.getQuantidadeAgua() < 0){
      cout << "Agua insuficiente para fazer essa preparacao" << endl;
    }else if(this->reservatorioAcucar - capsula.getQuantidadeAcucar() < 0){
      cout << "Acucar insuficiente para fazer essa preparacao" << endl;
    }else{
      this->reservatorioAgua -= capsula.getQuantidadeAgua();
      this->reservatorioAcucar -= capsula.getQuantidadeAcucar();
      cout << "Preparando um delicioso " << capsula.getNome() << endl;
      cout << "Aguarde..." << endl;
      cout << "Pronto!" << endl;
    }
  }
}

void Maquina::ligarDesligar(){
  this->ligada = !this->ligada;
}


int main(){
  Capsula c1("Expresso",10,1,22);
  Maquina m1;
  m1.preparar(c1);
  m1.ligarDesligar();
  m1.preparar(c1);
  m1.preparar(c1);
  m1.preparar(c1);
  m1.preparar(c1);      
  
}

