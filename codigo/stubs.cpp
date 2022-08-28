#include "stubs.h"
#include "curses.h"

bool stubISautenticacao::autenticar(_CPF CPF, _senha senha) throw(runtime_error) {

    int linha, coluna;
    string a;

      clear();
      initscr();
      getmaxyx(stdscr,linha,coluna);
       mvprintw(linha/2,(coluna-30)/2,"stubISautenticacao::autenticar");
       a = CPF.getCPF();
       mvprintw(linha/2 + 2,(coluna-13)/2,"CPF = ");
       mvprintw(linha/2 + 2,(coluna-13)/2 + 6, const_cast<char *>(a.c_str()));
       a = senha.getSenha();
       mvprintw(linha/2 + 4,(coluna-13)/2,"senha = ");
       mvprintw(linha/2 + 4,(coluna-13)/2 + 8, const_cast<char *>(a.c_str()));
      getch();
      endwin();

      if((CPF.getCPF()) == stubISautenticacao::TRIGGER_FALHA) return false;
      else if((CPF.getCPF()) == stubISautenticacao::TRIGGER_ERRO) throw runtime_error("Erro ao acessar a base de dados");
        else return true;
}

int stubISusuario::cadastrar(_usuario usuario, _cartao cartao) throw(runtime_error) {

    //IMPRIME AS INFORMACOES QUE CHEGAM A ELE

    //VERFICA O O CPF COMO CHAVE PRINCUIPAL SE JÁ EXISTE NA BASE DE DADOS

    if((usuario.getCPF().getCPF()) == TRIGGER_FALHA) return 1;
     else if((cartao.getNumeroDeCartao().getNumeroDeCartao()) == TRIGGER_FALHA2) return 2;
      else return 0;

}

bool stubISusuario::excluir(_CPF CPF) throw(runtime_error) {

   return true;

}

void stubISusuario::pesquisarDados(_CPF CPF, _usuario *usuario, _cartao *cartao) {

    _CPF CPF2;
    _senha senha;
    _numeroDeCartao numeroDeCartao;
    _dataDeValidade validade;
    _codigoDeSeguranca codigoDeSeguranca;
    _usuario usuario2;
    _cartao cartao2;

     //IMPRIME AS INFORMACOES QUE CHEGAM A ELE


    //RETORNA INFORMACOES GENERICAS DE CADASTRAMENTO
    CPF2.setCPF("001.234.567-97");
    senha.setSenha("Uap123");
    numeroDeCartao.setNumeroDeCartao("5457623898234113");
    validade.setDataDeValidade("12/88");
    codigoDeSeguranca.setCodigoDeSeguranca("887");

    usuario2.setCPF(CPF2);
    usuario2.setSenha(senha);
     *usuario = usuario2;
    cartao2.setNumeroDeCartao(numeroDeCartao);
    cartao2.setCodigoDeSeguranca(codigoDeSeguranca);
    cartao2.setDataDeValidade(validade);
     *cartao = cartao2;

     return;


}


//STUBS DO MODULO DE EVENTO
bool stubISeventos::pesquisarEventos(_data data1, _data data2, _cidade cidade, _estado estado, list<_evento> *lista1, list<_apresentacao> *lista2) throw(runtime_error) {

    list<_evento> listaAUX1;
    list<_apresentacao> listaAUX2;

    if(cidade.getCidade() == TRIGGER_FALHA) return false;

   _evento evento;
   _apresentacao apresentacao;

   _codigoDeEvento codigo;
   _cidade cidade1;
   _estado estado1;
   _nomeDoEvento nome;
   _classeDeEvento classe;
   _faixaEtaria faixa;

   _codigoDeApresentacao codigo2;
   _data data3;
   _horario hora;
   _preco preco;
   _numeroDeSala sala;
   _disponibilidade ingresso;

    codigo.setCodigoDeEvento("888");
    nome.setNomeDoEvento("Cabeca de gelo");
    cidade1.setCidade("Araci");
    estado1.setEstado("BA");
    classe.setClasseDeEvento(1);
    faixa.setFaixaEtaria("L");

    evento.setCodigoDeEvento(codigo);
    evento.setNomeDoEvento(nome);
    evento.setCidade(cidade1);
    evento.setEstado(estado1);
    evento.setClasseDeEvento(classe);
    evento.setFaixaEtaria(faixa);

    listaAUX1.push_back(evento);
    codigo.setCodigoDeEvento("777");
    evento.setCodigoDeEvento(codigo);
    listaAUX1.push_back(evento);
    codigo.setCodigoDeEvento("666");
    evento.setCodigoDeEvento(codigo);
    listaAUX1.push_back(evento);
    codigo.setCodigoDeEvento("555");
    evento.setCodigoDeEvento(codigo);
    listaAUX1.push_back(evento);

    codigo2.setCodigoDeApresentacao("9999");
    data3.setData("12/05/99");
    hora.setHorario("12:30");
    preco.setPreco(500);
    sala.setNumeroDeSala(5);
    ingresso.setDisponibilidade(100);

    apresentacao.setCodigoDeApresentacao(codigo2);
    apresentacao.setData(data3);
    apresentacao.setHorario(hora);
    apresentacao.setPreco(preco);
    apresentacao.setNumeroDeSala(sala);
    apresentacao.setDisponibilidade(ingresso);
    codigo.setCodigoDeEvento("888");
    apresentacao.setCodigoDeEvento2(codigo);

    listaAUX2.push_back(apresentacao);
    listaAUX2.push_back(apresentacao);
    listaAUX2.push_back(apresentacao);
    listaAUX2.push_back(apresentacao);
    listaAUX2.push_back(apresentacao);

    *lista1 = listaAUX1;
    *lista2 = listaAUX2;

    return true;

}

