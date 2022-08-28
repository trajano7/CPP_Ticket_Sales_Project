#include "comandosApresentacao.h"
#include <iostream>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

int cmdCadastrar::executar(ISusuario* cntrlISusuario) {

  int linha, coluna;
  int aux=0, aux3 = -1;
  bool excecao = false;
  char aux2[80];
  _CPF CPF;
  _senha senha;
  _numeroDeCartao numeroDeCartao;
  _codigoDeSeguranca codigoDeSeguranca;
  _dataDeValidade dataDeValidade;
  _usuario usuario;
  _cartao cartao;

    initscr();
     clear();
     getmaxyx(stdscr,linha,coluna);
     mvprintw(linha/2 - 4,(coluna)/2 - 8,"CPF: ");
     mvprintw(linha/2 - 2,(coluna)/2 - 8,"SENHA: ");
     mvprintw(linha/2,(coluna)/2 - 8,"NUMERO DE CARTAO: ");
     mvprintw(linha/2 + 2,(coluna)/2 - 8,"CODIGO DE SEGURANÇA: ");
     mvprintw(linha/2 + 4,(coluna)/2 - 8,"VALIDADE: ");

   while(true) {

    excecao = false;

    if(aux3 == cartaoCadastrado) {
      mvprintw(linha/2 - 8,(coluna)/2 - 8, "NUMERO DE CARTAO JÁ CADASTRADO");
      mvprintw(linha/2 - 7,(coluna)/2 - 8, "TENTE UM OUTRO CARTAO:");
      mvprintw(linha/2,(coluna)/2 + 10, "                  ");
    }


    try {

     switch(aux) {
       case 0:
         mvprintw(linha/2 - 4,(coluna)/2 - 3,"");
          getstr(aux2);
          CPF.setCPF(aux2);
          aux++;
       case 1:
         mvprintw(linha/2 - 2,(coluna)/2 - 1,"");
          getstr(aux2);
          senha.setSenha(aux2);
          aux++;
       case 2:
         mvprintw(linha/2,(coluna)/2 + 10,"");
          getstr(aux2);
          numeroDeCartao.setNumeroDeCartao(aux2);
           if(aux3 == cartaoCadastrado) break;
          aux++;
       case 3:
         mvprintw(linha/2 + 2,(coluna)/2 + 13,"");
         getstr(aux2);
         codigoDeSeguranca.setCodigoDeSeguranca(aux2);
         aux++;
       case 4:
         mvprintw(linha/2 + 4,(coluna)/2 + 2,"");
         getstr(aux2);
         dataDeValidade.setDataDeValidade(aux2);
         aux++;
     }
    }
     catch (invalid_argument) {

       excecao = true;

        switch(aux) {
          case 0:
            mvprintw(linha/2 - 8,(coluna)/2 - 8, "CPF EM FORMATO INVALIDO");
            mvprintw(linha/2 - 4,(coluna)/2 - 3, "              ");
            break;
          case 1:
            mvprintw(linha/2 - 8,(coluna)/2 - 8, "SENHA EM FORMATO INVALIDO");
            mvprintw(linha/2 - 2,(coluna)/2 - 1, "              ");
            break;
          case 2:
            mvprintw(linha/2 - 8,(coluna)/2 - 8, "NUMERO DE CARTAO EM FORMATO INVALIDO");
            mvprintw(linha/2,(coluna)/2 + 10, "                  ");
            break;
          case 3:
            mvprintw(linha/2 - 8,(coluna)/2 - 8, "CODIGO DE SEGURANCA EM FORMATO INVALIDO");
            mvprintw(linha/2 + 2,(coluna)/2 + 13, "                  ");
            break;
          case 4:
            mvprintw(linha/2 - 8,(coluna)/2 - 8, "DATA DE VALIDADE EM FORMATO INVALIDO");
            mvprintw(linha/2 + 4,(coluna)/2 + 2, "                  ");
            break;
        }
     }

     if(excecao == false)  {
       usuario.setCPF(CPF);
       usuario.setSenha(senha);
       cartao.setNumeroDeCartao(numeroDeCartao);
       cartao.setCodigoDeSeguranca(codigoDeSeguranca);
       cartao.setDataDeValidade(dataDeValidade);
        aux3 = cntrlISusuario->cadastrar(usuario, cartao);
        if(aux3 == CPFcadastrado) return CPFcadastrado; //1
         else if(aux3 == cartaoCadastrado) aux = 2; //2
          else if(aux3 == cadastroSucesso) return cadastroSucesso; //0
     }

   }
   endwin();



}


int cmdExcluir::executar(ISusuario *cntrlISusuario, _CPF CPF) {

  int linha, coluna, i;
  bool aux;
  static const int SIM = 48;
  static const int NAO = 49;

   initscr();
    clear();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna)/2 - 25,"TEM CERTEZA QUE DESEJA EXCLUIR A CONTA? (0. SIM / 1. NAO)");
    i = getch();
      switch(i) {
        case SIM:
          aux = cntrlISusuario->excluir(CPF);
           if(aux == false) return ExclusaoNaoPermitida;
            else return contaExcluida;
        case NAO:
          return ExclusaoCancelada;
      }
    endwin();


}

