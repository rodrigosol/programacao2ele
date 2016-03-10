#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <fstream>

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

struct Estado{
  int id;
  string nome;
  string sigla;
};
struct Cidade{
  int id;
  string nome;
  Estado estado;
};

void imprimeNome(Cidade c){
  cout << c.nome << " - " << c.estado.sigla << endl;
}
/**
*Essa funcao le um arquivo com os dados do estado
* e retornar um vector com os estados lidos
**/
vector<Estado> lerArquivoEstados(){
  //Vai conter cada linha lida durante a leitura do arquivo
  string linha;

  //Declara o vetor de estados que ira armazenar cada estado lido
  vector<Estado> estados;
  
  //Abre um arquivo, informando o nome do arquivo
  //a ser aberto
  ifstream tabelaEstados("estados.csv");
  //Testa se o arquivo foi encontra e esta pronto para ser
  //usado
  if(tabelaEstados.is_open()){
    //O arquivo esta aberto
    
    
    //Agora eu vou ler cada linha do arquivo
    while(getline(tabelaEstados,linha)){
      //Aqui dentro, a variavel linha vai conter a linha lida
      
      //Coloca no vetor de string campos, cada um dos campos da linha que 
      //foram separados por ","
      vector<string> campos = split(linha,',');
      Estado e;
      e.id = stoi(campos[0]);
      e.nome = campos[1];
      e.sigla = campos[2];
      
      //Coloca o estado lido no final do vetor
      estados.push_back(e);
    }
  }else{
    //O arquivo nao esta aberto ou nao foi encontrado
    cout << "Arquivo de estados nao encontrado";
  }
  
  return estados;
  
}


int main(){
  vector<Estado> estados = lerArquivoEstados();
  for(vector<Estado>::iterator it = estados.begin(); it != estados.end(); ++it){
    cout << it->nome << " - " << it-> sigla << endl;
  }
  
}











