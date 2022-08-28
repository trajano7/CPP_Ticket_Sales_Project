#ifndef COMANDOSAPRESENTACAO_H_INCLUDED
#define COMANDOSAPRESENTACAO_H_INCLUDED

#include "interfaces.h"

//CLASSES COMANDO DO MODULO DE USUARIO
class cmdCadastrar {

    static const int cadastroSucesso = 0;
    //CONSTANTE PARA REPRESENTAR UM ERRO DE CPF JA CADASTRADO
    static const int CPFcadastrado = 1;
    //CONSTANTE PARA REPRESENTAR UM ERRO DE CARTAO JA CADASTRADO
    static const int cartaoCadastrado = 2;

 public:

    int executar(ISusuario* );

};

class cmdExcluir {
 private:

   static const int contaExcluida = 0;
   static const int ExclusaoCancelada = 1;
   static const int ExclusaoNaoPermitida = 2;

 public:

    int executar(ISusuario* , _CPF);

};

class cmdMeusDados {
 public:

    int executar(ISusuario* ,_CPF);

};


//CLASSES COMANDO DO MODULO DE EVENTOS
class cmdPesquisarEventos {
 public:

    int executar(ISeventos* ,_CPF);

};

class cmdCadastrarEvento {
 public:

    bool executar(ISeventos*,_CPF);

};

class cmdEditarEvento {
 public:

    int executar(ISeventos*,_CPF);

};

class cmdDadosDeVenda {
 public:

    bool executar(ISeventos*,_CPF);

};

class cmdExcluirEvento {
 public:

    int executar(ISeventos*,_CPF);

};



#endif // COMANDOSAPRESENTACAO_H_INCLUDED
