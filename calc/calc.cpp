#include <iostream>
#include <string>
#include "calc.h"


/*
Multiplicacao 1 - A * B;
Multiplicacao 2 - Você não pode usar o operador *
Multiplicacao 3 - você nao pode user o operadro *, nao pode usar for, nao pode usar while, e nao pode usar do whilhe
*/


using namespace std;

int menu(){
  int resposta;
  
  
  cout << "ESCOLHA A OPERACAO" << endl;
  cout << "----------------------" << endl;
  cout << "1  - ADICAO" << endl;  
  cout << "2  - SUBTRACAO" << endl;
  cout << "3  - DIVISAO" << endl;
  cout << "4  - MULTIPLICACAO 1" << endl;
  cout << "5  - MULTIPLICACAO 2" << endl;
  cout << "6  - MULTIPLICACAO 3" << endl;
  cout << "7  - RAIZ QUADRADA" << endl;
  cout << "8  - FATORIAL" << endl;
  cout << "9  - FIBONNACI" << endl;
  cout << "10 - REDUCAO EM SOMA" << endl;
  cout << "11 - MEDIA" << endl;
  cout << "12 - MAIOR" << endl;
  cout << "13 - MENOR" << endl;
  cout << "----------------------" << endl;
  cout << "0  - SAIR" << endl;
  cin >> resposta;
  return resposta;
}

void lerDoisOperandos(int &a, int &b){
  if (system("CLS")){
    system("clear");
  }
  cout << "INFORME O PRIMEIRO OPERANDO:";
  cin >> a;
  cout << "INFORME O SEGUNDO OPERANDO:";
  cin >> b;
}
int lerQuantidade(){
  if (system("CLS")){
    system("clear");
  }
  cout << "QUANTOS OPERANDOS DESEJA INFORMAR:";
  int tamanho = 0;
  cin >> tamanho;
  return tamanho;
}
void lerNOperandos(int operandos[],int quantidade){
  for(int i = 0; i < quantidade; i++){
    cout << (i+1) << " : ";
    cin >> operandos[i];
  }
}

void imprimirResultado(int a, int b, char operacao ,int resultado){
  if (system("CLS")){
    system("clear");
  }
  cout << a << " " << operacao << " " << b << " = " 
       << resultado << endl << endl << endl;
}

void imprimirResultado(string operacao ,int resultado){
  if (system("CLS")){
    system("clear");
  }
  cout << "A " << operacao << " dos numeros inforamados e igual a:"
       << resultado << endl << endl << endl;
}

int soma(int a, int b){
  return a+b;
}

float media(int operandos[], int tamanho){
  int soma = 0;
  for(int i =0; i < tamanho; i++){
    soma+= operandos[i];
  }
  return soma / tamanho;
}

int main(){
  cout << "SUPER CALCULADORA" << endl;
  int acao = 0;
  int a, b;
  int resultado;
  
  do{
    acao = menu();
    switch(acao){
      case ADICAO:
        lerDoisOperandos(a,b);
        resultado = soma(a,b);
        imprimirResultado(a,b,'+',resultado);
        break;
      case MEDIA:
        int tamanho = lerQuantidade();
        int operandos[tamanho];
        lerNOperandos(operandos,tamanho);
        imprimirResultado("media",media(operandos,tamanho));
        break;
    }
  }while(acao > 0);

}
