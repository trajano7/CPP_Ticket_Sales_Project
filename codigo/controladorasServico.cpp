#include "controladorasServico.h"
#include "container.h"
#include "entidades.h"
#include "dominios.h"
#include "curses.h"

bool cntrlISautenticacao::autenticar(_CPF CPF, _senha senha) {

  _usuario usuario;
  bool aux;

  usuario.setCPF(CPF);
  aux = container->pesquisar(&usuario);

   if(aux == false) return false; //NAO ACHOU
    else {
      if(senha.getSenha() != usuario.getSenha().getSenha()) return false;
       else return true;
    }

}

int cntrlISusuario::cadastrar(_usuario usuario, _cartao cartao) {

  bool aux, aux2;

  aux = container->pesquisar(&usuario);
  aux2 = container2->pesquisar(&cartao);
   if(aux == true) return 1;
   if(aux2 == true) return 2;

  cartao.setCPFcomprador(usuario.getCPF());

  container->incluir(usuario);
  container2->incluir(cartao);

  return 0;

}

void cntrlISusuario::pesquisarDados(_CPF CPF, _usuario* usuario, _cartao* cartao) {

 usuario->setCPF(CPF);

 container->pesquisar(usuario);
 container2->pesquisarPorCPF(cartao, CPF);

 return;

}

bool cntrlISusuario::excluir(_CPF CPF) {

 return true;

}

//EVENTOS
bool cntrlISeventos::cadastrar(_evento evento, _apresentacao apresentacao, _CPF CPF, int funcao) {

  const static int LIMITE_EVENTOS = 0;
  const static int CADASTRAR_EVENTO = 1;
  const static int CADASTRAR_APRESENTACAO = 2;

  int i;
  bool aux;
  _evento eventoAUX;
  _apresentacao apresentacaoAUX;

  eventoAUX = evento;
  apresentacaoAUX = apresentacao;

   if(funcao == LIMITE_EVENTOS) {

     i = container3->qntdEventos(CPF);
      if(i > 5) return false;

   }

   if(funcao == CADASTRAR_EVENTO) {

     aux = container3->pesquisar(&eventoAUX);
      if(aux == true) return false;

     evento.setCPF(CPF);

     container3->incluir(evento);

   }

   if(funcao == CADASTRAR_APRESENTACAO) {

     aux = container4->pesquisar(&apresentacaoAUX);
      if(aux == true) return false;

     container4->incluir(apresentacao);

   }

}

bool cntrlISeventos::pesquisarEventos(_data data, _data data2, _cidade cidade, _estado estado, list<_evento>* lista1, list<_apresentacao>* lista2) {

  list<_evento> listaAUX;
  list<_apresentacao> listaAUX2;
  list<_codigoDeEvento> listaAUX3;
  _codigoDeEvento codigo;
  _evento evento;
  bool aux, repeticao = false;

  list<_evento>::iterator elemento1 = listaAUX.begin();
  list<_apresentacao>::iterator elemento2 = listaAUX2.begin();
  list<_codigoDeEvento>::iterator elemento3 = listaAUX3.begin();

  aux = container4->pesquisarFiltros(data, data2, cidade, estado, &listaAUX2);
   if(aux == false) return false;

   elemento2 = listaAUX2.begin();

   while(elemento2 != listaAUX2.end()) {

     repeticao = false;
     codigo = elemento2->getCodigoDeEvento2();
     elemento3 = listaAUX3.begin();
      while(elemento3 != listaAUX3.end()) {
        if(elemento3->getCodigoDeEvento() == codigo.getCodigoDeEvento()) {
          repeticao = true;
          break;
        }
      }

     if(repeticao == false) {

       evento.setCodigoDeEvento(codigo);
       container3->pesquisar(&evento);

        if(evento.getCidade().getCidade() != cidade.getCidade()) {
          elemento2 = listaAUX2.erase(elemento2);
        }
         else if(evento.getEstado().getEstado() != estado.getEstado())  {
           elemento2 = listaAUX2.erase(elemento2);
         }
          else {
            listaAUX.push_back(evento);
            listaAUX3.push_back(evento.getCodigoDeEvento());
            elemento2++;
          }

     }

     if(repeticao == true) elemento2++;
     if(listaAUX2.empty()) return false;

   }


   *lista1 = listaAUX;
   *lista2 = listaAUX2;

}

bool cntrlISeventos::excluirEvento(_codigoDeEvento) {

  return true;

}

bool cntrlISeventos::pesquisarMeuEvento(_codigoDeEvento codigoDeEvento, _evento* evento, list<_apresentacao>* lista1) {

   bool aux;

     evento->setCodigoDeEvento(codigoDeEvento);
     aux = container3->pesquisar(evento);
      if(aux == false) return false;

     container4->pesquisar2(codigoDeEvento, lista1);

      return true;

}

bool cntrlISeventos::alterar(_evento evento, _apresentacao apresentacao, _codigoDeApresentacao codigo2, _codigoDeEvento codigo1, int funcao) {

  const static int EDITAR_EVENTO = 0;
  const static int EDITAR_APRESENTACAO = 1;

  bool aux;
  _evento eventoAUX;
  _apresentacao aprAUX;

  eventoAUX.setCodigoDeEvento(evento.getCodigoDeEvento());

   if(funcao == EDITAR_EVENTO) {

    if(codigo1.getCodigoDeEvento() != evento.getCodigoDeEvento().getCodigoDeEvento()) {
     aux = container3->pesquisar(&eventoAUX);
      if(aux == true) return false; //CODIGO JA USADO
    }

     container4->editarCodEvento(codigo1,evento.getCodigoDeEvento());
     container3->editar(codigo1, evento);

      return true;

   }

   aprAUX.setCodigoDeApresentacao(apresentacao.getCodigoDeApresentacao());

   if(funcao == EDITAR_APRESENTACAO) {

   if(apresentacao.getCodigoDeApresentacao().getCodigoDeApresentacao() != codigo2.getCodigoDeApresentacao()) {
    aux = container4->pesquisar(&aprAUX);
     if(aux == true) return false;
   }

    container4->editar(codigo2, apresentacao);

     return true;

   }

}


bool cntrlISvendas::comprar(_CPF CPF, _codigoDeApresentacao codigo, int* quantidade) {

   bool aux;
   int disponivel;
   _apresentacao apresentacao;

   apresentacao.setCodigoDeApresentacao(codigo);

    aux = container4->pesquisar(&apresentacao);
     if(aux == false) return false;

    disponivel = *quantidade;

    aux = container4->disponibilidade(codigo, &disponivel, CPF);

     if(aux == false) {
       *quantidade = disponivel;
       return false;
     }
    aux = container5->gerarIngresso(CPF, codigo, *quantidade);


}










