#include <iostream>
#include <string>

using namespace std;

const int SOMA = 1;
const int SUBTRACAO = 2;
const int MULTIPLICAO3 = 6;
const int MEDIA = 11;


int soma(int a, int b){
  return a + b;
}

int subtracao(int a, int b){
  return a - b;
}

float media(int numeros[], int tamanho){
  int soma = 0;
  for(int i =0; i < tamanho; i++){
    soma = soma + numeros[i];
  }
  return soma / tamanho;
}

void imprimeResultadoBinario(int a, int b,int resultado, 
                             char operador){
  cout << a << " " << operador 
       << " " << b << " = " << resultado << endl;
}

void imprimeResultadoDeN(float resultado, 
                             string operador){
  cout << "O resultado do(a) " << operador << " eh:" << resultado << endl;
}


int menu(){
//  system("clear");
  
  cout << "MENU" << endl;
  cout << "1  - SOMA" << endl;
  cout << "2  - SUBTRACAO" << endl;
  cout << "3  - DIVISAO" << endl;
  cout << "4  - MULTIPLICACAO  1" << endl;
  cout << "5  - MULTIPLICACAO  2" << endl;
  cout << "6  - MULTIPLICACAO  3"<< endl;
  cout << "7  - RAIZ QUADRAD A"<< endl;
  cout << "8  - FATORIAL" << endl;
  cout << "9  - FIBONNACI" << endl;
  cout << "10 - REDUCAO E M SOMA"<< endl;
  cout << "11 - MEDIA" << endl;
  cout << "12 - MAIOR" << endl;
  cout << "13 - MENOR"<< endl;
  cout << "0  - SAIR"<< endl;
  
  int acao = 0;
  cin >> acao;  
  return acao;
}

void lerDoisNumeros(int &a, int &b){
  cout << "INFORME O PRIMEIRO NUMERO:";
  cin >> a;

  cout << "INFORME O SEGUNDO NUMERO:";
  cin >> b;
  
}

void lerNNumeros(int numeros[], int tamanho){
  for(int i = 0;  i < tamanho; i++){
    int numeroInformado;
    cout << "NUMERO " << (i + 1) << ":";
    cin >> numeroInformado;
    numeros[i] = numeroInformado;
  }
}

int lerQuantidade(){
    int quantidade = 0;
    cout << "INFORME QUANTOS OPERANDOS:";
    cin >> quantidade;
    return quantidade;
}

int main(){
  int acao;
  do{
    acao = menu();
    
    if(acao >= SOMA && acao <= MULTIPLICAO3){
      int a, b, resultado;
      lerDoisNumeros(a,b);
      switch(acao){
        case SOMA:
          resultado = soma(a,b);
          imprimeResultadoBinario(a,b,resultado,'+');
          break;
        case SUBTRACAO:
          resultado = subtracao(a,b);
          imprimeResultadoBinario(a,b,resultado,'-');
          break;
      }
    }else if(acao == MEDIA){
      int tamanho = lerQuantidade();
      int numeros[tamanho];
      lerNNumeros(numeros,tamanho);
      float resultado = media(numeros,tamanho);
      imprimeResultadoDeN(resultado,"media");
    }
  }while(acao > 0);
  
}