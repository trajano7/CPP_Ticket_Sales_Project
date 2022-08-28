#include "container.h"
#include "entidades.h"
#include "dominios.h"
#include "auxiliar.h"
#include "curses.h"

bool containerUsuario::incluir(_usuario usuario) {

  list<_usuario>::iterator elemento = container.begin();

  container.push_back(usuario);
  return true;

}

bool containerUsuario::pesquisar(_usuario *usuario) {

  list<_usuario>::iterator elemento = container.begin();

  _CPF CPF = usuario->getCPF();
  string chave = CPF.getCPF();

  while(elemento != container.end()) {
    if(elemento->getCPF().getCPF() == chave) {
      *usuario = *elemento;
      return true;
    }
    elemento++;
  }

  return false;

}


bool containerCartao::incluir(_cartao cartao) {

   container.push_back(cartao);
   return true;

}

bool containerCartao::excluir(_cartao) {
   return true;
}

bool containerCartao::pesquisar(_cartao *cartao) {

   list<_cartao>::iterator elemento = container.begin();

  _numeroDeCartao numero = cartao->getNumeroDeCartao();
  string chave = numero.getNumeroDeCartao();

  while(elemento != container.end()) {
    if(elemento->getNumeroDeCartao().getNumeroDeCartao() == chave) {
      *cartao = *elemento;
      return true;
    }
    elemento++;
  }

  return false;


}

bool containerCartao::pesquisarPorCPF(_cartao *cartao, _CPF CPF) {

   list<_cartao>::iterator elemento = container.begin();

  string chave = CPF.getCPF();

  while(elemento != container.end()) {
    if(elemento->getCPFcomprador().getCPF() == chave) {
      *cartao = *elemento;
      return true;
    }
    elemento++;
  }

  return false;


}


bool containerEventos::incluir(_evento evento) {

 container.push_back(evento);
  return true;

}

bool containerEventos::excluir(_evento) {

 return true;

}

bool containerEventos::pesquisar(_evento *evento) {

  list<_evento>::iterator elemento = container.begin();

  string chave = evento->getCodigoDeEvento().getCodigoDeEvento();

  while(elemento != container.end()) {
    if(elemento->getCodigoDeEvento().getCodigoDeEvento() == chave) {
      *evento = *elemento;
      return true;
    }
    elemento++;
  }

  return false;

}

int containerEventos::qntdEventos(_CPF CPF) {

 list<_evento>::iterator elemento = container.begin();
 int i = 0;

  while(elemento != container.end()) {
    if(elemento->getCPF().getCPF() == CPF.getCPF()) i++;
    elemento++;
  }

  return i;

}

bool containerEventos::editar(_codigoDeEvento codigoDeEvento, _evento evento) {

 list<_evento>::iterator elemento = container.begin();
 _evento eventoAUX;

  while(elemento != container.end()) {
    if(elemento->getCodigoDeEvento().getCodigoDeEvento() == codigoDeEvento.getCodigoDeEvento()) {

      eventoAUX = *elemento;
      evento.setCPF(eventoAUX.getCPF());
      elemento = container.erase(elemento);
      container.push_back(evento);

      elemento = container.begin();

       return true;
    }
    elemento++;
  }

 return false;

}


bool containerApresentacao::incluir(_apresentacao apresentacao) {

 container.push_back(apresentacao);
  return true;

}

bool containerApresentacao::excluir(_apresentacao) {

 return true;

}

bool containerApresentacao::pesquisar(_apresentacao* apresentacao) {

  list<_apresentacao>::iterator elemento = container.begin();

  string chave = apresentacao->getCodigoDeApresentacao().getCodigoDeApresentacao();

  while(elemento != container.end()) {
    if(elemento->getCodigoDeApresentacao().getCodigoDeApresentacao() == chave) {
      *apresentacao = *elemento;
      return true;
    }
    elemento++;
  }

  return false;

}

bool containerApresentacao::pesquisarFiltros(_data data1, _data data2, _cidade cidade, _estado estado, list<_apresentacao>* lista) {

  classeAuxiliar aux;
  int dataAUX1[3], dataAUX2[3], dataAUX3[3];
  bool dataCorreta = false, cidadeCorreta = false, estadoCorreto = false;
  _evento evento;



  list<_apresentacao>listaAUX;

  list<_apresentacao>::iterator elemento = container.begin();
  list<_apresentacao>::iterator elemento2 = listaAUX.begin();

   aux.transformar(data1.getData(),dataAUX1);
   aux.transformar(data2.getData(),dataAUX2);

   while(elemento != container.end()) {

     aux.transformar(elemento->getData().getData(), dataAUX3);

     //COMECO DA VERIFICACAO DE DATA
      if((dataAUX3[2] > dataAUX1[2]) && (dataAUX3[2] < dataAUX2[2])) dataCorreta = true;

       else if(dataAUX1[2] == dataAUX2[2]) { //ANOS IGUAIS
         if((dataAUX3[1] > dataAUX1[1]) && (dataAUX3[1] < dataAUX2[1])) dataCorreta = true; //MESES CONTIDOS NO INTERVALO

          else if(dataAUX1[1] == dataAUX2[1]) { //MESES SAO IGUAIS
            if((dataAUX3[0] >= dataAUX1[0]) && (dataAUX3[0] <= dataAUX2[0])) dataCorreta = true;
          }

           else if(dataAUX3[1] == dataAUX1[1]) { //MES CONTIDO NO EXTREMO INFERIOR DO INTERVALO DE MES
             if(dataAUX3[0] >= dataAUX1[0]) dataCorreta = true;
           }

           else if(dataAUX3[1] == dataAUX2[1]) {
             if(dataAUX3[0] <= dataAUX2[0]) dataCorreta = true; //MES CONTIDO NO EXTREMO SUPERIOR DO INTERVALO DE MES
           }
       }

        else if(dataAUX1[2] != dataAUX2[2]) {
          if(dataAUX3[2] == dataAUX1[2]) {
            if(dataAUX3[1] > dataAUX1[1]) dataCorreta = true;
             else if(dataAUX3[1] == dataAUX1[1])
               if(dataAUX3[0] >= dataAUX1[0]) dataCorreta = true;
          }

          else if(dataAUX3[2] == dataAUX2[2]) {
            if(dataAUX3[1] < dataAUX2[1]) dataCorreta = true;
             else if(dataAUX3[1] == dataAUX2[1])
               if(dataAUX3[0] <= dataAUX2[0]) dataCorreta = true;
          }
        }


      //FIM DA VERIFICACAO DE DATA

        if(dataCorreta == true) {
          listaAUX.push_back(*elemento);
          dataCorreta = false;
        }

      elemento++;

   }

   if(!listaAUX.empty()) {
    *lista = listaAUX;
     return true;
   }
   else {
     return false;
   }


}