int cmdMeusDados::executar(ISusuario *cntrlISusuario, _CPF CPF) {

  int linha, coluna;
  string aux;
  _CPF CPF2;
  _senha senha;
  _numeroDeCartao numeroDeCartao;
  _codigoDeSeguranca codigoDeSeguranca;
  _dataDeValidade validade;
  _usuario usuario;
  _cartao cartao;

    cntrlISusuario->pesquisarDados(CPF, &usuario, &cartao);

    CPF2 = usuario.getCPF();
    senha = usuario.getSenha();
    numeroDeCartao = cartao.getNumeroDeCartao();
    codigoDeSeguranca = cartao.getCodigoDeSeguranca();
    validade = cartao.getDataDeValidade();


    initscr();
     clear();
     getmaxyx(stdscr,linha,coluna);
     aux = CPF2.getCPF();
      mvprintw(linha/2 - 4,(coluna)/2 - 8,"CPF: ");
      mvprintw(linha/2 - 4,(coluna)/2 - 3, const_cast<char *>(aux.c_str()));
     aux = senha.getSenha();
      mvprintw(linha/2 - 2,(coluna)/2 - 8,"SENHA: ");
      mvprintw(linha/2 - 2,(coluna)/2 - 1, const_cast<char *>(aux.c_str()));
     aux = numeroDeCartao.getNumeroDeCartao();
      mvprintw(linha/2,(coluna)/2 - 8,"NUMERO DE CARTAO: ");
      mvprintw(linha/2,(coluna)/2 + 10, const_cast<char *>(aux.c_str()));
     aux = codigoDeSeguranca.getCodigoDeSeguranca();
      mvprintw(linha/2 + 2,(coluna)/2 - 8,"CODIGO DE SEGURANÇA: ");
      mvprintw(linha/2 + 2,(coluna)/2 + 13, const_cast<char *>(aux.c_str()));
     aux = validade.getDataDeValidade();
      mvprintw(linha/2 + 4,(coluna)/2 - 8,"VALIDADE: ");
      mvprintw(linha/2 + 4,(coluna)/2 + 2, const_cast<char *>(aux.c_str()));


    mvprintw(linha/2 + 8,(coluna)/2 - 8,"0. RETORNAR");
    echo();
    getch();
    noecho();
    endwin();

     return 0;

}


