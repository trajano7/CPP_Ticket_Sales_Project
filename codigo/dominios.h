///Biblioteca de dominios
#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

///Classe responsavel pelo armazenamento de um codigo de evento
///
///O formato padrao do codigo e XXX, sendo X um digito inteiro entre 0 e 9
class _codigoDeEvento {
 private:

    string codigoDeEvento;

    //Metodo de validacao do codigo de evento
    void validar(string) throw (invalid_argument);

 public:


    //! Metodo responsavel por gravar o codigo de evento
    /*!
      \param CodigoDeEvento eh um tipo string
      \return Retorna void
    */
    void setCodigoDeEvento(string) throw (invalid_argument);

    //! Metodo responsavel por fazer a leitura do valor gravado no objeto
    /*!
      \param - Nao recebe argumentos
      \return Retorna uma string
    */
    string getCodigoDeEvento() const { /**<Metodo responsavel por fazer a leitura do codigo de evento armazenado*/
      return codigoDeEvento;
    }

};

///Classe responsavel pelo armazenmaneto do codigo de apresentacao
///
///O formato padrao de entrada eh XXXX, sendo X um digito inteiro entre 0 e 9
//Classe de armazenamento do codigo de apresentacao
class _codigoDeApresentacao {
 private:

    string codigoDeApresentacao;

    //Meotodo de validacao
    void validar(string) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o codigo de apresentacao
    /*!
      \param codigoDeApresentacao eh um tipo string
      \return Retorna void
    */
    void setCodigoDeApresentacao(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura do valor gravado no objeto
    /*!
      \param - Nao recebe argumentos
      \return Retorna uma string
    */
    string getCodigoDeApresentacao() const {
      return codigoDeApresentacao;
    }

};


///Classe responsavel pelo armazenamento do codigo de ingresso
///
///O formato padrao de entrada eh XXXXX, sendo X um digito inteiro entre 0 e 9
class _codigoDeIngresso {
 private:

    string codigoDeIngresso;

    //Metodo de validacao
    void validar(string) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o o codigo de ingresso
    /*!
      \param codigoDeIngresso eh do tipo string
      \return Retorna void
    */
    void setCodigoDeIngresso(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura do valor armazenado no objeto
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getCodigoDeIngresso() const {
       return codigoDeIngresso;
    }

};


///Classe responsavel pelo armazenmaneto do nome do evento
///
///O formato padrao de entrada eh XXXXXXXXXXXXXXXXXXXX, onde X pode ser letra, digito ou espaco. Nao pode haver espaco seguidos e deve haver ao menos uma letra
class _nomeDoEvento {
 private:

    string nomeDoEvento;

    //metodo de validacao
    void validar(string) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o nome do evento
    /*!
      \param nomeDoEvento eh um argumento do tipo string
      \return Retorna void
    */
    void setNomeDoEvento(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura do nome armazenado no objeto
    /*!
      \param - Nao recebe parametros
      \return Retorna um tipo string
    */
    string getNomeDoEvento() const {
       return nomeDoEvento;
    }

};


///Classe responsavel pelo armazenamento da data do evento
///
///O formato padrao de entrada eh DD/MM/AA, onde DD eh dia, MM eh mes e AA eh ano. Anos bissextos sao considerados.
class _data {
 private:

    string data;

    void validar(string) throw(invalid_argument);
    //metodo abaixo transforma a os valores numericos da string em um vetor de inteiros para
    //ser usado na fase de verificacao dos intervalos das datas
    void transformar(string, int data2[]);

 public:

    //! Metodo responsavel por gravar a data
    /*!
      \param data eh um argumento do tipo string
      \return Retorna void
    */
    void setData(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura da data armazenada no objeto
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getData() {
       return data;
    }

};

///Classe responsavel pelo armazenamento do horario do evento
///
///O formato padrao de entrada eh HH:MM, onde HH eh hora e MM eh minuto. HH deve ficar entre 7 e 22 e MM esta restringido a (0,30,15,45)
class _horario {
 private:

