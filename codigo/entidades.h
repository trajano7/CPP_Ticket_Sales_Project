///Biblioteca de entidades
#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

///Classe responsavel pelo armazenamento das informacoes de um usuario
///
///Contem CPF e senha
class _usuario {
 private:

    _CPF CPF;
    _senha senha;

 public:

    //! Metodo responsavel por gravar um objeto do tipo CPF
    /*!
      \param CPF eh um argumento do tipo _CPF
      \return Retorna void
    */
    void setCPF(const _CPF &);
    //! Metodo responsavel por gravar um objeto do tipo _senha
    /*!
      \param senha eh um argumento do tipo _senha
      \return Retorna void
    */
    void setSenha(const _senha &);

    _CPF getCPF() const;
    _senha getSenha() const;

};


//classe entidade evento
class _evento {
 private:

    _codigoDeEvento codigoDeEvento;
    _nomeDoEvento nomeDoEvento;
    _cidade cidade;
    _estado estado;
    _classeDeEvento classeDeEvento;
    _faixaEtaria faixaEtaria;
    _CPF CPF;

 public:

    //! Metodo responsavel por gravar um objeto do _tipo CodigoDeEvento
    /*!
      \param CodigoDeEvento eh um argumento do tipo _CodigoDeEvento
      \return Retorna void
    */
    void setCodigoDeEvento(const _codigoDeEvento &);
    //! Metodo responsavel por gravar um objeto do tipo _nomeDeEvento
    /*!
      \param nomeDeEvento eh um argumento do tipo _nomeDeEvento
      \return Retorna void
    */
    void setNomeDoEvento(const _nomeDoEvento &);
    //! Metodo responsavel por gravar um objeto do tipo cidade
    /*!
      \param cidade eh um argumento do tipo _cidade
      \return Retorna void
    */
    void setCidade(const _cidade &);
    //! Metodo responsavel por gravar um objeto do tipo _estado
    /*!
      \param estado eh um argumento do tipo _estado
      \return Retorna void
    */
    void setEstado(const _estado &);
    //! Metodo responsavel por gravar um objeto do tipo _classeDeEvento
    /*!
      \param classeDeEvento eh um argumento do tipo _classeDeEvento
      \return Retorna void
    */
    void setClasseDeEvento(const _classeDeEvento &);
    //! Metodo responsavel por gravar um objeto do tipo _faixaEtaria
    /*!
      \param faixaEtaria eh um argumento do tipo _faixaEtaria
      \return Retorna void
    */
    void setFaixaEtaria(const _faixaEtaria &);

    void setCPF(const _CPF &);


    //! Metodo responsavel por fazer a leitura do objeto do tipo _CodigoDeEvento armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _codigoDeEvento
    */
    _codigoDeEvento getCodigoDeEvento() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _nomeDoEvento armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _nomeDoEvento
    */
    _nomeDoEvento getNomeDoEvento() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _cidade armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _cidade
    */
    _cidade getCidade() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _estado armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _estado
    */
    _estado getEstado() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _ClasseDeEvento armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _ClasseDeEvento
    */
    _classeDeEvento getClasseDeEvento() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _faixaEtaria armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _faixaEtaria
    */
    _faixaEtaria getFaixaEtaria() const;

    _CPF getCPF() const;

};


//classe entidade apresentacao
class _apresentacao {
 private:

    _codigoDeApresentacao codigoDeApresentacao;
    _data data;
    _horario horario;
    _preco preco;
    _numeroDeSala numeroDeSala;
    _disponibilidade disponibilidade;
    _codigoDeEvento codigoDeEvento2;
    int quantidadeVendida;
    _CPF listaCPF[250];
    int posicaoListaCPF;

 public:

     _apresentacao() {
       posicaoListaCPF = 0;
       quantidadeVendida = 0;
     }