//IMPLENTACAO DOS COMANDOS DE EVENTOS
int cmdPesquisarEventos::executar(ISeventos *cntrlISeventos, _CPF CPF) {

   int linha, coluna, aux = 0, x, i=0, linha1, k=0, j=0;
   char aux2[80];
   bool excecao = false, aux3;
   float aux6;
   string aux4, aux5, aux7;
   list<_evento> lista1;
   list<_apresentacao> lista2;
   _evento evento;
   _apresentacao apresentacao;
   _data data, data2;
   _cidade cidade1;
   _estado estado;
   _codigoDeEvento codigo;

   initscr();
    clear();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2 - 8,(coluna)/2 - 20,"ESCOLHA OS FILTROS DE EVENTO DESEJADOS:");
    mvprintw(linha/2 - 4,(coluna)/2 - 16,"PERIODO DE EVENTOS DESEJADO:");
    mvprintw(linha/2 - 2,(coluna)/2 - 14,"DE:");
    mvprintw(linha/2,(coluna)/2 - 14,"ATE:");
    mvprintw(linha/2 + 2,(coluna)/2 - 16,"CIDADE:");
    mvprintw(linha/2 + 4,(coluna)/2 - 16,"ESTADO:");

    while(true) {

     try {

       switch(aux) {
         case 0:
           mvprintw(linha/2 - 2,(coluna)/2 - 10,"");
           getstr(aux2);
           data.setData(aux2);
           aux++;
         case 1:
           mvprintw(linha/2,(coluna)/2 - 9,"");
           getstr(aux2);
           data2.setData(aux2);
           aux++;
         case 2:
           mvprintw(linha/2 + 2,(coluna)/2 - 8,"");
           getstr(aux2);
           cidade1.setCidade(aux2);
           aux++;
         case 3:
           mvprintw(linha/2 + 4,(coluna)/2 - 8,"");
           getstr(aux2);
           estado.setEstado(aux2);
           aux++;
       }
     }
     catch(invalid_argument) {

       excecao = true;

       switch(aux) {
         case 0:
           mvprintw(linha/2 - 10,(coluna)/2 - 12,"DATA EM FORMATO INVALIDO");
           mvprintw(linha/2 - 2,(coluna)/2 - 10,"        ");
           break;
         case 1:
           mvprintw(linha/2 - 10,(coluna)/2 - 12,"DATA EM FORMATO INVALIDO");
           mvprintw(linha/2,(coluna)/2 - 9,"        ");
           break;
         case 2:
           mvprintw(linha/2 - 14,(coluna)/2 - 12,"NOME DA CIDADE EM FORMATO INVALIDO");
           mvprintw(linha/2 + 2,(coluna)/2 - 8,"             ");
           break;
         case 3:
           mvprintw(linha/2 - 14,(coluna)/2 - 12,"SIGLA DO ESTADO EM FORMATO INVALIDO");
           mvprintw(linha/2 + 4,(coluna)/2 - 8,"               ");
           break;
       }
     }

     mvprintw(0,0,"TESTE2");
    getch();

     if(excecao == false) {
       aux3 = cntrlISeventos->pesquisarEventos(data, data2, cidade1, estado, &lista1, &lista2);
        if(aux3 == false) return 1;
        break;
     }
    }
    endwin();


    //IMPRIMIR AS INFORMACOES DOS EVENTOs


    list<_evento>::iterator elemento = lista1.begin();
    list<_apresentacao>::iterator elemento2 = lista2.begin();


    apresentacao = *elemento2;

  while(elemento != lista1.end()) {
       j++;
       elemento++;
  }

     elemento = lista1.begin();

  while(true) {

    elemento2 = lista2.begin();

    i = 0;
    evento = *elemento;

    initscr();
     clear();
     getmaxyx(stdscr,linha,coluna);
     mvprintw(1,19,"INFORMACOES DO EVENTO:");
     mvprintw(3,12,"COD. DO EVENTO:");
      aux4 = evento.getCodigoDeEvento().getCodigoDeEvento();
      mvprintw(3,28, const_cast<char *>(aux4.c_str()));
     mvprintw(4,12,"NOME:");
      aux4 = evento.getNomeDoEvento().getNomeDoEvento();
      mvprintw(4,18, const_cast<char *>(aux4.c_str()));
     mvprintw(5,12,"CIDADE:");
      aux4 = evento.getCidade().getCidade();
      mvprintw(5,20, const_cast<char *>(aux4.c_str()));
     mvprintw(6,12,"ESTADO:");
      aux4 = evento.getEstado().getEstado();
      mvprintw(6,20, const_cast<char *>(aux4.c_str()));
     mvprintw(7,12,"CLASSE:");
      x = evento.getClasseDeEvento().getClasseDeEvento();
      mvprintw(7,20, "%d", x);
     mvprintw(8,12,"FAIXA ETARIA:");
      aux4 = evento.getFaixaEtaria().getFaixaEtaria();
      mvprintw(8,26, const_cast<char *>(aux4.c_str()));

     aux4 = evento.getCodigoDeEvento().getCodigoDeEvento();

     apresentacao = *elemento2;

     mvprintw(10,19,"APRESENTACOES:");

     linha1 = 9;

     while(elemento2 != lista2.end()) {
          apresentacao = *elemento2;

          aux5 = apresentacao.getCodigoDeEvento2().getCodigoDeEvento();
          if(aux5 == aux4) {
            if(i == 2) linha1 = 0;
            linha1 = linha1 + 3;
            if(i <= 1) {
              mvprintw(linha1,12,"COD. DE APRESENTACAO:");
                aux7 = apresentacao.getCodigoDeApresentacao().getCodigoDeApresentacao();
                mvprintw(linha1,34, const_cast<char *>(aux7.c_str()));
                linha1++;
              mvprintw(linha1,12,"DATA:");
                aux7 = apresentacao.getData().getData();
                mvprintw(linha1,18, const_cast<char *>(aux7.c_str()));
                linha1++;
              mvprintw(linha1,12,"HORARIO:");
                aux7 = apresentacao.getHorario().getHorario();
                mvprintw(linha1,21, const_cast<char *>(aux7.c_str()));
                linha1++;
              mvprintw(linha1,12,"PREÇO:");
                aux6 = apresentacao.getPreco().getPreco();
                mvprintw(linha1,19, "%f", aux6);
                linha1++;
              mvprintw(linha1,12,"SALA:");
                x = apresentacao.getNumeroDeSala().getNumeroDeSala();
                mvprintw(linha1,18, "%d", x);
                linha1++;
              mvprintw(linha1,12,"INGRESSOS DISPONIVEIS:");
                x = apresentacao.getDisponibilidade().getDisponibilidade();
                mvprintw(linha1,35, "%d", x);
                linha1++;

                i++;
            }
            else {
              mvprintw(linha1,60,"COD. DE APRESENTACAO:");
                aux7 = apresentacao.getCodigoDeApresentacao().getCodigoDeApresentacao();
                mvprintw(linha1,82, const_cast<char *>(aux7.c_str()));
                linha1++;
              mvprintw(linha1,60,"DATA:");
                aux7 = apresentacao.getData().getData();
                mvprintw(linha1,66, const_cast<char *>(aux7.c_str()));
                linha1++;
              mvprintw(linha1,60,"HORARIO:");
                aux7 = apresentacao.getHorario().getHorario();
                mvprintw(linha1,69, const_cast<char *>(aux7.c_str()));
                linha1++;
              mvprintw(linha1,60,"PREÇO:");
                aux6 = apresentacao.getPreco().getPreco();
                mvprintw(linha1,68, "%f", aux6);
                linha1++;
              mvprintw(linha1,60,"SALA:");
                x = apresentacao.getNumeroDeSala().getNumeroDeSala();
                mvprintw(linha1,66, "%d", x);
                linha1++;
              mvprintw(linha1,60,"INGRESSOS DISPONIVEIS:");
                x = apresentacao.getDisponibilidade().getDisponibilidade();
                mvprintw(linha1,83, "%d", x);
                linha1++;

                i++;
            }
          }
         elemento2++;
     }

     aux3 = false;

    mvprintw(29,87,"0.RETORNAR");
    if(k != j-1)mvprintw(29,100,"2.PROXIMO>>");
    if(k != 0) mvprintw(29,72,"<<1.ANTERIOR");
    mvprintw(0,0,"");


    while(aux3 == false) {

     noecho();
     x = getch();
     echo();

     switch(x) {
       case 48:
         return 0;
       case 49:
         if(k != 0) {
          aux3 = true;
          elemento--;
          k--;
         }
         break;
       case 50:
         if(k != j-1) {
          k++;
          aux3 = true;
          elemento++;
         }
          break;
     }
    }
  }
}


