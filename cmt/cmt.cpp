#include <iostream>
#include <list>

using namespace std;

class Contato{
  private:
    string numero;
    string nome;
    int id;
    int generateID()
    {
        static int s_id = 0;
        return ++s_id;
    }
  public:
    Contato(string nome,string ){
      this->numero = numero;
      this->nome = nome;
      this->id = generateID();
    }
    string getNumero(){
      return this->numero;
    };
    string getNome(){
      return this->nome;
    }
    int getId(){
      return this->id;
    }
};

class Agenda{
  private:
    list<Contato> contatos;
  public:
    
    int salvar(Contato contato){
      contatos.push_back(contato);
    }
    
    bool atualizar(Contato contato){
      for (std::list<Contato>::iterator it=contatos.begin(); it != contatos.end(); ++it){
        if(it->getId() == contato.getId()){
          contatos.erase(it);
          contatos.push_back(contato);
          return true;
        }
      }
      return false;
    }

    bool remover(int id){
      for (std::list<Contato>::iterator it=contatos.begin(); it != contatos.end(); ++it){
        if(it->getId() == id){
          contatos.erase(it);
          return true;
        }
      }
      return false;
      
    }
    Contato pesquisarPorId(int id){
      for (std::list<Contato>::iterator it=contatos.begin(); it != contatos.end(); ++it){
        if(it->getId() == id){
          return *it;
        }
      }
      Contato c("","");
      return c;
      
    }
    
    std::list<Contato> pesquisarPorNome(string nome){
        list<Contato> encontrados;
        for (std::list<Contato>::iterator it=contatos.begin(); it != contatos.end(); ++it){
          if(it->getNome().substr(0, nome.size()) == nome) {
            encontrados.push_back(*it);
          }
        }
        return encontrados;
    }
};

class Discador{
  public:
    int ligar(Contato contato);
    int ligar(string telefone);
    void desligar();
};

class Central{
  public:
    int conectar(string origem, string destino);
    int desconectar(string solicitante);
    void registrarTelefone(string numero);
    void desregistrarTelefone(string numero);
    void listarConexoes();
  
};

class Telefone{
  public:
    Telefone(string numero);
    Discador getDiscador();
    Agenda getAgenda();
  
};



int main(){
  
  Contato c1("Rodrigo","1234");
  Contato c2("Rodrigo Sol","12345");  
  Agenda agenda;
  agenda.salvar(c1);
  agenda.salvar(c2);
  cout << agenda.pesquisarPorId(1).getNome();  
};

