#include "builder.h"
#include "interfaces.h"
#include "controladorasApresentacao.h"
#include "stubs.h"
#include "container.h"
#include "dominios.h"
#include "controladorasServico.h"

void builder::cadastroAUX(cntrlISusuario* cntrlUser, cntrlISautenticacao *cntrlAut, cntrlISeventos *cntrlEvento, cntrlISvendas *cntrlVendas) {

  _CPF CPF;
  _senha senha;
  _numeroDeCartao numero;
  _codigoDeSeguranca codigo1;
  _dataDeValidade validade;
  _usuario user;
  _cartao card;

  _codigoDeEvento codEvento;
  _nomeDoEvento nome;
  _cidade cidade;
  _estado estado;
  _classeDeEvento classe;
  _faixaEtaria faixa;
  _evento evento;

  _codigoDeApresentacao codApr;
  _data data;
  _horario horario;
  _preco preco;
  _numeroDeSala sala;
  _disponibilidade disp;
  _apresentacao apresentacao;

   CPF.setCPF("021.111.111-20");
   senha.setSenha("Uap321");
   numero.setNumeroDeCartao("5276600089745866");
   codigo1.setCodigoDeSeguranca("777");
   validade.setDataDeValidade("10/05");
   user.setCPF(CPF);
   user.setSenha(senha);
   card.setNumeroDeCartao(numero);
   card.setCodigoDeSeguranca(codigo1);
   card.setDataDeValidade(validade);

   cntrlUser->cadastrar(user,card);

    codEvento.setCodigoDeEvento("111");
    nome.setNomeDoEvento("Evento1");
    cidade.setCidade("Gama");
    estado.setEstado("DF");
    classe.setClasseDeEvento(1);
    faixa.setFaixaEtaria("L");
     evento.setCodigoDeEvento(codEvento);
     evento.setNomeDoEvento(nome);
     evento.setCidade(cidade);
     evento.setEstado(estado);
     evento.setClasseDeEvento(classe);
     evento.setFaixaEtaria(faixa);

    cntrlEvento->cadastrar(evento,apresentacao,CPF,1);

      codApr.setCodigoDeApresentacao("1111");
      data.setData("10/03/99");
      horario.setHorario("10:30");
      preco.setPreco(10);
      sala.setNumeroDeSala(1);
      disp.setDisponibilidade(120);
       apresentacao.setCodigoDeApresentacao(codApr);
       apresentacao.setData(data);
       apresentacao.setHorario(horario);
       apresentacao.setPreco(preco);
       apresentacao.setNumeroDeSala(sala);
       apresentacao.setDisponibilidade(disp);
       apresentacao.setCodigoDeEvento2(codEvento);

      cntrlEvento->cadastrar(evento,apresentacao,CPF,2);

    return;


}

void builder::build() {

    _CPF CPF;

    CPF.setCPF("040.709.391-56");

 cntrlIAcentral cntrlaIAcentral;

 cntrlIAautenticacao cntrlaIAautenticacao;
 cntrlIAusuario cntrlaIAusuario;
 cntrlIAeventos cntrlaIAeventos;
 cntrlIAvendas cntrlaIAvendas;

 cntrlISautenticacao cntrlAutenticacao;
 cntrlISusuario cntrlUsuario;
 cntrlISeventos cntrlEventos;
 cntrlISvendas cntrlVendas;

 containerUsuario containerUser;
 containerCartao containerCard;
 containerEventos containerEvent;
 containerApresentacao containerApr;
 containerIngressos containerIngressos;

 cntrlAutenticacao.setContainer(&containerUser);
 cntrlUsuario.setContainerUser(&containerUser);
 cntrlUsuario.setContainerCard(&containerCard);
 cntrlEventos.setContainerUser(&containerUser);
 cntrlEventos.setContainerEvent(&containerEvent);
 cntrlEventos.setContainerApr(&containerApr);
 cntrlVendas.setContainerIngressos(&containerIngressos);
 cntrlVendas.setContainerApr(&containerApr);

 cntrlaIAautenticacao.setCntrlISautenticacao(&cntrlAutenticacao);
 cntrlaIAusuario.setCntrlISusuario(&cntrlUsuario);
 cntrlaIAeventos.setCntrlISeventos(&cntrlEventos);
 cntrlaIAvendas.setCntrlISvendas(&cntrlVendas);

 cntrlaIAcentral.setCntrlIAautenticacao(&cntrlaIAautenticacao);
 cntrlaIAcentral.setCntrlIAusuario(&cntrlaIAusuario);
 cntrlaIAcentral.setCntrlIAeventos(&cntrlaIAeventos);
 cntrlaIAcentral.setCntrlIAvendas(&cntrlaIAvendas);

 cadastroAUX(&cntrlUsuario, &cntrlAutenticacao, &cntrlEventos, &cntrlVendas );

 cntrlaIAcentral.executar();


}
