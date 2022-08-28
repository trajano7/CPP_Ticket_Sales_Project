#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

//GLOSSARIO BASICO
//IA ~ INTERFACE DE APRESENTACAO
//IS ~ INTERFACE DE SERVICO

#include "dominios.h"
#include "entidades.h"
#include "auxiliar.h"
#include "curses.h"
#include "container.h"
#include <list>

using namespace std;

class ISautenticacao;
class ISusuario;
class ISeventos;
class ISvendas;

//Classes de interface da camada de apresentacao

class IAautenticacao {
 public:

    virtual bool autenticar(_CPF*) = 0;

    virtual void setCntrlISautenticacao(ISautenticacao *) = 0;

};

class IAusuario {
 public:

    virtual bool executarUsuario(_CPF, bool) = 0;

    virtual void setCntrlISusuario(ISusuario *) = 0;

};

class IAeventos {
 public:

    virtual bool executarEventos(_CPF, bool) = 0;

    virtual void setCntrlISeventos(ISeventos *) = 0;

};

class IAvendas {
 public:

    virtual int comprar(_CPF)  = 0;

    virtual void setCntrlISvendas(ISvendas *) = 0;

};

//Classes de interface da camada de servico

class ISautenticacao {
 public:

    virtual bool autenticar(_CPF, _senha) = 0;

};

class ISusuario {
 public:

    virtual int cadastrar(_usuario, _cartao)  = 0;
    virtual void pesquisarDados(_CPF, _usuario*, _cartao*) = 0;
    virtual bool excluir(_CPF) = 0;

};

class ISeventos {
  public:

    virtual bool pesquisarEventos(_data, _data, _cidade, _estado, list<_evento>*, list<_apresentacao>*) = 0; //RETORNA UM PONTEIRO PARA UMA LISTA COM TODOS EVENTOS QUE SE ENQUADRAM NAS DEFINICOES
    virtual bool cadastrar(_evento, _apresentacao, _CPF, int) = 0; //CADASTRAR EVENTO
    virtual bool excluirEvento(_codigoDeEvento) = 0; //DESCADASTRA EVENTO
    virtual bool pesquisarMeuEvento(_codigoDeEvento, _evento*, list<_apresentacao>*) = 0; //MOSTRA INFORMACOES SOBRE O EVENTO DO USUARIO
    virtual bool alterar(_evento, _apresentacao, _codigoDeApresentacao, _codigoDeEvento, int) = 0;

};

class ISvendas {
 public:

    virtual bool comprar(_CPF, _codigoDeApresentacao, int*) = 0;

};



#endif // INTERFACES_H_INCLUDED
