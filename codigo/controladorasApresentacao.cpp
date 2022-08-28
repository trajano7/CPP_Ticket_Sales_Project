#include <iostream>
#include "entidades.h"
#include "dominios.h"
#include "controladorasApresentacao.h"
#include "curses.h"
#include "stubs.h"
#include "comandosApresentacao.h"
#include <string>

using namespace std;

void cntrlIAcentral::executar() {

 const static int USUARIO_CADASTRADO_ERRO = 0;
 const static int USUARIO_CADASTRADO =1;
 const static int FALHA_PESQUISA = 2;

 int linha, coluna, resposta, x;
 _CPF CPF;
 bool logado = false, aux;

   while(true) {

     if(logado == false) {

       initscr();
        clear();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2 - 2,(coluna)/2 - 10,"0. FAZER LOGIN");
        mvprintw(linha/2,(coluna)/2 - 10,"1. CADASTRAR CONTA");
        mvprintw(linha/2 + 2,(coluna)/2 - 10,"2. PESQUISAR EVENTOS");
        mvprintw(0,0,"");

       if(resposta == USUARIO_CADASTRADO_ERRO) {
         mvprintw(linha/2 - 6,(coluna)/2 - 6,"NAO FOI POSSIVEL CADASTAR:");
         mvprintw(linha/2 - 5,(coluna)/2 - 3,"USUARIO JA CADASTRADO");
       }
       if(resposta == USUARIO_CADASTRADO) {
         mvprintw(linha/2 - 6,(coluna)/2 - 6,"USUARIO CADASTRADO COM SUCESSO");
         mvprintw(linha/2 - 5,(coluna)/2 - 6,"                       ");
       }
       if(resposta == FALHA_PESQUISA) {
         mvprintw(linha/2 - 6,(coluna)/2 - 10,"NAO FOI ENCONTRADO NENHUM EVENTO NESSE FILTRO");
         mvprintw(linha/2 - 5,(coluna)/2 - 6,"                          ");
       }
       resposta = -1;

       noecho();
        x = getch();
       echo();

       switch(x) {
         case LOGIN:
           cntrlaIAautenticacao->autenticar(&CPF);
           logado = true;
          break;
         case CADASTRAR:
           aux = cntrlaIAusuario->executarUsuario(CPF,false);
            if(aux == false) resposta = USUARIO_CADASTRADO_ERRO;
             else resposta = USUARIO_CADASTRADO;
         break;
        case PESQUISAR:
          aux = cntrlaIAeventos->executarEventos(CPF,false);
           if(aux == false) resposta = FALHA_PESQUISA;
         break;
      }
     }

     else {

       if(resposta == FALHA_PESQUISA) {
         mvprintw(linha/2 - 6,(coluna)/2 - 10,"NAO FOI ENCONTRADO NENHUM EVENTO NESSE FILTRO");
         mvprintw(linha/2 - 5,(coluna)/2 - 6,"                          ");
       }
       resposta = -1;

       initscr();
        clear();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2 - 4,(coluna)/2 - 10,"0. MENU DE USUARIO");
        mvprintw(linha/2 - 2,(coluna)/2 - 10,"1. MENU DE EVENTOS");
        mvprintw(linha/2,(coluna)/2 - 10,"2. PESQUISAR EVENTOS");
        mvprintw(linha/2 + 2,(coluna)/2 - 10,"3. COMPRAR INGRESSOS");
        mvprintw(linha/2 + 4,(coluna)/2 - 10,"4. SAIR");
        mvprintw(0,0,"");

        noecho();
        x = getch();
        echo();

        switch(x) {
         case MENU_USUARIO:
           aux = cntrlaIAusuario->executarUsuario(CPF,true);
           if(aux == true) logado = false; //exclusao de conta
          break;
         case MENU_EVENTOS:
           cntrlaIAeventos->executarEventos(CPF, true);
         break;
        case PESQUISAR:
          aux = cntrlaIAeventos->executarEventos(CPF,false);
           if(aux == false) resposta = FALHA_PESQUISA;
         break;
        case COMPRAR:
          cntrlaIAvendas->comprar(CPF);
         break;
        case SAIR:
          logado = false;
          break;
        }
     }

   }


}

//IMPLEMENTACAO DOS METODOS DA CONTROLADORA DE AUTENTICACAO
bool cntrlIAautenticacao::autenticar(_CPF *CPF) {

   _CPF CPF2;
   _senha senha;
   char auxiliar2[80];
   bool a = false;
   int linha, coluna;

     while(true) {
       initscr();
       clear();
        if(a == true) {
          getmaxyx(stdscr,linha,coluna);
          mvprintw(linha/2 - 3,(coluna-4)/2,"CPF ou senha invalido");
          mvprintw(linha/2 - 2,(coluna-4)/2,"Tente novamente:");
          a = false;
        }
        try {
          getmaxyx(stdscr,linha,coluna);
          mvprintw(linha/2 - 1,(coluna-13)/2,"DIGITE O CPF:");
          mvprintw(linha/2 + 1,(coluna-14)/2,"DIGITE A SENHA:");
          mvprintw(linha/2 - 1,(coluna+13)/2 + 1,"");
           getstr(auxiliar2);
           CPF2.setCPF(auxiliar2);
          mvprintw(linha/2 + 1,(coluna+14)/2 + 2,"");
           getstr(auxiliar2);
           senha.setSenha(auxiliar2);
       }
       catch (invalid_argument erro) {
          a = true;
       }
        endwin();

       if(a == false) {


         //CHAMA A AUTENTICACAO NA CAMADA DE SERVICO
         a = cntrlISautenticacao->autenticar(CPF2,senha);

         if(a == true) {
           *CPF = CPF2;
           return true;
         }
          else a = true;

       }
    }

}

