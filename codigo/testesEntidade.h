#ifndef TESTESENTIDADE_H_INCLUDED
#define TESTESENTIDADE_H_INCLUDED

#include "entidades.h"

class tu_usuario {
 private:

    _usuario usuario;
    _CPF CPF;
    _senha senha;

    int estado;

 public:

    const static int sucesso = 0;
    const static int falha = -1;

    int testeUsuario();

};


class tu_evento {
 private:

    _evento evento;
    _codigoDeEvento codigoDeEvento;
    _nomeDoEvento nomeDoEvento;
    _cidade cidade;
    _estado estado;
    _classeDeEvento classeDeEvento;
    _faixaEtaria faixaEtaria;

    int estadoDoTeste;

 public:

    const static int sucesso = 0;
    const static int falha = -1;

    int testeEvento();

};


//teste de unidade da classe _apresentacao
class tu_apresentacao {
 private:

    _apresentacao apresentacao;
    _codigoDeApresentacao codigoDeApresentacao;
    _data data;
    _horario horario;
    _preco preco;
    _numeroDeSala numeroDeSala;
    _disponibilidade disponibilidade;

    int estado;

 public:

    const static int sucesso = 0;
    const static int falha = -1;

    int testeApresentacao();

};


//teste de unidade da classe _ingresso
class tu_ingresso {
 private:

    _ingresso ingresso;
    _codigoDeIngresso codigoDeIngresso;

    int estado;

 public:

    const static int sucesso = 0;
    const static int falha = -1;

    int testeIngresso();

};


//teste de unidade da classe _cartao
class tu_cartao {
 private:

    _cartao cartao;
    _numeroDeCartao numeroDeCartao;
    _codigoDeSeguranca codigoDeSeguranca;
    _dataDeValidade dataDeValidade;

    int estado;

 public:

    const static int sucesso = 0;
    const static int falha = -1;

    int testeCartao();

};

#endif // TESTESENTIDADE_H_INCLUDED
