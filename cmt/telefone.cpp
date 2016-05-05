#include <iostream>
#include <list>

using namespace std;

class Contato{
  private:
    string nome;
    int telefone;
    
  public:
    Contato(string nome, int telefone){
      this->nome = nome;
      this->telefone = telefone;
    }
    
    string getNome(){
      return this->nome;
    }
    int getTelefone(){
      return this->telefone;
    }
    
    void imprimir(){
      cout << "NOME:" << this->nome << "  - TELEFONE:" << this->telefone << endl;
    }
};

class Agenda{
  private:
    list<Contato> contatos; 
   
    bool ehPrefixo(string nome, string prefixo){
      return nome.substr(0,prefixo.size()) == prefixo;
    }
  
  public:
    
    void salvar(Contato novoContato){
      contatos.push_back(novoContato);
    }
    
    void atualizar(Contato contato){
      for(list<Contato>::iterator it = contatos.begin(); it != contatos.end(); ++it){
        if(it->getTelefone() == contato.getTelefone()){
          contatos.erase(it);
          salvar(contato);
          return;
        }
      }  
    }
    
    void remover(Contato contato){
      for(list<Contato>::iterator it = contatos.begin(); it != contatos.end(); ++it){
        if(it->getTelefone() == contato.getTelefone()){
          contatos.erase(it);
          return;
        }
      }  
    }
    Contato buscarPorNumero(int telefone){
      for(list<Contato>::iterator it = contatos.begin(); it != contatos.end(); ++it){
        if(it->getTelefone() == telefone){
          return *it;
        }
      }  
    }
    
    list<Contato> buscarPorNome(string prefixo){
      
      list<Contato> encontrados;
      
      for(list<Contato>::iterator it = contatos.begin(); it != contatos.end(); ++it){
        if(ehPrefixo(it->getNome(),prefixo)){
          encontrados.push_back(*it);
        }
      }
      
      return encontrados;
    }
    
    int quantidadeDeContatos(){
      return contatos.size();
    }
  
};

int main(){
  Agenda minhaAgenda;
  
  Contato jose("J",12345);
  Contato joao("Joao de Souza",54321);
  Contato filho("Joao de Souza Filho",64321);  
  
  minhaAgenda.salvar(jose);
  minhaAgenda.salvar(joao);
  minhaAgenda.salvar(filho);
  
  
  list<Contato> resultado = minhaAgenda.buscarPorNome("Joao de Souza F");
  
  for(list<Contato>::iterator it = resultado.begin(); it != resultado.end(); ++it){
    it->imprimir();
  }
  
}