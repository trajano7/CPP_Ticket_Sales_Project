#include "testesDominio.h"
#include <iostream>

//implementacoes metodos teste da classe _codigoDeEvento
void tu_codigoDeEvento::testarCenarioSucesso() {
  try {
    codigoDeEvento.setCodigoDeEvento(codigoValido);
     if(codigoDeEvento.getCodigoDeEvento() != codigoValido) {
        estado = falha;
     }
  }
  catch(invalid_argument excecao){
        estado = falha;
    }

}

void tu_codigoDeEvento::testarCenarioFalha() {
  try {
    codigoDeEvento.setCodigoDeEvento(codigoInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
        return;
  }

}

int tu_codigoDeEvento::run(){
  codigoValido = "999";
  codigoInvalido = "9991";
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

   return estado;
}


//implementacoes metodos teste da classe _codigoDeApresentacao
void tu_codigoDeApresentacao::testarCenarioSucesso() {
  try {
    codigoDeApresentacao.setCodigoDeApresentacao(codigoValido);
     if(codigoDeApresentacao.getCodigoDeApresentacao() != codigoValido)
        estado = falha;
  }
  catch(invalid_argument excecao) {
     estado = falha;
  }

}

void tu_codigoDeApresentacao::testarCenarioFalha() {
  try {
    codigoDeApresentacao.setCodigoDeApresentacao(codigoInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_codigoDeApresentacao::run() {
  codigoValido = "9999";
  codigoInvalido = "99991";
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

   return estado;
}


//implementacoes metodos teste da classe _codigoDeIngresso
void tu_codigoDeIngresso::testarCenarioSucesso() {
  try {
    codigoDeIngresso.setCodigoDeIngresso(codigoValido);
     if(codigoDeIngresso.getCodigoDeIngresso() != codigoValido)
        estado = falha;
  }
  catch(invalid_argument excecao) {
     estado = falha;
  }

}

void tu_codigoDeIngresso::testarCenarioFalha() {
  try {
    codigoDeIngresso.setCodigoDeIngresso(codigoInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_codigoDeIngresso::run() {
  codigoValido = "99999";
  codigoInvalido = "999991";
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

   return estado;
}


//implementacao dos metodos de teste de unidade da classe _nomeDoEvento
int tu_nomeDoEvento::run() {
   nomeValido = "show de comedia1";
   nomeInvalido = "show  de comida";
   estado = sucesso;
   testarCenarioSucesso();
   testarCenarioFalha();

  return estado;
}

void tu_nomeDoEvento::testarCenarioSucesso() {
 string auxiliar;

  try {
    nomeDoEvento.setNomeDoEvento(nomeValido);
     auxiliar = nomeDoEvento.getNomeDoEvento();
      if((nomeValido.compare(auxiliar)) != 0)
         estado = falha;
  }
  catch(invalid_argument excecao) {
     estado = falha;
  }

}

void tu_nomeDoEvento::testarCenarioFalha() {
  try {
    nomeDoEvento.setNomeDoEvento(nomeInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
     return;
  }

}


//implementacao metodos da classe de teste de data
void tu_data::testarCenarioSucesso() {
    string auxiliar;

     try {
      data.setData(dataValida);
       auxiliar = data.getData();
        if((dataValida.compare(auxiliar)) != 0)
          estado = falha;
     }
     catch(invalid_argument excecao) {
        estado = falha;
     }

}

void tu_data::testarCenarioFalha() {
  try {
    data.setData(dataInvalida);
    estado = falha;
  }
  catch(invalid_argument excecao) {
     return;
  }

}

int tu_data::run() {
   dataValida = "10/03/99";
   dataInvalida = "31/0199";
   estado = sucesso;
   testarCenarioSucesso();
   testarCenarioFalha();


  return estado;

}


//implementacao dos metodos da classe de teste de unidade do horario
void tu_horario::testarCenarioSucesso() {
  try {
    horario.setHorario(horarioValido);
      if(horario.getHorario() != horarioValido)
        estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_horario::testarCenarioFalha() {
  try {
    horario.setHorario(horarioInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_horario::run() {
   horarioValido = "12:30";
   horarioInvalido = "25:12";
   estado = sucesso;
   testarCenarioSucesso();
   testarCenarioFalha();

    return estado;

}

//implementacao dos metodos da classe de teste de unidade do preco
void tu_preco::testarCenarioSucesso() {
  try {
   preco.setPreco(valorValido);
    if(preco.getPreco() != valorValido)
      estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }
}

void tu_preco::testarCenarioFalha() {
  try {
   preco.setPreco(valorInvalido);
   estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }
}

int tu_preco::run() {
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

    return estado;
}


//implementacao dos metodos da classe de teste de unidade de numero de sala
void tu_numeroDeSala::testarCenarioSucesso() {
  try {
   numeroDeSala.setNumeroDeSala(valorValido);
    if(numeroDeSala.getNumeroDeSala() != valorValido)
      estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_numeroDeSala::testarCenarioFalha() {
  try {
   numeroDeSala.setNumeroDeSala(valorInvalido);
   estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_numeroDeSala::run() {
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

   return estado;
}


//implementacao dos metodos da classe de teste de unidade do nome da cidade
void tu_cidade::testarCenarioSucesso() {
    string auxiliar;

  try {
   cidade.setCidade(nomeValido);
    auxiliar = cidade.getCidade();
       if((nomeValido.compare(auxiliar)) != 0)
          estado = falha;
     }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_cidade::testarCenarioFalha() {
  try {
   cidade.setCidade(nomeInvalido);
   estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_cidade::run() {
   nomeValido = "tangamandapio.1";
   nomeInvalido = ".tangamandapio";
   estado = sucesso;
   testarCenarioSucesso();
   testarCenarioFalha();

  return estado;

}


//implementacao dos metodos da classe de teste de unidade da classe _estado
void tu_estado::testarCenarioSucesso() {
    string auxiliar;

  try {
    estado.setEstado(siglaValida);
      auxiliar = estado.getEstado();
        if((siglaValida.compare(auxiliar)) != 0)
          estadoDoTU = falha;
  }
  catch(invalid_argument excecao) {
    estadoDoTU = falha;
  }

}

void tu_estado::testarCenarioFalha() {
  try {
    estado.setEstado(siglaInvalida);
    estadoDoTU = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_estado::run() {
   siglaValida = "AL";
   siglaInvalida = "HH";
   estadoDoTU = sucesso;
   testarCenarioSucesso();
   testarCenarioFalha();

     return estadoDoTU;

}


//implementacao dos metodos da classe de teste de unidade da classe _disponibilidade
void tu_disponibilidade::testarCenarioSucesso() {
  try {
    disponibilidade.setDisponibilidade(valorValido);
     if(disponibilidade.getDisponibilidade() != valorValido)
       estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_disponibilidade::testarCenarioFalha() {
  try {
    disponibilidade.setDisponibilidade(valorInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_disponibilidade::run() {
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

    return estado;

}


//implementacao dos metodos da classe de teste de unidade da classe _classeDeEvento
void tu_classeDeEvento::testarCenarioSucesso() {
  try {
    classeDeEvento.setClasseDeEvento(classeValida);
     if(classeDeEvento.getClasseDeEvento() != classeValida)
       estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_classeDeEvento::testarCenarioFalha() {
  try {
    classeDeEvento.setClasseDeEvento(classeInvalida);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_classeDeEvento::run() {
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

   return estado;

}


//implementacao dos metodos da classe de teste de unidade da classe _faixaEtaria
void tu_faixaEtaria::testarCenarioSucesso() {
  try {
    faixaEtaria.setFaixaEtaria(faixaValida);
     if(faixaEtaria.getFaixaEtaria() != faixaValida)
       estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_faixaEtaria::testarCenarioFalha() {
  try {
    faixaEtaria.setFaixaEtaria(faixaInvalida);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_faixaEtaria::run() {
   faixaValida = "L";
   faixaInvalida = "25";
   estado = sucesso;
   testarCenarioSucesso();
   testarCenarioFalha();

    return estado;

}


//implementacao dos metodos da classe de teste de unidade da classe _CPF
void tu_CPF::testarCenarioSucesso() {
  try {
    CPF.setCPF(cpfValido);
     if(CPF.getCPF() != cpfValido) {
       estado = falha;
     }
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_CPF::testarCenarioFalha() {
  try {
    CPF.setCPF(cpfInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_CPF::run() {
  cpfValido = "111.444.777-35";
  cpfInvalido = "111.444.777-31";
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

    return estado;

}


//implementacao dos metodos da classe de teste de unidade da classe _senha
void tu_senha::testarCenarioSucesso() {
  try {
    senha.setSenha(senhaValida);
     if(senha.getSenha() != senhaValida)
       estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_senha::testarCenarioFalha() {
  try {
    senha.setSenha(senhaInvalida);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_senha::run() {
   senhaValida = "1AbTuk";
   senhaInvalida = "1AAbtuk";
   estado = sucesso;
   testarCenarioSucesso();
   testarCenarioFalha();

    return estado;

}


//implementacao dos metodos da classe de teste de unidade da classe _numeroDeCartao
void tu_numeroDeCartao::testarCenarioSucesso() {
  try {
    numeroDeCartao.setNumeroDeCartao(numeroDeCartaoValido);
     if(numeroDeCartao.getNumeroDeCartao() != numeroDeCartaoValido)
       estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_numeroDeCartao::testarCenarioFalha() {
  try {
    numeroDeCartao.setNumeroDeCartao(numeroDeCartaoInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_numeroDeCartao::run() {
  numeroDeCartaoValido = "5457623898234113";
  numeroDeCartaoInvalido = "5457623898234112";
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

    return estado;

}


//implementacao dos metodos da classe de teste de unidade da classe _codigoDeSegurança
void tu_codigoDeSeguranca::testarCenarioSucesso() {
  try {
    codigoDeSeguranca.setCodigoDeSeguranca(codigoDeSegurancaValido);
     if(codigoDeSeguranca.getCodigoDeSeguranca() != codigoDeSegurancaValido)
       estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_codigoDeSeguranca::testarCenarioFalha() {
  try {
    codigoDeSeguranca.setCodigoDeSeguranca(codigoDeSegurancaInvalido);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_codigoDeSeguranca::run() {
  codigoDeSegurancaValido = "999";
  codigoDeSegurancaInvalido = "A09";
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

    return estado;

}


//implementacao dos metodos da classe de teste de unidade da classe _dataDeValidade
void tu_dataDeValidade::testarCenarioSucesso() {
  try {
    dataDeValidade.setDataDeValidade(dataDeValidadeValida);
     if(dataDeValidade.getDataDeValidade() != dataDeValidadeValida)
       estado = falha;
  }
  catch(invalid_argument excecao) {
    estado = falha;
  }

}

void tu_dataDeValidade::testarCenarioFalha() {
  try {
    dataDeValidade.setDataDeValidade(dataDeValidadeInvalida);
    estado = falha;
  }
  catch(invalid_argument excecao) {
    return;
  }

}

int tu_dataDeValidade::run() {
  dataDeValidadeValida = "12/99";
  dataDeValidadeInvalida = "13/99";
  estado = sucesso;
  testarCenarioSucesso();
  testarCenarioFalha();

    return estado;

}




