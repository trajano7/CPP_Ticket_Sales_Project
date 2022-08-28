#include "entidades.h"


//Implementacao dos metodos da entidade _usuario
void _usuario::setCPF(const _CPF &CPF) {
    this->CPF = CPF;
}

void _usuario::setSenha(const _senha &senha) {
    this->senha = senha;
}

_CPF _usuario::getCPF() const {
    return CPF;
}

_senha _usuario::getSenha() const {
    return senha;
}


//Implementacao dos metodos da entidade _evento
void _evento::setCodigoDeEvento(const _codigoDeEvento &codigoDeEvento) {
    this->codigoDeEvento = codigoDeEvento;
}
void _evento::setNomeDoEvento(const _nomeDoEvento &nomeDoEvento) {
    this->nomeDoEvento = nomeDoEvento;
}
void _evento::setCidade(const _cidade &cidade) {
    this->cidade = cidade;
}
void _evento::setEstado(const _estado &estado) {
    this->estado = estado;
}
void _evento::setClasseDeEvento(const _classeDeEvento &classeDeEvento) {
    this->classeDeEvento = classeDeEvento;
}
void _evento::setFaixaEtaria(const _faixaEtaria &faixaEtaria) {
    this->faixaEtaria = faixaEtaria;
}

void _evento::setCPF(const _CPF &CPF) {
    this->CPF = CPF;
}

_codigoDeEvento _evento::getCodigoDeEvento() const {
    return codigoDeEvento;
}
_nomeDoEvento _evento::getNomeDoEvento() const {
    return nomeDoEvento;
}
_cidade _evento::getCidade() const {
    return cidade;
}
_estado _evento::getEstado() const {
    return estado;
}
_classeDeEvento _evento::getClasseDeEvento() const {
    return classeDeEvento;
}
_faixaEtaria _evento::getFaixaEtaria() const {
    return faixaEtaria;
}

_CPF _evento::getCPF() const {
    return CPF;
}


//Implementacao dos metodos da entidade _apresentacao
void _apresentacao::setCodigoDeApresentacao(const _codigoDeApresentacao &codigoDeApresentacao) {
    this->codigoDeApresentacao = codigoDeApresentacao;
}
void _apresentacao::setData(const _data &data) {
    this->data = data;
}
void _apresentacao::setHorario(const _horario &horario) {
    this->horario = horario;
}
void _apresentacao::setPreco(const _preco &preco) {
    this->preco = preco;
}
void _apresentacao::setNumeroDeSala(const _numeroDeSala &numeroDeSala) {
    this->numeroDeSala = numeroDeSala;
}
void _apresentacao::setDisponibilidade(const _disponibilidade &disponibilidade) {
    this->disponibilidade = disponibilidade;
}

void _apresentacao::setCodigoDeEvento2(const _codigoDeEvento &codigoDeEvento) {
    codigoDeEvento2 = codigoDeEvento;
}

void _apresentacao::setQuantidadeVendida(const int quantiade) {
    quantidadeVendida = quantiade;
}

void _apresentacao::setCPFcomprador(const _CPF CPF) {
    listaCPF[posicaoListaCPF] = CPF;
    posicaoListaCPF++;
}

_codigoDeApresentacao _apresentacao::getCodigoDeApresentacao() const {
    return codigoDeApresentacao;
}
_data _apresentacao::getData() const {
    return data;
}
_horario _apresentacao::getHorario() const {
    return horario;
}
_preco _apresentacao::getPreco() const {
    return preco;
}
_numeroDeSala _apresentacao::getNumeroDeSala() const {
    return numeroDeSala;
}
_disponibilidade _apresentacao::getDisponibilidade() const {
    return disponibilidade;
}
_codigoDeEvento _apresentacao::getCodigoDeEvento2() const {
    return codigoDeEvento2;
}

int _apresentacao::getQuantiadeVendida() const {
   return quantidadeVendida;
}

_CPF _apresentacao::getCPFcomprador(int posicao) const {
    return listaCPF[posicao];
}

int _apresentacao::getPosicaoLista() const {
   return posicaoListaCPF;
}


//Implementacao dos metodos da entidade _ingresso
void _ingresso::setCodigoDeIngresso(const _codigoDeIngresso &codigoDeIngresso) {
    this->codigoDeIngresso = codigoDeIngresso;
}

_codigoDeIngresso _ingresso::getCodigoDeIngresso() const {
    return codigoDeIngresso;
}

void _ingresso::setCodigoDeApresentacao(const _codigoDeApresentacao &codigoDeApresentacao) {
    this->codigoDeApresentacao = codigoDeApresentacao;
}

_codigoDeApresentacao _ingresso::getCodigoDeApresentacao() const {
    return codigoDeApresentacao;
}

void _ingresso::setCPFcomprador(const _CPF &CPF) {
    this->CPF = CPF;
}

_CPF _ingresso::getCPFcomprador() const {
   return CPF;
}




//Implementacao dos metodos da entidade _cartao
void _cartao::setNumeroDeCartao(const _numeroDeCartao &numeroDeCartao) {
    this->numeroDeCartao = numeroDeCartao;
}
void _cartao::setCodigoDeSeguranca(const _codigoDeSeguranca &codigoDeSeguranca) {
    this->codigoDeSeguranca = codigoDeSeguranca;
}
void _cartao::setDataDeValidade(const _dataDeValidade &dataDeValidade) {
    this->dataDeValidade = dataDeValidade;
}

void _cartao::setCPFcomprador(const _CPF &CPF) {
    this->CPF = CPF;
}

_numeroDeCartao _cartao::getNumeroDeCartao() const {
    return numeroDeCartao;
}
_codigoDeSeguranca _cartao::getCodigoDeSeguranca() const {
    return codigoDeSeguranca;
}
_dataDeValidade _cartao::getDataDeValidade() const {
    return dataDeValidade;
}

_CPF _cartao::getCPFcomprador() const {
    return CPF;
}





