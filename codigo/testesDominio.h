#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <string>
#include "dominios.h"

//classe de teste de unidade do dominio _codigoDeEvento
class tu_codigoDeEvento
{
private:

    string codigoValido;
    string codigoInvalido;

    _codigoDeEvento codigoDeEvento;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso =  0;
    const static int falha   = -1;

    int run();

};

//classe de teste de unidade da classe de dominio codigoDeApresentacao
class tu_codigoDeApresentacao
{
private:

    string codigoValido;
    string codigoInvalido;

    _codigoDeApresentacao codigoDeApresentacao;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe de teste de unidade da classe de dominio codigoDeIngresso
class tu_codigoDeIngresso
{
private:

    string codigoValido;
    string codigoInvalido;

    _codigoDeIngresso codigoDeIngresso;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe de teste de unidade da classe de dominio nomeDoEvento
class tu_nomeDoEvento
{
private:

    string nomeValido;
    string nomeInvalido;

    _nomeDoEvento nomeDoEvento;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//teste de unidade da classe data
class tu_data
{
private:

    string dataValida;
    string dataInvalida;

    _data data;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe de teste de unidade do horario
class tu_horario
{
private:

    string horarioValido;
    string horarioInvalido;

    _horario horario;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe de teste de unidade do preco
class tu_preco
{
private:

    const static float valorValido = 500;
    const static float valorInvalido = 1500;

    _preco preco;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe de teste de unidade numero de sala
class tu_numeroDeSala
{
private:

    const static int valorValido = 5;
    const static int valorInvalido = 13;

    _numeroDeSala numeroDeSala;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe de teste de unidade do nome da cidade
class tu_cidade
{
private:

    string nomeValido;
    string nomeInvalido;

    _cidade cidade;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe do teste de unidade da classe _estado
class tu_estado
{
private:

    string siglaValida;
    string siglaInvalida;

    _estado estado;

    int estadoDoTU;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe do teste de unidade da classe _disponibilidade
class tu_disponibilidade
{
private:

    const static int valorValido = 125;
    const static int valorInvalido = 300;

    _disponibilidade disponibilidade;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe do teste de unidade da classe _classeDeEvento
class tu_classeDeEvento
{
private:

    const static int classeValida = 1;
    const static int classeInvalida = 7;

    _classeDeEvento classeDeEvento;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};

//classe do teste de unidade da classe _faixaEtaria
class tu_faixaEtaria
{
private:

    string faixaValida;
    string faixaInvalida;

    _faixaEtaria faixaEtaria;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe do teste de unidade da classe _CPF
class tu_CPF
{
private:

    string cpfValido;
    string cpfInvalido;

    _CPF CPF;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe do teste de unidade para classe _senha
class tu_senha
{
private:

    string senhaValida;
    string senhaInvalida;

    _senha senha;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe do teste de unidade para classe _numeroDeCartao
class tu_numeroDeCartao
{
private:

    string numeroDeCartaoValido;
    string numeroDeCartaoInvalido;

    _numeroDeCartao numeroDeCartao;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe do teste de unidade para classe _codigoDeSegurança
class tu_codigoDeSeguranca
{
private:

    string codigoDeSegurancaValido;
    string codigoDeSegurancaInvalido;

    _codigoDeSeguranca codigoDeSeguranca;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


//classe de teste de unidade da data de validade
class tu_dataDeValidade
{
private:

    string dataDeValidadeValida;
    string dataDeValidadeInvalida;

    _dataDeValidade dataDeValidade;

    int estado;

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:

    const static int sucesso = 0;
    const static int falha = -1;

    int run();

};


#endif // TESTES_H_INCLUDED
