#include <iostream>
#include <cctype>
#include <sstream>
#include "dominios.h"

using namespace std;


//Implementacao dos metodos referentes a classe _codigoDeEvento

//Metodo responsavel pela validacao do formato do codigo de evento
void _codigoDeEvento::validar(string codigoDeEvento) throw (invalid_argument) {
     int i;

      if(codigoDeEvento.size() != 3) throw invalid_argument("argumento invalido: numero invalido de digitos");
      for(i=0; i<3; i++)
         if(isdigit(codigoDeEvento[i]) == 0) throw invalid_argument("argumento invalido: digito invalido");

}

//Metodo responsavel por setar o valor do codigo de evento no objeto
void _codigoDeEvento::setCodigoDeEvento(string codigoDeEvento) throw (invalid_argument) {
    validar(codigoDeEvento);
    this->codigoDeEvento = codigoDeEvento;
}


//Implementacao dos metodos referentes a classe _codigoDeApresentacao
void _codigoDeApresentacao::validar(string codigoDeApresentacao) throw(invalid_argument) {
     int i=0;

      if(codigoDeApresentacao.size() != 4) throw invalid_argument("argumento invalido: numero invalido de digitos");
       for(i=0; i<4; i++)
          if(isdigit(codigoDeApresentacao[i]) == 0) throw invalid_argument("argumento invalido: digito invalido");

}

void _codigoDeApresentacao::setCodigoDeApresentacao(string codigoDeApresentacao) throw(invalid_argument) {
    validar(codigoDeApresentacao);
    this->codigoDeApresentacao = codigoDeApresentacao;

}


//implementacao dos metodos referentes a classe _codigoDeIngresso
void _codigoDeIngresso::validar(string codigoDeIngresso) throw(invalid_argument) {
     int i=0;

      if(codigoDeIngresso.size() != 5) throw invalid_argument("argumento invalido: numero invalido de digitos");
       for(i=0; i<5; i++)
          if(isdigit(codigoDeIngresso[i]) == 0) throw invalid_argument("argumento invalido: digito invalido");

}

void _codigoDeIngresso::setCodigoDeIngresso(string codigoDeIngresso) throw(invalid_argument) {
    validar(codigoDeIngresso);
    this->codigoDeIngresso = codigoDeIngresso;

}


//implementacao dos metodos referentes a classe _nomeDoEvento
void _nomeDoEvento::validar(string nomeDoEvento) throw(invalid_argument) {
   int tamanho, letra = 0, i;

   //lança excecao caso o nome exceda vinte digitos
   tamanho = nomeDoEvento.size();
    if(nomeDoEvento.size() > 20) throw invalid_argument("argumento invalido: numero invalido de digitos");

   //procura por letras na string e por dois espaços seguidos
   //lanca excecao caso encontre dois espaços seguidos
   for(i=0; i<tamanho; i++) {
    if((isalpha(nomeDoEvento[i])) != 0) letra = 1;
    if(nomeDoEvento[i] == ' ') {
      if(nomeDoEvento[i+1] == ' ') throw invalid_argument("argumento invalido: dois espacos seguidos");
    }
   }

   //lanca excecao caso nao existe pelo menos uma letra na string
   if(letra == 0)
     throw invalid_argument("argumento invalido: nao ha nenhuma letra no nome");

}

void _nomeDoEvento::setNomeDoEvento(string nomeDoEvento) throw(invalid_argument) {
    validar(nomeDoEvento);
    this->nomeDoEvento = nomeDoEvento;
}


//implementacao dos metodos referentes a classe data
void _data::transformar(string data, int intData[3]) {
    stringstream sst1, sst2;
    int e=0, k=0, i, j;

    while(e < 3) {
      sst1 << data[k] << endl;
      sst2 << data[k+1] << endl;
       sst1 >> i;
       sst2 >> j;
       intData[e] = i*10 + j;
       k = k+3;
       e++;
    }

}

