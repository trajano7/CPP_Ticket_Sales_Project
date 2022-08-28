#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED

#include "entidades.h"
#include <list>

class containerUsuario {
 private:

    list<_usuario> container;

 public:

    bool incluir(_usuario);
    bool pesquisar(_usuario* );
    bool excluir(_CPF);

};

class containerCartao {
 private:

    list<_cartao> container;

 public:

    bool incluir(_cartao);
    bool excluir(_cartao);
    bool pesquisar(_cartao* );
    bool pesquisarPorCPF(_cartao*, _CPF);

};

class containerEventos {
 private:

    list<_evento> container;

 public:

    bool incluir(_evento);
    bool excluir(_evento);
    bool pesquisar(_evento* );
    int qntdEventos(_CPF);
    bool editar(_codigoDeEvento, _evento);

};

class containerApresentacao {
 private:

    list<_apresentacao> container;

 public:

    bool incluir(_apresentacao);
    bool excluir(_apresentacao);
    bool pesquisar(_apresentacao* apresentacao);
    bool pesquisarFiltros(_data, _data, _cidade, _estado, list<_apresentacao>*);
    bool pesquisar2(_codigoDeEvento, list<_apresentacao>*); //PESQUISA APRESENTACOES A PARTIR DE UM CODIGO DE EVENTO
    bool editar(_codigoDeApresentacao, _apresentacao);
    bool editarCodEvento(_codigoDeEvento, _codigoDeEvento);
    bool disponibilidade(_codigoDeApresentacao, int*, _CPF);

};

class containerIngressos {
 private:

    list<_ingresso> container;
    bool listaVazia;
    string maiorCod;

 public:

    containerIngressos() {
      listaVazia = true;
      maiorCod = "00000";
    }

    bool gerarIngresso(_CPF, _codigoDeApresentacao, int);
    bool incluir(_ingresso);


};




#endif // CONTAINER_H_INCLUDED
