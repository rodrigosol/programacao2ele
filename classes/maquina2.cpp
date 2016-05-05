#include <iostream>

/*
 * Você deve adicionar a capacidade da máquina de reabastecer o reservatório;
 * Ao preparar um cafe a máquina grava no chip que a capsula foi utilizada;
 * Uma capsula não poderar ser utilizada mais de uma vez
 */


using namespace std;

class Capsula{
  public:
    Capsula(string tipo, int quantidadeAgua, int quantidadeAcucar, float pressao);
    int getQuantidadeAgua();
    int getQuantidadeAcucar();
    string getTipo();    
  private:
    string tipo;
    int quantidadeAgua;
    int quantidadeAcucar;
    float pressao;
};

Capsula::Capsula(string tipo, int quantidadeAgua, int quantidadeAcucar, float pressao){
  this->tipo = tipo;
  this->quantidadeAgua = quantidadeAgua;
  this->quantidadeAcucar = quantidadeAcucar;
  this->pressao = pressao;
}

int Capsula::getQuantidadeAgua(){
  return this->quantidadeAgua;
}

int Capsula::getQuantidadeAcucar(){
  return this->quantidadeAcucar;
}
string Capsula::getTipo(){
  return this->tipo;
}

class Maquina{
  public:
    Maquina();
    void ligar();
    void desligar();
    void preparar(Capsula capsula);
    
    
  private:
    bool ligada;
    int reservatorioAgua;
    int reservatorioAcucar;
};


Maquina::Maquina(){
  this->reservatorioAgua = 200;
  this->reservatorioAcucar = 40;
}

void Maquina::ligar(){
  this->ligada = true;
  cout << "Maquina ligada!" << endl; 
}

void Maquina::desligar(){
  this->ligada = false;
  cout << "Maquina desligada!" << endl; 
}

void Maquina::preparar(Capsula capsula){
  if(!this->ligada){
    cout << "Ligue a maquina!" << endl;
  }else{
    if(this->reservatorioAgua - capsula.getQuantidadeAgua() < 0){
      cout << "Agua insuficiente. Reabasteca" <<  endl;
    }else if(this->reservatorioAcucar - capsula.getQuantidadeAcucar() < 0){
      cout << "Acucar insuficiente. Reabasteca" <<  endl;
    }else{
      this->reservatorioAgua -= capsula.getQuantidadeAgua();
      this->reservatorioAcucar -= capsula.getQuantidadeAcucar();
      cout << "Preparando o seu " << capsula.getTipo() << endl;
      cout << "Aguarde..."  << endl;
      cout << "Pronto..."  << endl;      
    }
  }
}

int main(){

  Capsula expresso("Expresso",80,5,20.0); 
  Capsula cafezinho("Cafezinho",50,15,5.0);
  
  Maquina maquina;
  maquina.preparar(expresso);
  maquina.ligar();
  maquina.preparar(expresso);
  maquina.preparar(expresso);
  maquina.preparar(expresso);
  maquina.preparar(expresso);
  maquina.preparar(expresso);
  maquina.preparar(expresso);          
  maquina.desligar();
  
}