bool containerApresentacao::pesquisar2(_codigoDeEvento codigoDeEvento, list<_apresentacao> *lista) {

  list <_apresentacao> listaAUX;

  list<_apresentacao>::iterator elemento = container.begin();

   while(elemento != container.end()) {
     if(elemento->getCodigoDeEvento2().getCodigoDeEvento() == codigoDeEvento.getCodigoDeEvento()) {
       listaAUX.push_back(*elemento);
     }
     elemento++;
   }

   *lista = listaAUX;

    return true;

}

bool containerApresentacao::editar(_codigoDeApresentacao codigo, _apresentacao apresentacao) {

 list<_apresentacao>::iterator elemento = container.begin();
 _apresentacao aprAUX;

  while(elemento != container.end()) {
    if(elemento->getCodigoDeApresentacao().getCodigoDeApresentacao() == codigo.getCodigoDeApresentacao()) {
      aprAUX = *elemento;
      apresentacao.setCodigoDeEvento2(aprAUX.getCodigoDeEvento2());
      elemento = container.erase(elemento);
      container.push_back(apresentacao);
       return true;
    }
    elemento++;
  }

 return false;

}

bool containerApresentacao::editarCodEvento(_codigoDeEvento codigoAntigo, _codigoDeEvento codigoNovo) {

  list<_apresentacao>::iterator elemento = container.begin();

  while(elemento != container.end()) {
    if(elemento->getCodigoDeEvento2().getCodigoDeEvento() == codigoAntigo.getCodigoDeEvento()) {
      elemento->setCodigoDeEvento2(codigoNovo);
    }
    elemento++;
  }

 return true;

}

bool containerApresentacao::disponibilidade(_codigoDeApresentacao codigo, int *quantidade, _CPF CPF) {

   list<_apresentacao>::iterator elemento = container.begin();
   int qtdDisponivel;
   int qtdVendida;
   _disponibilidade obj1;


   while(elemento != container.end()) {
     if(codigo.getCodigoDeApresentacao() == elemento->getCodigoDeApresentacao().getCodigoDeApresentacao()) {

       if(elemento->getDisponibilidade().getDisponibilidade() >= *quantidade) {
         qtdDisponivel = (elemento->getDisponibilidade().getDisponibilidade()) - *quantidade;
         obj1.setDisponibilidade(qtdDisponivel);
         elemento->setDisponibilidade(obj1);
         elemento->setCPFcomprador(CPF);
         qtdVendida = elemento->getQuantiadeVendida();
         qtdVendida = qtdVendida + *quantidade;
         elemento->setQuantidadeVendida(qtdVendida);
         return true;
       }
       else if(elemento->getDisponibilidade().getDisponibilidade() < *quantidade) {
        *quantidade = (elemento->getDisponibilidade().getDisponibilidade());
        return false;
       }

     }
     elemento++;
   }

}

bool containerIngressos::incluir(_ingresso ingresso) {

 container.push_back(ingresso);
  return true;

}

bool containerIngressos::gerarIngresso(_CPF CPF, _codigoDeApresentacao codigo, int quantidade) {

  _ingresso ingresso;
  _codigoDeIngresso codigo2;
  string aux;
  int i;

  for(i=0; i<quantidade; i++) {

   if(listaVazia == true) {
     aux = maiorCod;
     aux[4]++;
     codigo2.setCodigoDeIngresso(aux);
     ingresso.setCodigoDeIngresso(codigo2);
     ingresso.setCodigoDeApresentacao(codigo);
     ingresso.setCPFcomprador(CPF);
     incluir(ingresso);
     listaVazia = false;
     maiorCod = aux;
   }

   aux = maiorCod;

   if(maiorCod[4] < 9) aux[4]++;
    else if(maiorCod[3] < 9) aux[3]++;
     else if(maiorCod[2] < 9) aux[2]++;
      else if(maiorCod[1] < 9) aux[1]++;
       else if(maiorCod[0] < 9) aux[0]++;

   codigo2.setCodigoDeIngresso(aux);
   ingresso.setCodigoDeIngresso(codigo2);
   ingresso.setCodigoDeApresentacao(codigo);
   ingresso.setCPFcomprador(CPF);
   incluir(ingresso);
   maiorCod = aux;

  }

  return true;

}





