bool cmdCadastrarEvento::executar(ISeventos* cntrlISeventos, _CPF CPF) {

  const static int LIMITE_EVENTOS = 0;
  const static int CADASTRAR_EVENTO = 1;
  const static int CADASTRAR_APRESENTACAO = 2;

  bool excecao = false, aux4 = false;
  int linha, coluna, aux = 0, aux3, i = 0, j;
  float aux5;
  char aux2[80];
  _codigoDeEvento codigoDeEvento;
  _nomeDoEvento nome;
  _cidade cidade;
  _estado estado;
  _classeDeEvento classe;
  _faixaEtaria faixa;
  _evento evento;
  _apresentacao apresentacao;
  _codigoDeApresentacao codigo;
  _data data;
  _horario horario;
  _preco preco;
  _numeroDeSala sala;
  _disponibilidade disponibilidade;

   //CHAMA O METODO CADASTRAR PEDINDO PARA VERIFICAR SE O USUARIO JA ATINGIU O LIMITE DE EVENTOS
   aux4 = cntrlISeventos->cadastrar(evento, apresentacao, CPF, LIMITE_EVENTOS);
    if(aux4 == false) {
      return false;
    }

   //FAZ A LEITURA DOS DADOS DO EVENTO
   initscr();
     clear();
     getmaxyx(stdscr,linha,coluna);
     mvprintw(linha/2 - 6,15,"COD. DE EVENTO:");
     mvprintw(linha/2 - 4,15,"NOME:");
     mvprintw(linha/2 - 2,15,"CIDADE:");
     mvprintw(linha/2,15,"ESTADO:");
     mvprintw(linha/2 + 2,15,"CLASSE:");
     mvprintw(linha/2 + 4,15,"FAIXA ETARIA:");
     mvprintw(linha/2 + 6,15,"QNTD DE APRESENTACOES:");

    while(true) {

     excecao = false;

       try {

        switch(aux) {
          case 0:
            mvprintw(linha/2 - 6,31,"");
            getstr(aux2);
            codigoDeEvento.setCodigoDeEvento(aux2);
            if(aux4 == false) break;
            aux++;
          case 1:
            mvprintw(linha/2 - 4,21,"");
            getstr(aux2);
            nome.setNomeDoEvento(aux2);
            aux++;
          case 2:
            mvprintw(linha/2 - 2,23,"");
            getstr(aux2);
            cidade.setCidade(aux2);
            aux++;
          case 3:
            mvprintw(linha/2,23,"");
            getstr(aux2);
            estado.setEstado(aux2);
            aux++;
          case 4:
            mvprintw(linha/2 + 2,23,"");
            getstr(aux2);
            sscanf (aux2,"%d",&aux3);
            classe.setClasseDeEvento(aux3);
            aux++;
          case 5:
            mvprintw(linha/2 + 4,29,"");
            getstr(aux2);
            faixa.setFaixaEtaria(aux2);
            aux++;
     }
    }
     catch (invalid_argument) {

       excecao = true;

        switch(aux) {
          case 0:
            mvprintw(linha/2 - 10,10, "COD. DE EVENTO EM FORMATO INVALIDO              ");
            mvprintw(linha/2 - 6,31, "              ");
            break;
          case 1:
            mvprintw(linha/2 - 10,10, "NOME EM FORMATO INVALIDO              ");
            mvprintw(linha/2 - 4,21, "              ");
            break;
          case 2:
            mvprintw(linha/2 - 10,10, "NOME DA CIDADE EM FORMATO INVALIDO              ");
            mvprintw(linha/2 - 2,23, "                  ");
            break;
          case 3:
            mvprintw(linha/2 - 10,10, "SIGLA DO ESTADO EM FORMATO INVALIDO              ");
            mvprintw(linha/2,23, "                  ");
            break;
          case 4:
            mvprintw(linha/2 - 10,10, "CLASSE EM FORMATO INVALIDO              ");
            mvprintw(linha/2 + 2,23, "                  ");
            break;
          case 5:
            mvprintw(linha/2 - 10,10, "FAIXA ETARIA EM FORMATO INVALIDO              ");
            mvprintw(linha/2 + 4,29, "                  ");
            break;
        }
     }


     if(excecao == false)  {

       aux4 = false;

       while(aux4 == false) {
          if(aux == 0) break;
          aux4 = true;
          mvprintw(linha/2 + 6,38,"");
          getstr(aux2);
          sscanf (aux2,"%d",&aux3);
            if(aux3 > 10) {
              mvprintw(linha/2 - 10,10, "QUANTIDADE INVALIDA: MIN 1 ~ MAX 5              ");
              mvprintw(linha/2 + 6,38, "                  ");
              aux4 = false;
            }
       }

       evento.setCodigoDeEvento(codigoDeEvento);
       evento.setNomeDoEvento(nome);
       evento.setCidade(cidade);
       evento.setEstado(estado);
       evento.setClasseDeEvento(classe);
       evento.setFaixaEtaria(faixa);

       //CHAMA O METODO DE CADASTRAMENTO PARA CADASTRAR O EVENTO E VERIFICAR SE O COD. DE EVENTO NAO FOI USADO
       aux4 = cntrlISeventos->cadastrar(evento, apresentacao, CPF, CADASTRAR_EVENTO);
        if(aux4 == false) {
          aux = 0;
          mvprintw(linha/2 - 10,10, "CODIGO DE EVENTO JA CADASTRADO        ");
          mvprintw(linha/2 - 9,14, "TENTE OUTRO CODIGO:");
          mvprintw(linha/2 - 6,31, "                  ");
        }
        else {
          aux = 0;
          i = 1;

          while(i <= aux3) {

            excecao = false;

            mvprintw(11,60, "APRESENTACAO %d/%d", i, aux3);
            mvprintw(13,60, "COD. DE APRESENTACAO:");
            mvprintw(14,60, "DATA DA APRESENTACAO:");
            mvprintw(15,60, "HORARIO:");
            mvprintw(16,60, "PREÇO:");
            mvprintw(17,60, "SALA:");
            mvprintw(18,60, "DISPONIBILIDADE:");

            try {

              switch(aux) {
                case 0:
                  mvprintw(13,82, "");
                  getstr(aux2);
                  codigo.setCodigoDeApresentacao(aux2);
                  if(aux4 == false) break;
                  aux++;
                case 1:
                  mvprintw(14,82, "");
                  getstr(aux2);
                  data.setData(aux2);
                  aux++;
                case 2:
                  mvprintw(15,69, "");
                  getstr(aux2);
                  horario.setHorario(aux2);
                  aux++;
                case 3:
                  mvprintw(16,67, "");
                  getstr(aux2);
                  sscanf (aux2,"%f",&aux5);
                  preco.setPreco(aux5);
                  aux++;
                case 4:
                  mvprintw(17,66, "");
                  getstr(aux2);
                  sscanf (aux2,"%d",&j);
                  sala.setNumeroDeSala(j);
                  aux++;
                case 5:
                  mvprintw(18,77, "");
                  getstr(aux2);
                  sscanf (aux2,"%d",&j);
                  disponibilidade.setDisponibilidade(j);
              }
            }

            catch(invalid_argument) {

              excecao = true;

              switch(aux) {
                case 0:
                  mvprintw(8,60, "CODIGO DE APRESENTACAO EM FORMATO INVALIDO");
                  mvprintw(13,82, "                                  ");
                  break;
                case 1:
                  mvprintw(8,60, "DATA EM FORMATO INVALIDO                  ");
                  mvprintw(14,82, "                                  ");
                  break;
                case 2:
                  mvprintw(8,60, "HORARIO EM FORMATO INVALIDO               ");
                  mvprintw(15,69, "                                  ");
                  break;
                case 3:
                  mvprintw(8,60, "PRECO EM FORMATO INVALIDO                 ");
                  mvprintw(16,68, "                                  ");
                  break;
                case 4:
                  mvprintw(8,60, "NUMERO DE SALA EM FORMATO INVALIDO        ");
                  mvprintw(17,66, "                                  ");
                  break;
                case 5:
                  mvprintw(8,60, "DISPONIBILIDADE EM FORMATO INVALIDO       ");
                  mvprintw(18,77, "                                  ");
                  break;
              }
            }

            if(excecao == false) {
              apresentacao.setCodigoDeApresentacao(codigo);
              apresentacao.setData(data);
              apresentacao.setHorario(horario);
              apresentacao.setPreco(preco);
              apresentacao.setNumeroDeSala(sala);
              apresentacao.setDisponibilidade(disponibilidade);
              apresentacao.setCodigoDeEvento2(codigoDeEvento);

              aux4 = cntrlISeventos->cadastrar(evento, apresentacao, CPF, CADASTRAR_APRESENTACAO);
               if(aux4 == false) {
                 aux = 0;
                 mvprintw(8,60, "CODIGO DE APRESENTACAO JA CADASTRADO       ");
                 mvprintw(9,67, "TENTE OUTRO CODIGO      ");
                 mvprintw(13,82, "                                  ");
               }
               else {
                 if(i == aux3) return true;
                 mvprintw(13,82, "                                  ");
                 mvprintw(14,82, "                                  ");
                 mvprintw(15,69, "                                  ");
                 mvprintw(16,67, "                                  ");
                 mvprintw(17,66, "                                  ");
                 mvprintw(18,77, "                                  ");
                 i++;
                 aux = 0;
               }
            }
          }
        }
     }
    }
}


