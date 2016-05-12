//****************************************
//* Tarefa - Valor 3 Pontos
//* Você deve remover os registros duplicados na listagem 
//* de conexoes ativas.
//* Sugestão:
//* Remodele as estruturas de dados para nao registrar
//* chaves duplicadas (2 pontos extra),
//* ou filtre na hora de imprimir a lista 
//* Entrega SGA - 22/05 ate às 23:59

// 

#include <iostream>
#include <list>
#include <map>
#include <ctime>

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


class Ligacao{
  
  public:
    int origem;
    int destino;
    time_t inicio;
    
    Ligacao(int origem,int destino){
      this->origem = origem;
      this->destino = destino;
      time(&inicio);
    }
    
    double tempoDecorrido(){
      time_t agora;
      time(&agora);
      return difftime(agora,inicio);
    }
    
    void status(){
      cout << "Origem:" << this->origem << ", Destino:" << this->destino << ", Tempo:" << tempoDecorrido() << "s" << endl;
    }
    
    
};

class Central{
  private:
  
  map<int,bool> telefones;
  map<int,Ligacao> ligacoes;

  public:
    // 0 - Se a ligacao for efetuado com sucesso
    // 1 - Se o telefone estiver ocupado
    // 2 - se o telefone estiver ligado
    int conectar(int origem, int destino){
      if(telefones.find(destino) == telefones.end()){
        cout << "O telefone " << destino << " nao esta ligado" << endl;
        return 2;
      }
      if(ligacoes.find(destino) != ligacoes.end()){
        cout << "O numero " << destino << " ja esta em outra ligacao com o numero ..." << endl;
        return 1;
      }
      
      Ligacao l(origem,destino);
      ligacoes.insert(pair<int,Ligacao>(origem,l));
      ligacoes.insert(pair<int,Ligacao>(destino,l));

      cout << "A ligacao entre " << origem << " e " << destino << " foi completada com sucesso!"<< endl;
      
    }
    
    int desconectar(int solicitante); //4
    
    void registrarTelefone(int numero){
      if(telefones.find(numero) != telefones.end()){
        cout << "Numero " << numero << " ja registrado" << endl;
      }else{
        telefones.insert(pair<int,bool>(numero,true));  
        cout << "Numero " << numero << " registrado com sucesso!" << endl;
      }
      
      
    }
    void desregistrarTelefone(int numero){
      telefones.erase(numero);
      cout << "O registro do telefone  " << numero << " foi cancelado com sucesso!" << endl;
      
    }
    void listarConexoes(){
      //system("clear");
      cout << "REGISTRO DAS LIGACOES" << endl;
      cout << "Conexoes Ativas:" << ligacoes.size() << endl;
      for(map<int,Ligacao>::iterator it = ligacoes.begin(); it != ligacoes.end(); ++it){
        it->second.status();
      }
    }

};

int main(){
  Central minhaCentral;
  minhaCentral.listarConexoes();
  minhaCentral.registrarTelefone(123);
  minhaCentral.registrarTelefone(456);
  minhaCentral.registrarTelefone(789);
  minhaCentral.registrarTelefone(190);  
  minhaCentral.conectar(123,456);
  minhaCentral.conectar(789,456);
  minhaCentral.conectar(789,123);

  int x,y;

  cin >> x;
  minhaCentral.listarConexoes();
  minhaCentral.conectar(789,190); 
  
  cin >> y;
  minhaCentral.listarConexoes();  

  cin >> y;
  minhaCentral.listarConexoes();  
  // Agenda minhaAgenda;
  //
  // Contato jose("J",12345);
  // Contato joao("Joao de Souza",54321);
  // Contato filho("Joao de Souza Filho",64321);
  //
  // minhaAgenda.salvar(jose);
  // minhaAgenda.salvar(joao);
  // minhaAgenda.salvar(filho);
  //
  //
  // list<Contato> resultado = minhaAgenda.buscarPorNome("Joao de Souza F");
  //
  // for(list<Contato>::iterator it = resultado.begin(); it != resultado.end(); ++it){
  //   it->imprimir();
  // }
}