void _data::validar(string data) throw(invalid_argument) {
    int intData[3], i;
    const static int DD = 0;
    const static int MM = 1;
    const static int AA = 2;

    if((data.size()) > 8) throw invalid_argument("argumento invalido: tamanho invalido de data");
    if(data[2] != '/' || data[5] != '/') throw invalid_argument("argumento invalido: sem barras");
    for(i=0; i<8; i++) {
      if(i != 2)
       if(i != 5)
        if(isdigit(data[i]) == 0) throw invalid_argument("argumento invalido: caractere invalido");
    }
    transformar(data,intData);

    if(intData[AA] < 0 || intData[AA] > 99) throw invalid_argument("argumento invalido: ano inconsistente");
    if(intData[MM] < 1 || intData[MM] > 12) throw invalid_argument("argumento invalido: mes inconsistente");

    //checa se eh feveiro, caso seja, checa se o ano eh bissexto e so entao chega se o dia esta no intervalo
    if(intData[MM] == 2) {
      if(intData[AA]%4 == 0) {
        if(intData[DD] < 1 || intData[DD] > 29) throw invalid_argument("argumento invalido: dia inconsistente");
      }
      else {
        if(intData[DD] < 1 || intData[DD] > 28) throw invalid_argument("argumento invalido: dia inconsistente");
      }
    }

    if(intData[MM] == 1 || intData[MM] == 3 || intData[MM] == 5 || intData[MM] == 7 || intData[MM] == 8 || intData[MM] == 10 || intData[MM] == 12) {
      if(intData[DD] < 1 || intData[DD] > 31) throw invalid_argument("argumento invalido: dia inconsistente");
    }
     else {
       if(intData[DD] < 1 || intData[DD] > 30) throw invalid_argument("argumento invalido: dia inconsistente");
     }

}

void _data::setData(string data) throw(invalid_argument) {
    validar(data);
    this->data = data;
}


//implementacao dos metodos para classe _horario
void _horario::transformar(string horario, int intHorario[2]) {
   stringstream sst1, sst2;
    int e=0, k=0, i, j;

    while(e < 2) {
      sst1 << horario[k] << endl;
      sst2 << horario[k+1] << endl;
       sst1 >> i;
       sst2 >> j;
       intHorario[e] = i*10 + j;
       k = k+3;
       e++;
    }

}

void _horario::validar(string horario) throw(invalid_argument) {
   int intHorario[2], horarioValido = 0, i;
   const static int HH = 0;
   const static int MM = 1;

   if((horario.size()) != 5) throw invalid_argument("argumento invalido: muitos caracteres");
    if(horario[2] != ':') throw invalid_argument("argumento invalido: sem notacao");
    for(i=0; i<5; i++) {
      if(i != 2)
        if(isdigit(horario[i]) == 0) throw invalid_argument("argumento invalido: caractere invalido");
    }
    transformar(horario,intHorario);

   if(intHorario[HH] < 7 || intHorario[HH] > 22) throw invalid_argument("argumento invalido");
   if(intHorario[MM] == 0 || intHorario[MM] == 15 || intHorario[MM] == 30 || intHorario[MM] == 45) horarioValido = 1;

   if(horarioValido == 0)
    throw invalid_argument("argumento invalido");

}

void _horario::setHorario(string horario) throw(invalid_argument) {
    validar(horario);
    this->horario = horario;
}


//implementacao dso metodos para classe _preco
void _preco::validar(float preco) throw(invalid_argument) {

    if(preco < 0 || preco > 1000)
      throw invalid_argument("argumento invalido");

}

void _preco::setPreco(float preco) throw(invalid_argument) {
    validar(preco);
    this->preco = preco;

}


//implementacao dos metodos para classe _numeroDeSala
void _numeroDeSala::validar(int numeroDeSala) throw(invalid_argument) {

   if(numeroDeSala < 1 || numeroDeSala > 10)
     throw invalid_argument("argumento invalido");

}