//IMPLEMENTACAO DOS METODOS DA CONTROLADORA DE USUARIO
bool cntrlIAusuario::executarUsuario(_CPF CPF, bool logado) {

    cmdCadastrar *comandoCadastrar;
    cmdExcluir *comandoExluir;
    cmdMeusDados *comandoMeusDados;
    int aux;
    int i, linha, coluna;



     //CASO O MODULO DE USUARIO ESTEJA SENDO CHAMADO DE UM SISTEMA NAO LOGADO
     if(logado == false) {
       comandoCadastrar = new cmdCadastrar;
       aux = comandoCadastrar->executar(cntrlISusuario);
       delete comandoCadastrar;
       if(aux == 1) return false;
        else if(aux == 0) return true;
     }

     //CASO O MODULO DE USUARIO ESTEJA SENDO CHAMADO DE UM SISTEMA LOGADO
     else {

      while(true) {
       initscr();
       clear();
       getmaxyx(stdscr,linha,coluna);
        if(aux == 2) mvprintw(linha/2 - 4,(coluna)/2 - 15,"NAO FOI POSSIVEL EXCLUIR A CONTA:");
        if(aux == 2) mvprintw(linha/2 - 3,(coluna)/2 - 22,"AINDA EXISTE ALGUM EVENTO CADASTRADO NA SUA CONTA");
        mvprintw(linha/2,(coluna)/2 - 6,"1. EXCLUIR CONTA");
        mvprintw(linha/2 + 2,(coluna)/2 - 6,"2. MEUS DADOS");
        mvprintw(linha/2 + 4,(coluna)/2 - 6,"0. RETORNAR");
        mvprintw(0,0,"");
        noecho();
        i = getch();
        echo();

       switch(i) {
          case RETORNAR:
            return false;
            break;
          case MEUSDADOS:
            comandoMeusDados = new cmdMeusDados;
            comandoMeusDados->executar(cntrlISusuario,CPF);
            break;
          case EXCLUIR:
            comandoExluir = new cmdExcluir;
            aux = comandoExluir->executar(cntrlISusuario,CPF);
             if(aux == 0) return true;
            delete comandoExluir;
       }
      }

     }

}