int cmdEditarEvento::executar(ISeventos* cntrlISeventos, _CPF CPF) {

   const static int EDITAR_EVENTO = 0;
   const static int EDITAR_APRESENTACAO = 1;
   const static int EVENTO_NAO_ENCONTRADO = 2;
   const static int INGRESSO_VENDIDO = 3;

   int linha, coluna, aux3, escolha, qntdElemento = 0, pagina;
   float aux6;
   bool excecao = false, aux, aux4, alterarApresentacao = false;
   char aux2[80];
   string aux5;
   list<_apresentacao> lista;
   _codigoDeEvento codigoDeEvento, codigo1;
   _codigoDeApresentacao codigoDeApresentacao, codigo2;
   _evento evento;
   _apresentacao apresentacao;
   _nomeDoEvento nome;
   _cidade cidade;
   _estado estado;
   _classeDeEvento classe;
   _faixaEtaria faixa;
   _data data;
   _horario horario;
   _preco preco;
   _numeroDeSala sala;
   _disponibilidade disponibilidade;

   //BUSCA PELO EVENTO
     initscr();
      clear();
      getmaxyx(stdscr,linha,coluna);
      mvprintw(linha/2 - 4,coluna/2 - 24,"DIGITE O CODIGO DO EVENTO QUE DESEJA ALTERAR:");
      mvprintw(linha/2,coluna/2 - 12,"CODIGO DE EVENTO:");

      aux = false;

      while(aux == false) {
        aux = true;
        try {
          mvprintw(linha/2,coluna/2+6,"");
          getstr(aux2);
          codigo1.setCodigoDeEvento(aux2);
        }
        catch(invalid_argument) {
          aux = false;
          mvprintw(linha/2 - 6,coluna/2-20, "COD. DE EVENTO EM FORMATO INVALIDO");
          mvprintw(linha/2,coluna/2+6, "              ");
        }
      }

      aux = cntrlISeventos->pesquisarMeuEvento(codigo1, &evento, &lista);
        if(aux == false) return EVENTO_NAO_ENCONTRADO;

      if(evento.getCPF().getCPF() != CPF.getCPF()) return 2;

      list<_apresentacao>::iterator elemento = lista.begin();

      //VERIFICA SE HA INGRESSO VENDIDO EM UMA DAS APRESENTACOES DO EVENTO
      while(elemento != lista.end()) {
        apresentacao = *elemento;
        if((apresentacao.getQuantiadeVendida()) > 0)
          return INGRESSO_VENDIDO;
        elemento++;
      }

      elemento = lista.begin();

   //FIM DA PESQUISA PELO EVENTO

   //LOGISTICA DE EDICAO DE DADOS

     clear();
     getmaxyx(stdscr,linha,coluna);

     mvprintw(linha/2 - 6,15,"0. COD. DE EVENTO:");
       aux5 = evento.getCodigoDeEvento().getCodigoDeEvento();
       mvprintw(linha/2 - 6,34, const_cast<char *>(aux5.c_str()));
     mvprintw(linha/2 - 4,15,"1. NOME:");
       aux5 = evento.getNomeDoEvento().getNomeDoEvento();
       mvprintw(linha/2 - 4,24, const_cast<char *>(aux5.c_str()));
     mvprintw(linha/2 - 2,15,"2. CIDADE:");
       aux5 = evento.getCidade().getCidade();
       mvprintw(linha/2 - 2,26, const_cast<char *>(aux5.c_str()));
     mvprintw(linha/2,15,"3. ESTADO:");
       aux5 = evento.getEstado().getEstado();
       mvprintw(linha/2,26, const_cast<char *>(aux5.c_str()));
     mvprintw(linha/2 + 2,15,"4. CLASSE:");
       aux3 = evento.getClasseDeEvento().getClasseDeEvento();
       mvprintw(linha/2 + 2,26, "%d", aux3);
     mvprintw(linha/2 + 4,15,"5. FAIXA ETARIA:");
       aux5 = evento.getFaixaEtaria().getFaixaEtaria();
       mvprintw(linha/2 + 4,32, const_cast<char *>(aux5.c_str()));
     mvprintw(linha/2 + 6,15,"6. ALTERAR APRESENTACOES");

     while(elemento != lista.end()) {
        qntdElemento++;
        elemento++;
     }


      while(true) {

        aux = false;
        mvprintw(linha/2 + 10,20, "7.RETORNAR");

        try {

         if(excecao == false) {
           noecho();
           escolha = getch();
           echo();
         }

        switch(escolha) {
          case 48:
            while(aux == false) {
              aux = true;
              mvprintw(linha/2 - 6,34, "                      ");
              mvprintw(linha/2 - 6,34,"");
              getstr(aux2);
               if(aux2 != codigo1.getCodigoDeEvento()) {
                 codigoDeEvento.setCodigoDeEvento(aux2);
                 evento.setCodigoDeEvento(codigoDeEvento);
                 aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_EVENTO);
                  if(aux4 == false) {
                    mvprintw(linha/2 - 10,10, "COD. DE EVENTO JA ESTA EM USO");
                    aux = false;
                  }
                  else {
                    codigo1.setCodigoDeEvento(aux2);
                  }
               }
            }
            break;
          case 49:
            mvprintw(linha/2 - 4,24,"                           ");
            mvprintw(linha/2 - 4,24,"");
            getstr(aux2);
            nome.setNomeDoEvento(aux2);
            evento.setNomeDoEvento(nome);
            aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_EVENTO);
            break;
          case 50:
            mvprintw(linha/2 - 2,26,"                       ");
            mvprintw(linha/2 - 2,26,"");
            getstr(aux2);
            cidade.setCidade(aux2);
            evento.setCidade(cidade);
            aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_EVENTO);
            break;
          case 51:
            mvprintw(linha/2,26,"                        ");
            mvprintw(linha/2,26,"");
            getstr(aux2);
            estado.setEstado(aux2);
            evento.setEstado(estado);
            aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_EVENTO);
            break;
          case 52:
            mvprintw(linha/2 + 2,26,"                    ");
            mvprintw(linha/2 + 2,26,"");
            getstr(aux2);
            sscanf (aux2,"%d",&aux3);
            classe.setClasseDeEvento(aux3);
            evento.setClasseDeEvento(classe);
            aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_EVENTO);
            break;
          case 53:
            mvprintw(linha/2 + 4,32,"                    ");
            mvprintw(linha/2 + 4,32,"");
            getstr(aux2);
            faixa.setFaixaEtaria(aux2);
            evento.setFaixaEtaria(faixa);
            aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_EVENTO);
            break;
          case 54:
            alterarApresentacao = true;
            break;
          case 55:
            return 0;
         }
          excecao = false;
        }

     catch (invalid_argument) {

       excecao = true;

       switch(escolha) {
          case 48:
            mvprintw(linha/2 - 10,10, "COD. DE EVENTO EM FORMATO INVALIDO");
            break;
          case 49:
            mvprintw(linha/2 - 10,10, "NOME EM FORMATO INVALIDO           ");
            break;
          case 50:
            mvprintw(linha/2 - 10,10, "NOME DA CIDADE EM FORMATO INVALIDO");
            break;
          case 51:
            mvprintw(linha/2 - 10,10, "SIGLA DO ESTADO EM FORMATO INVALIDO");
            break;
          case 52:
            mvprintw(linha/2 - 10,10, "CLASSE EM FORMATO INVALIDO         ");
            break;
          case 53:
            mvprintw(linha/2 - 10,10, "FAIXA ETARIA EM FORMATO INVALIDO   ");
            break;
        }
     }


      if(alterarApresentacao == true) {

       elemento = lista.begin();
       apresentacao = *elemento;
       pagina = 0;

       mvprintw(11,60, "APRESENTACAO 1/%d", qntdElemento);
       mvprintw(13,60, "0. COD. DE APRESENTACAO:");
       mvprintw(14,60, "1. DATA DA APRESENTACAO:");
       mvprintw(15,60, "2. HORARIO:");
       mvprintw(16,60, "3. PREÇO:");
       mvprintw(17,60, "4. SALA:");
       mvprintw(18,60, "5. DISPONIBILIDADE:");
       mvprintw(19,60, "6. ALTERAR EVENTO");

       elemento = lista.begin();
       apresentacao = *elemento;
       codigo2 = apresentacao.getCodigoDeApresentacao();

       while(alterarApresentacao == true) {

         mvprintw(11,60, "APRESENTACAO %d/%d", pagina+1, qntdElemento);
         aux5 = apresentacao.getCodigoDeApresentacao().getCodigoDeApresentacao();
         mvprintw(13,85, const_cast<char *>(aux5.c_str()));
         aux5 = apresentacao.getData().getData();
         mvprintw(14,85, const_cast<char *>(aux5.c_str()));
         aux5 = apresentacao.getHorario().getHorario();
         mvprintw(15,72, const_cast<char *>(aux5.c_str()));
         aux6 = apresentacao.getPreco().getPreco();
         mvprintw(16,70, "%.2f", aux6);
         aux3 = apresentacao.getNumeroDeSala().getNumeroDeSala();
         mvprintw(17,69, "%d", aux3);
         aux3 = apresentacao.getDisponibilidade().getDisponibilidade();
         mvprintw(18,80, "%d", aux3);

         if(pagina != 0) mvprintw(21,60, "<<8.ANTERIOR");
          else mvprintw(21,60, "              ");
         if(pagina != (qntdElemento-1)) mvprintw(21,86, "9.PROXIMO>>");
          else mvprintw(21,86, "              ");

         aux = false;

         try {

           if(excecao == false) {
             noecho();
             escolha = getch();
             echo();
           }

           switch(escolha) {
              case 48:
                while(aux == false) {
                  aux = true;
                  mvprintw(13,85, "                     ");
                  mvprintw(13,85, "");
                  getstr(aux2);
                   if(aux2 != codigo2.getCodigoDeApresentacao()) {
                     codigoDeApresentacao.setCodigoDeApresentacao(aux2);
                     apresentacao.setCodigoDeApresentacao(codigoDeApresentacao);
                     aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_APRESENTACAO);
                      if(aux4 == false) {
                        mvprintw(linha/2 - 10,10, "COD. DE APRESENTACAO JA ESTA EM USO");
                        aux = false;
                      }
                      else {
                        codigo2.setCodigoDeApresentacao(aux2);
                        lista.insert(elemento,1,apresentacao);
                        elemento = lista.erase(elemento);
                        elemento--;
                      }
                   }
                }
                 aux = false;
                 break;
              case 49:
                mvprintw(14,85, "                     ");
                mvprintw(14,85, "");
                getstr(aux2);
                data.setData(aux2);
                apresentacao.setData(data);
                lista.insert(elemento,1,apresentacao);
                elemento = lista.erase(elemento);
                elemento--;
                aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_APRESENTACAO);
                break;
              case 50:
                mvprintw(15,72, "                     ");
                mvprintw(15,72, "");
                getstr(aux2);
                horario.setHorario(aux2);
                apresentacao.setHorario(horario);
                lista.insert(elemento,1,apresentacao);
                elemento = lista.erase(elemento);
                elemento--;
                aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_APRESENTACAO);
                break;
              case 51:
                mvprintw(16,70, "                     ");
                mvprintw(16,70, "");
                getstr(aux2);
                sscanf (aux2,"%f",&aux6);
                preco.setPreco(aux6);
                apresentacao.setPreco(preco);
                lista.insert(elemento,1,apresentacao);
                elemento = lista.erase(elemento);
                elemento--;
                aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_APRESENTACAO);
                break;
              case 52:
                mvprintw(17,69, "                     ");
                mvprintw(17,69, "");
                getstr(aux2);
                sscanf (aux2,"%d",&aux3);
                sala.setNumeroDeSala(aux3);
                apresentacao.setNumeroDeSala(sala);
                lista.insert(elemento,1,apresentacao);
                elemento = lista.erase(elemento);
                elemento--;
                aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_APRESENTACAO);
                break;
              case 53:
                mvprintw(18,80, "                     ");
                mvprintw(18,80, "");
                getstr(aux2);
                sscanf (aux2,"%d",&aux3);
                disponibilidade.setDisponibilidade(aux3);
                apresentacao.setDisponibilidade(disponibilidade);
                lista.insert(elemento,1,apresentacao);
                elemento = lista.erase(elemento);
                elemento--;
                aux4 = cntrlISeventos->alterar(evento, apresentacao, codigo2, codigo1, EDITAR_APRESENTACAO);
                break;
              case 54:
                alterarApresentacao = false;
                break;
              case 55:
                return 0;
              case 56:
                if(pagina != 0) {
                  elemento--;
                  apresentacao = *elemento;
                  codigo2 = apresentacao.getCodigoDeApresentacao();
                  pagina--;
                }
                break;
              case 57:
                if(pagina != qntdElemento-1) {
                  mvprintw(0,0,"              ");
                  elemento++;
                  apresentacao = *elemento;
                  codigo2 = apresentacao.getCodigoDeApresentacao();
                  pagina++;
                }
                break;
           }
              excecao = false;
         }

         catch(invalid_argument) {

            excecao = true;

              switch(escolha) {
                case 48:
                  mvprintw(8,60, "CODIGO DE APRESENTACAO EM FORMATO INVALIDO");
                  break;
                case 49:
                  mvprintw(8,60, "DATA EM FORMATO INVALIDO                  ");
                  break;
                case 50:
                  mvprintw(8,60, "HORARIO EM FORMATO INVALIDO               ");
                  break;
                case 51:
                  mvprintw(8,60, "PRECO EM FORMATO INVALIDO                 ");
                  break;
                case 52:
                  mvprintw(8,60, "NUMERO DE SALA EM FORMATO INVALIDO        ");
                  break;
                case 53:
                  mvprintw(8,60, "DISPONIBILIDADE EM FORMATO INVALIDO       ");
                  break;
              }
            }

        if(alterarApresentacao == false) {
          mvprintw(11,60, "                                             ");
          mvprintw(13,60, "                                             ");
          mvprintw(14,60, "                                             ");
          mvprintw(15,60, "                                             ");
          mvprintw(16,60, "                                             ");
          mvprintw(17,60, "                                             ");
          mvprintw(18,60, "                                             ");
          mvprintw(19,60, "                                             ");
          mvprintw(21,60, "                                             ");
          mvprintw(0,0, "");
        }
       }
      }
      }
}