void _numeroDeSala::setNumeroDeSala(int numeroDeSala) throw(invalid_argument) {
    validar(numeroDeSala);
    this->numeroDeSala = numeroDeSala;

}


//implementacao dos metodos para classe _cidade
void _cidade::validar(string cidade) throw(invalid_argument) {
   int tamanho, i,  letra = 0;

    tamanho = cidade.size();
     if(tamanho > 15) throw invalid_argument("argumento invalido: muitos caracteres");

    for(i=0; i<tamanho; i++) {
       if((isalpha(cidade[i])) != 0) letra = 1;
       if(cidade[i] == ' ') {
         if(i != tamanho-1) {
           if(cidade[i+1] == ' ') throw invalid_argument("argumento invalido: 2 ou mais espacos seguidos");
         }
       }
       if((ispunct(cidade[i])) != 0) {
         if(i == 0) throw invalid_argument("argumento invalido: ponto sem letra antes");
          else if((isalpha(cidade[i-1])) == 0) throw invalid_argument("argumento invalido: ponto sem letra antes");
       }
    }

    if(letra == 0) throw invalid_argument("argumento invalido: nao ha nenhuma letra no nome");

}

void _cidade::setCidade(string cidade) throw(invalid_argument) {
    validar(cidade);
    this->cidade = cidade;
}


//implementacao dos metodos para classe _estado
void _estado::validar(string estado) throw(invalid_argument) {
    int estadoValido=0;

    if(estado.size() != 2) throw invalid_argument("argumento invalido");

    if(estado == "AL") estadoValido = 1;
     else if(estado == "AC") estadoValido = 1;
     else if(estado == "AP") estadoValido = 1;
     else if(estado == "AM") estadoValido = 1;
     else if(estado == "BA") estadoValido = 1;
     else if(estado == "CE") estadoValido = 1;
     else if(estado == "DF") estadoValido = 1;
     else if(estado == "ES") estadoValido = 1;
     else if(estado == "GO") estadoValido = 1;
     else if(estado == "MA") estadoValido = 1;
     else if(estado == "MT") estadoValido = 1;
     else if(estado == "MS") estadoValido = 1;
     else if(estado == "MG") estadoValido = 1;
     else if(estado == "PA") estadoValido = 1;
     else if(estado == "PB") estadoValido = 1;
     else if(estado == "PR") estadoValido = 1;
     else if(estado == "PE") estadoValido = 1;
     else if(estado == "PI") estadoValido = 1;
     else if(estado == "RJ") estadoValido = 1;
     else if(estado == "RN") estadoValido = 1;
     else if(estado == "RS") estadoValido = 1;
     else if(estado == "RO") estadoValido = 1;
     else if(estado == "RR") estadoValido = 1;
     else if(estado == "SC") estadoValido = 1;
     else if(estado == "SP") estadoValido = 1;
     else if(estado == "SE") estadoValido = 1;
     else if(estado == "TO") estadoValido = 1;

    if(estadoValido == 0) throw invalid_argument("argumento invalido");

}

void _estado::setEstado(string estado) throw(invalid_argument) {
    validar(estado);
    this->estado = estado;
}


//implementacao dos metodos para classe _disponibilidade
void _disponibilidade::validar(int disponibilidade) throw(invalid_argument) {

    if(disponibilidade < 0 || disponibilidade > 250)
      throw invalid_argument("argumento invalido");

}

void _disponibilidade::setDisponibilidade(int disponibilidade) throw(invalid_argument) {
    validar(disponibilidade);
    this->disponibilidade = disponibilidade;
}


//implementacao dos metodos para classe _classeDeEvento
void _classeDeEvento::validar(int classeDeEstado) throw(invalid_argument) {

    if(classeDeEstado < 1 || classeDeEstado > 4)
      throw invalid_argument("argumento invalido");

}

