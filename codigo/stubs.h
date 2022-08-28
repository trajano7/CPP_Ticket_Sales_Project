#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <iostream>
#include <string>
#include "curses.h"
#include "interfaces.h"

class stubISautenticacao:public ISautenticacao {
 private:

    std::string TRIGGER_FALHA;
    std::string TRIGGER_ERRO;

 public:

    stubISautenticacao() {
      TRIGGER_FALHA = "011.111.111-03";
      TRIGGER_ERRO = "021.111.111-20";
    }

    bool autenticar(_CPF, _senha) throw(runtime_error);

};

class stubISusuario: public ISusuario {

    //GATILHO DE FALHA PARA O CADASTRAMENTO: CPF JA CADASTRADO
    std::string TRIGGER_FALHA;
    //GATILHO DE FALHA PARA O CADASTRAMENTO: CARTAO JA CADASTRADO
    std::string TRIGGER_FALHA2;

 public:

    stubISusuario() {
      TRIGGER_FALHA = "011.111.111-03";
      TRIGGER_FALHA2 = "4800313792273261";
    }

    int cadastrar(_usuario, _cartao) throw(runtime_error);
    bool excluir(_CPF) throw(runtime_error);
    void pesquisarDados(_CPF, _usuario*, _cartao*);

};


class stubISeventos: public ISeventos {

    string TRIGGER_FALHA;

 public:

     stubISeventos() {
       TRIGGER_FALHA = "Whiterun";
     }

    bool pesquisarEventos(_data, _data, _cidade, _estado, list<_evento>*, list<_apresentacao>*) throw(runtime_error); //RETORNA UM PONTEIRO PARA UMA LISTA COM TODOS EVENTOS QUE SE ENQUADRAM NAS DEFINICOES
    bool cadastrar(_evento, _apresentacao, _CPF, int) throw(runtime_error); //CADASTRAR EVENTO
    bool excluirEvento(_codigoDeEvento) throw(runtime_error); //DESCADASTRA EVENTO
    bool pesquisarMeuEvento(_codigoDeEvento, _evento*, list<_apresentacao>*) throw(runtime_error); //MOSTRA INFORMACOES SOBRE O EVENTO DO USUARIO
    bool alterar(_evento, _apresentacao, _codigoDeApresentacao, _codigoDeEvento, int) throw(runtime_error);

};

class stubISvendas: public ISvendas {

 public:

    bool comprar(_CPF CPF, _codigoDeApresentacao, int*) throw(runtime_error);

};

#endif // STUBS_H_INCLUDED