    string horario;

    //metodo de validacao
    void validar(string) throw(invalid_argument);
    //metodo para transformar string em vetor inteiro
    void transformar(string, int hora[]);

 public:

    //! Metodo responsavel por gravar o horario
    /*!
      \param horario eh do tipo string
      \return Retorna void
    */
    void setHorario(string) throw(invalid_argument);

    //! Metodo responvavel por fazer a leitura do horario armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getHorario() {
      return horario;
    }

};

///Classe responsavel por armazenar o preco
///
///O formato padrao de entrada eh X, sendo X um ponto flutuante podendo assumir valores entre 0 e 1000
class _preco {
 private:

    float preco;

    //Metodo de validacao
    void validar(float) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o preco
    /*!
      \param preco eh um argumento do tipo float
      \return Retorna void
    */
    void setPreco(float) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura do preco armazenado no objeto
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo float
    */
    float getPreco() const {
      return preco;
    }

};

///Classe responsavel pelo armazenamento do numero da sala
///
///O formato padrao de entrada eh X, onde X eh um inteiro entre 1 e 10
class _numeroDeSala {
 private:

    int numeroDeSala;

    //Metodo responvavel pela validacao
    void validar(int) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o numero da sala
    /*!
      \param numeroDeSala eh do tipo int
      \return Retorna void
    */
    void setNumeroDeSala(int) throw(invalid_argument);

    //! Metodo responvavel por fazer a leitura do numero da sala armezenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo int
    */
    int getNumeroDeSala() const {
       return numeroDeSala;
    }

};


///Classe responsavel pelo armazenamento do nome da cidade
///
///O formato padrao de entrada do nome da cidade eh XXXXXXXXXXXXXXXX,onde X pode ser letra, espaco ou ponto. Nao pode haver espaco seguido e pontos sao preceidos de letra
class _cidade {
 private:

    string cidade;
    //Metodo de validacao
    void validar(string) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o nome da cidade
    /*!
      \param cidade eh um argumento do tipo string
      \return Retorna void
    */
    void setCidade(string) throw(invalid_argument);

    //! Metodo responvavel por fazer a leitura do nome da cidade armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getCidade() const {
       return cidade;
    }

};


///Classe responsavel pelo armazenamento do estado
///
///O formato padrao eh a sigla de um dos estados brasileiros com letra em maiusculo (EX: AL)
class _estado {
 private:

    string estado;
    //Metodo de validacao
    void validar(string) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar a sigla do estado
    /*!
      \param estado eh um argumento do tipo string
      \return Retorna void
    */
    void setEstado(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura de um estado armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getEstado() const {
       return estado;
    }

};


///Classe responsavel pelo armazenamento da disponibilidade
///
///O formato padrao de entrada eh X, sendo X um digito inteiro entre 0 a 250
class _disponibilidade {
 private:

    int disponibilidade;
    //Metodo de validacao
    void validar(int) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o digito de disponibilidade
    /*!
      \param disponibilidade eh um argumento do tipo int
      \return Retorna void
    */
    void setDisponibilidade(int) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura da disponibilidade
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo int
    */
    int getDisponibilidade() const {
       return disponibilidade;
    }

};

///Classe responsavel pelo armazenamento da classe de evento
///
///O formato padrao de entrada eh X, onde X eh um digito inteiro que pode assumir valores entre 1 e 4
class _classeDeEvento {
 private:

    int classeDeEvento;
    //Metodo de validacao
    void validar(int) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar a classe de evento
    /*!
      \param classeDeEvento eh um argumento do tipo int
      \return Retorna void
    */
    void setClasseDeEvento(int) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura da classe de evento armazenada
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo int
    */
    int getClasseDeEvento() const {
      return classeDeEvento;
    }

};


///Classe responsavel por armazenar a faixa etaria
///
///O formato padrao de entrada eh uma string que pode assumir (L,10,12,14,16,18)
class _faixaEtaria {
 private:

    string faixaEtaria;
    //Metodo de validacao
    void validar(string) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o valor da faixa etaria
    /*!
      \param faixaEtaria eh um argumento do tipo string
      \return Retorna void
    */
    void setFaixaEtaria(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura da faixa etaria armazenada
    /*!
      \param - Nao recebe argumentos
      \return - Retorna um tipo string
    */
    string getFaixaEtaria() const {
      return faixaEtaria;
    }

};


///Classe responsavel pelo armazenamento do CPF
///
///O formato padrao de entrada eh XXX.XXX.XXX-XX, onde X eh um digito inteiro entre 0 e 9
class _CPF {
 private:

    string CPF;
    //Metodo de validacao
    void validar(string) throw(invalid_argument);
    void verificador(int intCPF[11], int*, int*); //Metodo que verifica o digito de seguranca
    void transformar(string, int intCPF[11]); //Metodo que transformar os numeros da string em um vetor de int

 public:

    //! Metodo responsavel por gravar o CPF
    /*!
      \param CPF eh um argumento do tipo string
      \return Retorna void
    */
    void setCPF(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura do CPF armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getCPF() {
      return CPF;
    }

};


///Classe responsavel por armazenar a senha
///
///O formato padrao de entrada eh XXXXXX, onde X pode ser uma letra ou digito. Nao ha caracteres repetidos e precisa haver ao menos uma letra maiuscula, minuscula e um digito
class _senha {
 private:

    string senha;
    //Metodo de validacao
    void validar(string) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar a senha
    /*!
      \param senha eh um argumento do tipo string
      \return Retorna void
    */
    void setSenha(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura da senha armazenada
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getSenha() const {
      return senha;
    }

};


///Classe responsavel por armazenar o numero de cartao
///
///O formato padrao de entrada eh XXXXXXXXXXXXXXXX, onde X eh um numero entre 0 e 9
class _numeroDeCartao {
 private:

     string numeroDeCartao;
     //Metodo de validacao
     void validar(string) throw(invalid_argument);
     void transformar(string, int IntArray[16]); //transforma a string em um array de int
     int digitoDeValidacao(int IntArray[16]); //verifica qual eh o digito de validacao

 public:

    //! Metodo responsavel por gravar o numero de cartao
    /*!
      \param numeroDeCartao eh um tipo string
      \return Retorna void
    */
    void setNumeroDeCartao(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura do numero de cartao armazenado
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getNumeroDeCartao() const {
      return numeroDeCartao;
    }

};


///Classe responsavel pelo armazenamento do codigo de seguranca
///
///O formato padrao de entrada eh XXX, onde X eh um inteiro de 0 a 9
class _codigoDeSeguranca {
 private:

    string codigoDeSeguranca;
    //Metodo de validacao
    void validar(string) throw(invalid_argument);

 public:

    //! Metodo responsavel por gravar o codigo de seguranca
    /*!
      \param codigoDeSeguranca eh um argumento do tipo string
      \return Retorna void
    */
    void setCodigoDeSeguranca(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura do codigo de seguranca
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getCodigoDeSeguranca() const {
       return codigoDeSeguranca;
    }


};


///Classe responsavel por armazenar a data de validade
///
///O formato padrao de entrada eh XX/YY, sendo XX mes e YY ano. XX deve ficar entre 0 e 12 e YY 0 e 99
class _dataDeValidade {
 private:

    string dataDeValidade;
    //Metodo de validacao
    void validar(string) throw(invalid_argument);
    void transformar(string, int hora[]); //Metodo responsavel por transformar a string em um vetor de int

 public:

    //! Metodo responsavel por gravar a data de validade
    /*!
      \param dataDeValidade eh um argumento do tipo string
      \return Retorna void
    */
    void setDataDeValidade(string) throw(invalid_argument);

    //! Metodo responsavel por fazer a leitura da data de validade
    /*!
      \param - Nao recebe argumentos
      \return Retorna um tipo string
    */
    string getDataDeValidade() {
      return dataDeValidade;
    }

};


#endif // DOMINIOS_H_INCLUDED