void _classeDeEvento::setClasseDeEvento(int classeDeEstado) throw(invalid_argument) {
    validar(classeDeEstado);
    this->classeDeEvento = classeDeEstado;
}


//implementacao dos metodos para classe _faixaEtaria
void _faixaEtaria::validar(string faixaEtaria) throw(invalid_argument) {
    int faixaValida = 0;

    if(faixaEtaria == "L") faixaValida = 1;
     else if(faixaEtaria == "10") faixaValida = 1;
     else if(faixaEtaria == "12") faixaValida = 1;
     else if(faixaEtaria == "14") faixaValida = 1;
     else if(faixaEtaria == "16") faixaValida = 1;
     else if(faixaEtaria == "18") faixaValida = 1;

    if(faixaValida == 0) throw invalid_argument("argumento invalido");

}

void _faixaEtaria::setFaixaEtaria(string faixaEtaria) throw(invalid_argument) {
    validar(faixaEtaria);
    this->faixaEtaria = faixaEtaria;
}


//implementacao dos metodos para classe _CPF
void _CPF::transformar(string CPF, int intCPF[11]) {
   stringstream sst1;
    int i=0, k=0;

    while(i < 14) {
     if(CPF[i] != '.' && CPF[i] != '-') {
      sst1 << CPF[i] << endl;
       sst1 >> intCPF[k];
       k++;
     }
       i++;
    }

}

void _CPF::verificador(int intCPF[], int *x, int *y) {
   int montante=0, i=0, j=10;

   for(i=0; i<9; i++) {
    montante += intCPF[i]*j;
    j--;
   }

   if(montante%11 < 2) *x = 0;
    else *x = 11-(montante%11);

   montante = 0;
   j = 11;

   for(i=0; i<9; i++) {
    montante += intCPF[i]*j;
    j--;
   }

   montante += (*x)*j;

   if(montante%11 < 2) *y = 0;
    else *y = 11-(montante%11);

}

void _CPF::validar(string CPF) throw(invalid_argument) {
    int x = 0, y = 0, i = 0, intCPF[11];

    if((CPF.size()) != 14) throw invalid_argument("argumento invalido: tamanho invalido");
    if(CPF[3] != '.' || CPF[7] != '.') throw invalid_argument("argumento invalido: sem pontos");
    if(CPF[11] != '-') throw invalid_argument("argumento invalido: sem traço");
    for(i=0; i<14; i++) {
      if(i != 3)
       if(i != 7)
        if(i != 11)
         if(isdigit(CPF[i]) == 0) throw invalid_argument("argumento invalido: caractere invalido");
    }
    transformar(CPF, intCPF);
    verificador(intCPF, &x, &y);

    i = 0;

    while(i < 11) {
      if(intCPF[i] < 0 || intCPF[i] > 9) throw invalid_argument("argumento invalido");
       i++;
    }

    if(intCPF[9] != x || intCPF[10] != y) throw invalid_argument("argumento invalido: codigo verificador errado");

}

void _CPF::setCPF(string CPF) throw(invalid_argument) {
    validar(CPF);
    this->CPF = CPF;
}


//implementacao dos metodos para classe _senha
void _senha::validar(string senha) throw(invalid_argument) {
    int i, j, maiuscula = 0, minuscula = 0, digito = 0;

    if((senha.size()) != 6) throw invalid_argument("argumento invalido: tamanho errado");

    for(i = 0; i < 6; i++) {
       if(ispunct(senha[i]) != 0) throw invalid_argument("argumento invalido: pontuacao na senha nao permitida");
       if(islower(senha[i]) != 0) minuscula = 1;
       if(isupper(senha[i]) != 0) maiuscula = 1;
       if(isdigit(senha[i]) != 0) digito = 1;

        for(j = 0; j<6; j++)
          if(i != j)
           if(senha[i] == senha[j]) throw invalid_argument("argumento invalido: caractere repetido");
    }

    if(maiuscula == 0 || minuscula == 0 || digito == 0) throw invalid_argument("argumento invalido: nao cumpre requisitos");

}