    //! Metodo responsavel por gravar um objeto do tipo _codigoDeApresentacao
    /*!
      \param codigoDeApresentacao eh um argumento do tipo _codigoDeApresentacao
      \return Retorna void
    */
    void setCodigoDeApresentacao(const _codigoDeApresentacao &);
    //! Metodo responsavel por gravar um objeto do tipo _data
    /*!
      \param data eh um argumento do tipo _data
      \return Retorna void
    */
    void setData(const _data &);
    //! Metodo responsavel por gravar um objeto do tipo _horario
    /*!
      \param horario eh um argumento do tipo _horario
      \return Retorna void
    */
    void setHorario(const _horario &);
    //! Metodo responsavel por gravar um objeto do tipo _preco
    /*!
      \param preco eh um argumento do tipo _preco
      \return Retorna void
    */
    void setPreco(const _preco &);
    //! Metodo responsavel por gravar um objeto do tipo _numeroDeSala
    /*!
      \param numeroDeSala eh um argumento do tipo _numeroDeSala
      \return Retorna void
    */
    void setNumeroDeSala(const _numeroDeSala &);
    //! Metodo responsavel por gravar um objeto do tipo _disponibilidade
    /*!
      \param disponibilidade eh um argumento do tipo _disponibilidade
      \return Retorna void
    */
    void setDisponibilidade(const _disponibilidade &);

    void setCodigoDeEvento2(const _codigoDeEvento &);

    void setQuantidadeVendida(const int);

    void setCPFcomprador(const _CPF);


    //! Metodo responsavel por fazer a leitura do objeto do tipo _codigoDeApresentacao armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _codigoDeApresentacao
    */
    _codigoDeApresentacao getCodigoDeApresentacao() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _data armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _data
    */
    _data getData() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _horario armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _horario
    */
    _horario getHorario() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _preco armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _preco
    */
    _preco getPreco() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _numeroDeSala armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _numeroDeSala
    */
    _numeroDeSala getNumeroDeSala() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _disponibilidade armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _disponibilidade
    */
    _disponibilidade getDisponibilidade() const;

    _codigoDeEvento getCodigoDeEvento2() const;

    int getQuantiadeVendida() const;

    _CPF getCPFcomprador(int) const;

    int getPosicaoLista() const;

};


//classe entidade ingresso
class _ingresso {
 private:

    _codigoDeIngresso codigoDeIngresso;
    _codigoDeApresentacao codigoDeApresentacao;
    _CPF CPF;

 public:

    //! Metodo responsavel por gravar um objeto do tipo _codigoDeIngresso
    /*!
      \param codigoDeIngresso eh um argumento do tipo _codigoDeIngresso
      \return Retorna void
    */
    void setCodigoDeIngresso(const _codigoDeIngresso &);

    void setCodigoDeApresentacao(const _codigoDeApresentacao &);

    void setCPFcomprador(const _CPF &);

    //! Metodo responsavel por fazer a leitura do objeto do tipo _codigoDeIngresso armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _codigoDeIngresso
    */
    _codigoDeIngresso getCodigoDeIngresso() const;

    _codigoDeApresentacao getCodigoDeApresentacao() const;

    _CPF getCPFcomprador() const;

};


//classe entidade cartao
class _cartao {
 private:

    _numeroDeCartao numeroDeCartao;
    _codigoDeSeguranca codigoDeSeguranca;
    _dataDeValidade dataDeValidade;
    _CPF CPF;

 public:

    //! Metodo responsavel por gravar um objeto do tipo _numeroDeCartao
    /*!
      \param numeroDeCartao eh um argumento do tipo _numeroDeCartao
      \return Retorna void
    */
    void setNumeroDeCartao(const _numeroDeCartao &);
    //! Metodo responsavel por gravar um objeto do tipo _codigoDeSeguranca
    /*!
      \param codigoDeSeguranca eh um argumento do tipo _codigoDeSeguranca
      \return Retorna void
    */
    void setCodigoDeSeguranca(const _codigoDeSeguranca &);
    //! Metodo responsavel por gravar um objeto do tipo _dataDeValidade
    /*!
      \param dataDeValidade eh um argumento do tipo _dataDeValidade
      \return Retorna void
    */
    void setDataDeValidade(const _dataDeValidade &);

    void setCPFcomprador(const _CPF &);


    //! Metodo responsavel por fazer a leitura do objeto do tipo _numeroDeCartao armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _numeroDeCartao
    */
    _numeroDeCartao getNumeroDeCartao() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _codigoDeSeguraca armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _codigoDeSeguranca
    */
    _codigoDeSeguranca getCodigoDeSeguranca() const;
    //! Metodo responsavel por fazer a leitura do objeto do tipo _dataDeValidade armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo _dataDeValidade
    */
    _dataDeValidade getDataDeValidade() const;

     _CPF getCPFcomprador() const;

};




#endif // ENTIDADES_H_INCLUDED
