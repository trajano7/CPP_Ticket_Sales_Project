#ifndef CONTROLEAUTENTICACAO_H_INCLUDED
#define CONTROLEAUTENTICACAO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//CLASSE CONTROLADORA CENTRAL
//CLASSE DO MODULO RESPONSAVEL POR MOSTRAR OS MENUS INICIAIS E GERAIS
class cntrlIAcentral {
 private:

    const static int LOGIN = 48;
    const static int CADASTRAR = 49;
    const static int PESQUISAR = 50;
    const static int COMPRAR = 51;
    const static int MENU_USUARIO = 48;
    const static int MENU_EVENTOS = 49;
    const static int SAIR = 52;

    IAautenticacao *cntrlaIAautenticacao;
    IAusuario *cntrlaIAusuario;
    IAeventos *cntrlaIAeventos;
    IAvendas *cntrlaIAvendas;

 public:

    void executar();

    void setCntrlIAautenticacao(IAautenticacao* );
    void setCntrlIAusuario(IAusuario* );
    void setCntrlIAeventos(IAeventos* );
    void setCntrlIAvendas(IAvendas* );

};

void inline cntrlIAcentral::setCntrlIAautenticacao(IAautenticacao *cntrlaIAautenticacao) {
    this->cntrlaIAautenticacao = cntrlaIAautenticacao;
}

void inline cntrlIAcentral::setCntrlIAusuario(IAusuario *cntrlaIAusuario) {
    this->cntrlaIAusuario = cntrlaIAusuario;
}

void inline cntrlIAcentral::setCntrlIAeventos(IAeventos *cntrlaIAeventos) {
    this->cntrlaIAeventos = cntrlaIAeventos;
}

void inline cntrlIAcentral::setCntrlIAvendas(IAvendas *cntrlaIAvendas) {
    this->cntrlaIAvendas = cntrlaIAvendas;
}


//CLASSE CONTROLADORA DE AUTENTICACAO
class cntrlIAautenticacao:public IAautenticacao {
 private:

    ISautenticacao* cntrlISautenticacao;

 public:

    bool autenticar(_CPF*);

    void setCntrlISautenticacao(ISautenticacao *);

};

void inline cntrlIAautenticacao::setCntrlISautenticacao(ISautenticacao *cntrlISautenticacao) {
        this->cntrlISautenticacao = cntrlISautenticacao;
}


//CLASSE CONTROLADORA DE USUARIO
class cntrlIAusuario: public IAusuario {
 private:

    const static int RETORNAR = 48;
    const static int EXCLUIR = 49;
    const static int MEUSDADOS = 50;

    ISusuario* cntrlISusuario;

 public:

    //bool logado indica se o modulo de usuario esta sendo chamado em um sistema logado ou nao
    bool executarUsuario(_CPF, bool);

    void setCntrlISusuario(ISusuario *);

};

void inline cntrlIAusuario::setCntrlISusuario(ISusuario *cntrlISusuario) {
        this->cntrlISusuario = cntrlISusuario;
}


//CLASSE CONTROLADORA DE EVENTOS
class cntrlIAeventos: public IAeventos {
 private:

    const static int RETORNAR = 48;
    const static int PESQUISAR_EVENTO = 49;
    const static int CADASTRAR_EVENTO = 50;
    const static int EDITAR_EVENTO = 51;
    const static int MEU_EVENTO = 52;
    const static int EXCLUIR_EVENTO = 53;

    ISeventos *cntrlISeventos;

 public:

    bool executarEventos(_CPF, bool);

    void setCntrlISeventos(ISeventos* );

};

void inline cntrlIAeventos::setCntrlISeventos(ISeventos *cntrlISeventos) {
        this->cntrlISeventos = cntrlISeventos;
}


//CLASSE CONTROLADORA DE VENDAS
class cntrlIAvendas: public IAvendas {
 private:

    ISvendas *cntrlISvendas;

 public:

    int comprar(_CPF);

    void setCntrlISvendas(ISvendas* );

};

void inline cntrlIAvendas::setCntrlISvendas(ISvendas *cntrlISvendas) {
     this->cntrlISvendas = cntrlISvendas;
}



#endif // CONTROLEAUTENTICACAO_H_INCLUDED
