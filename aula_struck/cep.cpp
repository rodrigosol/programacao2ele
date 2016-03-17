/*
SEGUNDA PRATICA
O Programa abaixo de busca de CEP deve ser modificado 
para apresentar também o bairro no resultado da pesquisa. Os bairros estão no arquivo bairros.csv.

O campo de indice 5 (sexto campo) da tabela de ceps contem o id do bairro.

Você deve:
- Criar uma estrutura para representar o bairro;

- Implementar uma nova funcao para leitura do arquivo de cep;

- Modificar a estrutura de cep para conter o bairro;

- E mostrar quando o cep for encontrado o nome do bairro;


*/

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
struct CEP{
  string codigo;
  string rua;
  Cidade cidade;
};

void imprimeNome(Cidade c){
  cout << c.nome << " - " << c.estado.sigla << endl;
}

Estado buscaEstado(vector<Estado> estados, int id){
  Estado e;
  
  for(vector<Estado>::iterator it = estados.begin();
    it != estados.end(); ++it){
      if(it->id == id){
        e.id = it->id;
        e.nome = it->nome;
        e.sigla = it->sigla;
        break;
      }
    }
  
  return e;
}

Cidade buscaCidade(vector<Cidade> cidades, int id){
  Cidade c;
  
  for(vector<Cidade>::iterator it = cidades.begin();
    it != cidades.end(); ++it){
      if(it->id == id){
        c.id = it->id;
        c.nome = it->nome;
        c.estado = it->estado;
        break;
      }
    }
  
  return c;
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

vector<Cidade> lerArquivoCidades(vector<Estado> estados){
  vector<Cidade> cidades;
  string linha;
  
  ifstream tabelaCidades("cidades.csv");
  if(tabelaCidades.is_open()){
    while(getline(tabelaCidades,linha)){
      vector<string> campos = split(linha,',');
      Cidade c;
      c.id = stoi(campos[0]);
      c.nome = campos[1];
      c.estado = buscaEstado(estados,stoi(campos[4]));
      cidades.push_back(c);
    }
    
    
  }else{
    cout << "Arquivo nao encontrado";
  }
  return cidades;
  
}

vector<CEP> lerArquivoCEP(vector<Cidade> cidades){
  vector<CEP> ceps;
  string linha;
  
  ifstream tabelaCEP("enderecos.csv");
  if(tabelaCEP.is_open()){
    while(getline(tabelaCEP,linha)){
      vector<string> campos = split(linha,',');
      CEP c;
      c.codigo = campos[7];
      c.rua = campos[4];
      c.cidade = buscaCidade(cidades,stoi(campos[2]));
      ceps.push_back(c);
    }
    
    
  }else{
    cout << "Arquivo nao encontrado";
  }
  return ceps;
  
}
int main(){
  vector<Estado> estados = lerArquivoEstados();
  vector<Cidade> cidades = lerArquivoCidades(estados);
  vector<CEP> ceps = lerArquivoCEP(cidades);
  string cep;
  
  while(true){
  cout << "Digite o CEP:";
  cin >> cep;
  
  for(vector<CEP>::iterator it = ceps.begin();
   it != ceps.end(); ++it){
     if(it->codigo == cep){
       cout << "CEP ENCONTRADO!" << endl;
       cout << "CEP:" << it->codigo << endl;
       cout << "RUA:" << it->rua << endl;
       cout << "CIDADE:" << it->cidade.nome << endl;
       cout << "ESTADO:" << it->cidade.estado.sigla << endl;
     }
   }
 }
  
}