//IMPLEMENTACAO DOS METODOS DA CONTROLADORA DE EVENTOS
bool cntrlIAeventos::executarEventos(_CPF CPF, bool logado) {

   const static int LIMITE_EVENTOS = 0;
   const static int FALHA_PESQUISA = 1;
   const static int EVENTO_NAO_ENCONTRADO = 2;
   const static int INGRESSO_VENDIDO = 3;
   const static int EXCLUIDO_SUCESSO = 4;
   const static int EVENTO_NAO_ENCONTRADO_2 = 5;

   int aux, aux2, linha, coluna, i, resposta=-1;
   bool aux3;
   cmdPesquisarEventos *comandoPesquisar;
   cmdCadastrarEvento *comandoCadastrar;
   cmdEditarEvento *comandoEditar;
   cmdDadosDeVenda *comandoDadosDeVenda;
   cmdExcluirEvento *comandoExcluirEvento;

     if(logado == false) {
       comandoPesquisar = new cmdPesquisarEventos;
       aux = comandoPesquisar->executar(cntrlISeventos,CPF);
       delete comandoPesquisar;
         if(aux == 1) return false;
           else return true;
     }

     else {
       while(true) {

        initscr();
         clear();
         getmaxyx(stdscr,linha,coluna);

         if(resposta == FALHA_PESQUISA)
           mvprintw(linha/2 - 10,(coluna)/2 - 20,"NAO FOI ENCONTRADO NENHUM EVENTO NESSE FILTRO                                      ");
         if(resposta == LIMITE_EVENTOS)
           mvprintw(linha/2 - 10,(coluna)/2 - 20,"NAO EH POSSIVEL CADASTRAR EVENTO: NUMERO MAXIMO ATINGIDO                           ");
         if(resposta == EVENTO_NAO_ENCONTRADO)
           mvprintw(linha/2 - 10,(coluna)/2 - 20,"O EVENTO PROCURADO NAO EXISTE                                                      ");
         if(resposta == INGRESSO_VENDIDO)
           mvprintw(linha/2 - 10,(coluna)/2 - 37,"NAO EH POSSIVEL ALTERAR OU EXCLUIR ESSE EVENTO: JA EXISTE INGRESSO VENDIDO PARA ELE");
         if(resposta == EXCLUIDO_SUCESSO)
           mvprintw(linha/2 - 10,(coluna)/2 - 20,"EVENTO EXCLUIDO COM SUCESSO"                                                        );
         if(resposta == EVENTO_NAO_ENCONTRADO_2)
           mvprintw(linha/2 - 10,(coluna)/2 - 20,"NENHUM EVENTO COM O CODIGO DIGITADO FOI ENCONTRADO EM SEU CPF                      ");
         resposta = -1;


         mvprintw(linha/2 - 6,(coluna)/2 - 10,"1. PESQUISAR EVENTOS");
         mvprintw(linha/2 - 4,(coluna)/2 - 10,"2. CADASTRAR EVENTO");
         mvprintw(linha/2 - 2,(coluna)/2 - 10,"3. EDITAR EVENTO");
         mvprintw(linha/2,(coluna)/2 - 10,"4. INFO. DE EVENTO");
         mvprintw(linha/2 + 2,(coluna)/2 - 10,"5. EXCLUIR EVENTO");
         mvprintw(linha/2 + 4,(coluna)/2 - 10,"0. RETORNAR");
         mvprintw(0,0,"");
         noecho();
         i = getch();
         echo();

       switch(i) {
          case RETORNAR:
            return false;
            break;
          case PESQUISAR_EVENTO:
            comandoPesquisar = new cmdPesquisarEventos;
            aux = comandoPesquisar->executar(cntrlISeventos,CPF);
            delete comandoPesquisar;
             if(aux == 1) resposta = FALHA_PESQUISA;
             break;
          case CADASTRAR_EVENTO:
            comandoCadastrar = new cmdCadastrarEvento;
            aux3 = comandoCadastrar->executar(cntrlISeventos, CPF);
            if(aux3 == false) resposta = LIMITE_EVENTOS;
            delete comandoCadastrar;
            break;
          case EDITAR_EVENTO:
            comandoEditar = new cmdEditarEvento;
            aux = comandoEditar->executar(cntrlISeventos, CPF);
             if(aux == 2) resposta = EVENTO_NAO_ENCONTRADO_2;
             if(aux == 3) resposta = INGRESSO_VENDIDO;
            break;
          case MEU_EVENTO:
            comandoDadosDeVenda = new cmdDadosDeVenda;
            aux3 = comandoDadosDeVenda->executar(cntrlISeventos, CPF);
             if(aux3 == false) resposta = EVENTO_NAO_ENCONTRADO_2;
            break;
          case EXCLUIR_EVENTO:
            comandoExcluirEvento = new cmdExcluirEvento;
            aux = comandoExcluirEvento->executar(cntrlISeventos, CPF);
             if(aux == 1) resposta = EXCLUIDO_SUCESSO;
              else if(aux == 2) resposta = INGRESSO_VENDIDO;
            break;
       }
      }

     }

     return true;


}


//IMPLEMENTACAO DOS METODOS DA CONTROLADORA DE VENDAS
int cntrlIAvendas::comprar(_CPF CPF) {

    const static int APRESENTACAO_NAO_ENCONTRADA = 1;


   int linha, coluna, quantidade, quantidade2;
   bool aux = false, aux3;
   char aux2[80];
   _codigoDeApresentacao codigoDeApresentacao;


   initscr();
      clear();
      getmaxyx(stdscr,linha,coluna);
      mvprintw(linha/2 - 4,coluna/2 - 29,"DIGITE O CODIGO DA APRESENTACAO QUE DESEJA COMPRAR INGRESSO:");
      mvprintw(linha/2,coluna/2 - 12,"CODIGO DE APRESENTACAO:");
      mvprintw(linha/2 + 2,coluna/2 - 12,"QUANTIDADE DE INGRESSOS:");

      while(aux == false) {
        aux = true;
        try {
          mvprintw(linha/2,coluna/2+12,"");
          getstr(aux2);
          codigoDeApresentacao.setCodigoDeApresentacao(aux2);
        }
        catch(invalid_argument) {
          aux = false;
          mvprintw(linha/2 - 7,coluna/2-20, "COD. DE APRESENTACAO EM FORMATO INVALIDO");
          mvprintw(linha/2,coluna/2+12, "                       ");
        }
      }

      aux = false;
      aux3 = true;

      while(aux == false) {
        aux = true;
         if(aux3 == false) {
           mvprintw(linha/2+ 2,coluna/2+13,"                      ");
           mvprintw(linha/2 - 7,coluna/2-22, "QUANTIDADE DE INGRESSOS SOLICITADA INDISPONIVEL:");
           mvprintw(linha/2 - 6,coluna/2-12, "QUANTIDADE DISPONIVEL: %d                      ", quantidade);
         }

        mvprintw(linha/2+ 2,coluna/2+13,"");
        getstr(aux2);
        sscanf(aux2,"%d",&quantidade);
        quantidade2 = quantidade;
        aux3 = cntrlISvendas->comprar(CPF, codigoDeApresentacao, &quantidade);
         if(aux3 == false) {
           if(quantidade2 > quantidade) return APRESENTACAO_NAO_ENCONTRADA;
            aux = false;
         }

      }

      return 0;

}





