#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "interfaces.h"
#include "container.h"

class cntrlISautenticacao: public ISautenticacao {
 private:

   containerUsuario *container;

 public:

   bool autenticar(_CPF, _senha);

   void setContainer(containerUsuario* );

};

void inline cntrlISautenticacao::setContainer(containerUsuario* container) {
   this->container = container;
}

class cntrlISusuario: public ISusuario {
 private:

    containerUsuario *container;
    containerCartao *container2;

 public:

    int cadastrar(_usuario,_cartao);
    void pesquisarDados(_CPF, _usuario*, _cartao*);
    bool excluir(_CPF);

    void setContainerUser(containerUsuario*);
    void setContainerCard(containerCartao*);

};

void inline cntrlISusuario::setContainerUser(containerUsuario* container) {
    this->container = container;
}

void inline cntrlISusuario::setContainerCard(containerCartao* container2) {
    this->container2 = container2;
}

class cntrlISeventos: public ISeventos {
 private:

    containerUsuario *container1;
    containerEventos *container3;
    containerApresentacao *container4;

 public:

    bool pesquisarEventos(_data, _data, _cidade, _estado, list<_evento>*, list<_apresentacao>*); //RETORNA UM PONTEIRO PARA UMA LISTA COM TODOS EVENTOS QUE SE ENQUADRAM NAS DEFINICOES
    bool cadastrar(_evento, _apresentacao, _CPF, int); //CADASTRAR EVENTO
    bool excluirEvento(_codigoDeEvento); //DESCADASTRA EVENTO
    bool pesquisarMeuEvento(_codigoDeEvento, _evento*, list<_apresentacao>*); //MOSTRA INFORMACOES SOBRE O EVENTO DO USUARIO
    bool alterar(_evento, _apresentacao, _codigoDeApresentacao, _codigoDeEvento, int);

    void setContainerUser(containerUsuario*);
    void setContainerEvent(containerEventos*);
    void setContainerApr(containerApresentacao*);


};

void inline cntrlISeventos::setContainerUser(containerUsuario* container1) {
    this->container1 = container1;
}

void inline cntrlISeventos::setContainerEvent(containerEventos* container3) {
    this->container3 = container3;
}

void inline cntrlISeventos::setContainerApr(containerApresentacao* container4) {
    this->container4 = container4;
}

class cntrlISvendas: public ISvendas {
 private:

    containerApresentacao *container4;
    containerIngressos *container5;

 public:

    bool comprar(_CPF, _codigoDeApresentacao, int*);

    void setContainerApr(containerApresentacao*);
    void setContainerIngressos(containerIngressos* );

};

void inline cntrlISvendas::setContainerApr(containerApresentacao* container4) {
    this->container4 = container4;
}

void inline cntrlISvendas::setContainerIngressos(containerIngressos* container5) {
    this->container5= container5;
}

#endif // CONTROLADORASSERVICO_H_INCLUDED