void _senha::setSenha(string senha) throw(invalid_argument) {
    validar(senha);
    this->senha = senha;
}


//implementacao dos metodos para classe _numeroDeCartao
void _numeroDeCartao::transformar(string numeroDeCartao, int IntArray[16]) {

    stringstream sst1;
    int i=0;

    while(i < 16) {
      sst1 << numeroDeCartao[i] << endl;
       sst1 >> IntArray[i];
       i++;
    }

}

int _numeroDeCartao::digitoDeValidacao(int IntArray[16]) {

  int i, j, M=0;

    for(i=0; i<8; i++) {
       j = IntArray[i*2]*2;
         if(j >= 10)
           j = (j/10) + (j%10);
       M += j;
       if(i != 7) M += IntArray[(i*2)+1];
    }

    i = 0;

    while(M%10 != 0) {
       M++;
       i++;
    }

    return i;

}

void _numeroDeCartao::validar(string numeroDeCartao) throw(invalid_argument) {
    int IntArray[16];
    int i;

    if(numeroDeCartao.size() != 16) throw invalid_argument("argumento invalido: numero invalido de digitos");
     for(i=0; i<16; i++)
        if(isdigit(numeroDeCartao[i]) == 0) throw invalid_argument("argumento invalido: digito invalido");

    transformar(numeroDeCartao, IntArray);
    i = digitoDeValidacao(IntArray);

    if(IntArray[15] != i) throw invalid_argument("argumento invalido: digito de seguranca invalido");

}

void _numeroDeCartao::setNumeroDeCartao(string numeroDeCartao) throw (invalid_argument) {
    validar(numeroDeCartao);
    this->numeroDeCartao = numeroDeCartao;
}


//implementacao dos metodos para classe _codigoDeSeguranca
void _codigoDeSeguranca::validar(string codigoDeSeguranca) throw(invalid_argument) {
    int i;

     if(codigoDeSeguranca.size() != 3) throw invalid_argument("argumento invalido: numero invalido de digitos");

     for(i = 0; i<3; i++)
        if(isdigit(codigoDeSeguranca[i]) == 0) throw invalid_argument("argumento invalido: digito invalido");

}

void _codigoDeSeguranca::setCodigoDeSeguranca(string codigoDeSeguranca) throw(invalid_argument) {
    validar(codigoDeSeguranca);
    this->codigoDeSeguranca = codigoDeSeguranca;
}


//implementacao dos metodos para classe _dataDeValidade
void _dataDeValidade::transformar(string dataDeValidade, int IntArray[2]) {
   stringstream sst1, sst2;
    int e=0, k=0, i, j;

    while(e < 2) {
      sst1 << dataDeValidade[k] << endl;
      sst2 << dataDeValidade[k+1] << endl;
       sst1 >> i;
       sst2 >> j;
       IntArray[e] = i*10 + j;
       k = k+3;
       e++;
    }

}

void _dataDeValidade::validar(string dataDeValidade) throw(invalid_argument) {
   int IntArray[2];
   const static int XX = 0;
   const static int YY = 1;

   if((dataDeValidade.size()) > 5) throw invalid_argument("argumento invalido: muitos caracteres");
    if(dataDeValidade[2] != '/') throw invalid_argument("argumento invalido: sem barras");
    transformar(dataDeValidade,IntArray);

   if(IntArray[XX] < 1 || IntArray[XX] > 12) throw invalid_argument("argumento invalido");
   if(IntArray[YY] < 0 || IntArray[YY] > 99) throw invalid_argument("argumento invalido");

}

void _dataDeValidade::setDataDeValidade(string dataDeValidade) throw(invalid_argument) {
    validar(dataDeValidade);
    this->dataDeValidade = dataDeValidade;
}