bool stubISeventos::cadastrar(_evento evento, _apresentacao apresentacao, _CPF CPF, int funcao) throw(runtime_error) {

 const static int LIMITE_EVENTOS = 0;
 const static int CADASTRAR_EVENTO = 1;
 const static int CADASTRAR_APRESENTACAO = 2;

    if(funcao == LIMITE_EVENTOS) return true;
    if(funcao == CADASTRAR_EVENTO) return true;

 return true;

}

bool stubISeventos::excluirEvento(_codigoDeEvento codigoDeEvento) throw(runtime_error) {

 return false;

}

bool stubISeventos::pesquisarMeuEvento(_codigoDeEvento codigoDeEvento, _evento *evento, list<_apresentacao> *lista) throw(runtime_error) {

    list<_apresentacao> listaAUX2;
    int i;

   _evento evento2;
   _apresentacao apresentacao;

   _codigoDeEvento codigo;
   _cidade cidade1;
   _estado estado1;
   _nomeDoEvento nome;
   _classeDeEvento classe;
   _faixaEtaria faixa;
   _CPF CPF;
   _CPF CPF2;
   _apresentacao apresentacao2;

   _codigoDeApresentacao codigo2;
   _data data3;
   _horario hora;
   _preco preco;
   _numeroDeSala sala;
   _disponibilidade ingresso;

    codigo.setCodigoDeEvento("888");
    nome.setNomeDoEvento("Cabeca de gelo");
    cidade1.setCidade("Araci");
    estado1.setEstado("BA");
    classe.setClasseDeEvento(3);
    faixa.setFaixaEtaria("L");

    evento2.setCodigoDeEvento(codigo);
    evento2.setNomeDoEvento(nome);
    evento2.setCidade(cidade1);
    evento2.setEstado(estado1);
    evento2.setClasseDeEvento(classe);
    evento2.setFaixaEtaria(faixa);

    *evento = evento2;

    codigo2.setCodigoDeApresentacao("9999");
    data3.setData("12/05/99");
    hora.setHorario("12:30");
    preco.setPreco(500);
    sala.setNumeroDeSala(5);
    ingresso.setDisponibilidade(100);
    CPF.setCPF("040.709.391-56");

    apresentacao.setCodigoDeApresentacao(codigo2);
    apresentacao.setData(data3);
    apresentacao.setHorario(hora);
    apresentacao.setPreco(preco);
    apresentacao.setNumeroDeSala(sala);
    apresentacao.setDisponibilidade(ingresso);
    codigo.setCodigoDeEvento("888");
    apresentacao.setCodigoDeEvento2(codigo);
    apresentacao.setQuantidadeVendida(100);

    for(i = 0; i< 30; i++)
      apresentacao.setCPFcomprador(CPF);

    listaAUX2.push_back(apresentacao);

    codigo2.setCodigoDeApresentacao("6666");
    apresentacao2.setCodigoDeApresentacao(codigo2);
    apresentacao2.setData(data3);
    apresentacao2.setHorario(hora);
    apresentacao2.setPreco(preco);
    apresentacao2.setNumeroDeSala(sala);
    apresentacao2.setDisponibilidade(ingresso);
    codigo.setCodigoDeEvento("888");
    apresentacao2.setCodigoDeEvento2(codigo);
    apresentacao2.setQuantidadeVendida(100);

    CPF2.setCPF("011.111.111-03");
    for(i = 0; i< 30; i++)
      apresentacao2.setCPFcomprador(CPF2);

    apresentacao.setCodigoDeApresentacao(codigo2);
    listaAUX2.push_back(apresentacao2);
    codigo2.setCodigoDeApresentacao("5555");
    apresentacao.setCodigoDeApresentacao(codigo2);
    listaAUX2.push_back(apresentacao);
    codigo2.setCodigoDeApresentacao("4444");
    apresentacao.setCodigoDeApresentacao(codigo2);
    listaAUX2.push_back(apresentacao);
    codigo2.setCodigoDeApresentacao("3333");
    apresentacao.setCodigoDeApresentacao(codigo2);
    listaAUX2.push_back(apresentacao);

    *lista = listaAUX2;

    return true;

}

bool stubISeventos::alterar(_evento evento, _apresentacao apresentacao, _codigoDeApresentacao codigo2, _codigoDeEvento codigo1, int funcao) throw(runtime_error) {

// if(FUNCAO == 2)
 return true;

}


bool stubISvendas::comprar(_CPF CPF, _codigoDeApresentacao codigoDeApresentacao, int *quantidade) throw(runtime_error) {

 *quantidade = 100;
 return false;

}