bool cmdDadosDeVenda::executar(ISeventos* cntrlISeventos, _CPF CPF) {

    int linha, coluna, i, pagina = 0, qntDeElementos = 0, j, k, z;
    char aux2[80];
    bool aux = false;
    string aux3;
    list<_apresentacao> lista;
    _evento evento;
    _codigoDeEvento codigoDeEvento;
    _apresentacao apresentacao;

    initscr();
      clear();
      getmaxyx(stdscr,linha,coluna);
      mvprintw(linha/2 - 4,coluna/2 - 32,"DIGITE O CODIGO DO EVENTO QUE DESEJA ACESSAR AS INFORMACOES:");
      mvprintw(linha/2,coluna/2 - 12,"CODIGO DE EVENTO:");

      while(aux == false) {
        aux = true;
        try {
          mvprintw(linha/2,coluna/2+6,"");
          getstr(aux2);
          codigoDeEvento.setCodigoDeEvento(aux2);
        }
        catch(invalid_argument) {
          aux = false;
          mvprintw(linha/2 - 6,coluna/2-20, "COD. DE EVENTO EM FORMATO INVALIDO");
          mvprintw(linha/2,coluna/2+6, "              ");
        }
      }

      aux = cntrlISeventos->pesquisarMeuEvento(codigoDeEvento, &evento, &lista);
       if(aux == false) return false;

       if(evento.getCPF().getCPF() != CPF.getCPF()) return false;

      list<_apresentacao>::iterator elemento = lista.begin();

      while(elemento != lista.end()) {
        qntDeElementos++;
        elemento++;
      }

      elemento = lista.begin();

      clear();

      apresentacao = *elemento;

      while(true) {

        clear();
        aux3 = codigoDeEvento.getCodigoDeEvento();
        mvprintw(0,0, "CODIGO DO EVENTO:");
        mvprintw(0,18, const_cast<char *>(aux3.c_str()));
        mvprintw(1,0, "CODIGO DA APRESENTACAO:");
        mvprintw(1,32, "INGRESSOS VENDIDOS:");
         for(i=0; i<120; i++) mvprintw(2,i, "-");
        mvprintw(3,0, "CPF DOS COMPRADORES:");

        mvprintw(0,115, "%d/%d", pagina+1, qntDeElementos);
        aux3 = apresentacao.getCodigoDeApresentacao().getCodigoDeApresentacao();
        mvprintw(1,24, const_cast<char *>(aux3.c_str()));
        z = apresentacao.getQuantiadeVendida();
        mvprintw(1,52, "%d", z);

        k = apresentacao.getPosicaoLista();
        i = 4;
        j = 0;


        for(z = 0; z < k; z++) {
           aux3 = apresentacao.getCPFcomprador(z).getCPF();;
           mvprintw(i,j, const_cast<char *>(aux3.c_str()));
           j = j + 17;
           if(j == 119) {
             i++;
             j = 0;
           }
        }


        if(pagina != 0) mvprintw(1,81, "<<1.ANTERIOR");
          else mvprintw(1,81, "            ");
        mvprintw(1,95, "0.RETORNAR");
        if(pagina != (qntDeElementos-1)) mvprintw(1,107, "2.PROXIMO>>");
          else mvprintw(1,107, "           ");

        noecho();
        z = getch();
        echo();

        switch(z) {
          case 48:
            return true;
          case 49:
            if(pagina != 0) {
              elemento--;
              apresentacao = *elemento;
              pagina--;
            }
            break;
          case 50:
            if(pagina != (qntDeElementos-1)) {
              elemento++;
              apresentacao = *elemento;
              pagina++;
            }
            break;
        }

      }

}


