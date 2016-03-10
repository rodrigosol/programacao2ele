#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <fstream>

using namespace std;

struct estado {
  int id;
  string nome;
  string sigla;
} ;

struct cidade {
  int id;
  string nome;
  estado estado;
} ;

struct endereco{
  string cep;
  string nome;
  cidade cidade;
  int cidade_id;
};



std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::vector<estado> lerEstados(){
  std::vector<estado> estados;
  string line;
  ifstream tabelaEstados ("estados.csv");
  
  if (tabelaEstados.is_open())
  {
    while ( getline (tabelaEstados,line) )
    {
      std::vector<std::string> campos = split(line,',');
      estado estadoAtual;
      estadoAtual.id = stoi(campos[0]);
      estadoAtual.nome = campos[1];
      estadoAtual.sigla = campos[2];
      estados.push_back(estadoAtual);
    }
    tabelaEstados.close();
  }else{ 
    cout << "Unable to open file";
  }
  return estados;
}

std::vector<cidade> lerCidades(std::vector<estado> estados){
  std::vector<cidade> cidades;
  string line;
  ifstream tabelaCidades ("cidades.csv");
  if (tabelaCidades.is_open())
  {
    while ( getline (tabelaCidades,line) )
    {
      std::vector<std::string> campos = split(line,',');
      cidade cidadeAtual;
      cidadeAtual.id = stoi(campos[0]);
      cidadeAtual.nome = campos[1];
      cidadeAtual.estado =  estados[stoi(campos[4]) - 1];
      cidades.push_back(cidadeAtual);
    }
    tabelaCidades.close();
  }else{
    cout << "Unable to open file";
  }
  return cidades;
}

std::vector<endereco> lerEnderecos(std::vector<cidade> cidades){
  std::vector<endereco> enderecos;
  string line;
  ifstream tabelaEnderecos ("enderecos.csv");
  
  if (tabelaEnderecos.is_open())
  {
    while ( getline (tabelaEnderecos,line) )
    {
      std::vector<std::string> campos = split(line,',');
      endereco enderecoAtual;
      enderecoAtual.cidade = cidades[stoi(campos[2]) - 1];
      enderecoAtual.cidade_id = stoi(campos[2]);      

      enderecoAtual.nome =  campos[4];
      enderecoAtual.cep = campos[7];
      enderecos.push_back(enderecoAtual);
    }
    tabelaEnderecos.close();
  }else{ 
    cout << "Unable to open file";
  }
  return enderecos;
}

int main(){
  std::vector<estado> estados = lerEstados();

  std::vector<cidade> cidades = lerCidades(estados);
  int i = 0;
  for (std::vector<cidade>::iterator it = cidades.begin() ; it != cidades.end(); ++it){
    
    cout << it->id << " " << it->nome << " " << i << endl;
    i++;
  }
    
  std::vector<endereco> enderecos = lerEnderecos(cidades);  
  
  string cep; 
  
  cout << "digite o cep:";
  cin >> cep;
  
  for (std::vector<endereco>::iterator it = enderecos.begin() ; it != enderecos.end(); ++it){
    if(it->cep == cep){
      std::cout << "CEP:" << it->cep  << ", ENDERECO:" << it->nome << ", CIDADE:" << it->cidade.nome  << "-" << it->cidade_id << endl;
      break;
    }
  }
}