int cmdExcluirEvento::executar(ISeventos* cntrlISeventos, _CPF CPF) {

    const static int EXCLUSAO_CANCELADA = 0;
    const static int EXCLUIDO_SUCESSO = 1;
    const static int INGRESSO_VENDIDO = 2;

    int linha, coluna, x;
    char aux2[80];
    bool aux = false;
    _codigoDeEvento codigoDeEvento;


     initscr();
      clear();
      getmaxyx(stdscr,linha,coluna);
      mvprintw(linha/2 - 4,coluna/2 - 24,"DIGITE O CODIGO DO EVENTO QUE DESEJA EXCLUIR:");
      mvprintw(linha/2,coluna/2 - 12,"CODIGO DE EVENTO:");

      while(aux == false) {
        aux = true;
        try {
          mvprintw(linha/2,coluna/2+6,"");
          getstr(aux2);
          codigoDeEvento.setCodigoDeEvento(aux2);
        }
        catch(invalid_argument) {
          aux = false;
          mvprintw(linha/2 - 6,coluna/2-20, "COD. DE EVENTO EM FORMATO INVALIDO");
          mvprintw(linha/2,coluna/2+6, "              ");
        }
      }

      clear();
      mvprintw(linha/2,(coluna)/2 - 27,"TEM CERTEZA QUE DESEJA EXCLUIR A CONTA? (0. SIM / 1. NAO)");
      x = getch();

      if(x == 49) return EXCLUSAO_CANCELADA;
       else if(x == 48) {
          aux = cntrlISeventos->excluirEvento(codigoDeEvento);
            if(aux == false) return INGRESSO_VENDIDO;
             else return EXCLUIDO_SUCESSO;
       }

}















































