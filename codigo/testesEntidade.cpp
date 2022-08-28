#include "testesEntidade.h"
#include <iostream>

int tu_usuario::testeUsuario() {

   CPF.setCPF("111.444.777-35");
   senha.setSenha("1AbTuk");
   estado = sucesso;
   usuario.setCPF(CPF);
   if(usuario.getCPF().getCPF() != CPF.getCPF())
     estado = falha;
   usuario.setSenha(senha);
   if(usuario.getSenha().getSenha() != senha.getSenha())
     estado = falha;

      return estado;

}


int tu_evento::testeEvento() {

   codigoDeEvento.setCodigoDeEvento("999");
    evento.setCodigoDeEvento(codigoDeEvento);
   nomeDoEvento.setNomeDoEvento("show de comedia1");
    evento.setNomeDoEvento(nomeDoEvento);
   cidade.setCidade("tangamandapio.1");
    evento.setCidade(cidade);
   estado.setEstado("AL");
    evento.setEstado(estado);
   classeDeEvento.setClasseDeEvento(1);
    evento.setClasseDeEvento(classeDeEvento);
   faixaEtaria.setFaixaEtaria("L");
    evento.setFaixaEtaria(faixaEtaria);

    estadoDoTeste = sucesso;

   if(evento.getCodigoDeEvento().getCodigoDeEvento() != codigoDeEvento.getCodigoDeEvento()) estadoDoTeste = falha;
   if(evento.getNomeDoEvento().getNomeDoEvento() != nomeDoEvento.getNomeDoEvento()) estadoDoTeste = falha;
   if(evento.getCidade().getCidade() != cidade.getCidade()) estadoDoTeste = falha;
   if(evento.getEstado().getEstado() != estado.getEstado()) estadoDoTeste = falha;
   if(evento.getClasseDeEvento().getClasseDeEvento() != classeDeEvento.getClasseDeEvento())estadoDoTeste = falha;
   if(evento.getFaixaEtaria().getFaixaEtaria() != faixaEtaria.getFaixaEtaria()) estadoDoTeste = falha;

      return estadoDoTeste;

}


//teste de unidade da classe _apresentacao
int tu_apresentacao::testeApresentacao() {

   codigoDeApresentacao.setCodigoDeApresentacao("9999");
    apresentacao.setCodigoDeApresentacao(codigoDeApresentacao);
   data.setData("10/03/99");
    apresentacao.setData(data);
   horario.setHorario("12:30");
    apresentacao.setHorario(horario);
   preco.setPreco(500);
    apresentacao.setPreco(preco);
   numeroDeSala.setNumeroDeSala(5);
    apresentacao.setNumeroDeSala(numeroDeSala);
   disponibilidade.setDisponibilidade(125);
    apresentacao.setDisponibilidade(disponibilidade);

   estado = sucesso;

   if(apresentacao.getCodigoDeApresentacao().getCodigoDeApresentacao() != codigoDeApresentacao.getCodigoDeApresentacao()) estado = falha;
   if(apresentacao.getData().getData() != data.getData()) estado = falha;
   if(apresentacao.getHorario().getHorario() != horario.getHorario()) estado = falha;
   if(apresentacao.getPreco().getPreco() != preco.getPreco()) estado = falha;
   if(apresentacao.getNumeroDeSala().getNumeroDeSala() != numeroDeSala.getNumeroDeSala()) estado = falha;
   if(apresentacao.getDisponibilidade().getDisponibilidade() != disponibilidade.getDisponibilidade()) estado = falha;

      return estado;

}


int tu_ingresso::testeIngresso() {

   codigoDeIngresso.setCodigoDeIngresso("99999");
    ingresso.setCodigoDeIngresso(codigoDeIngresso);

    estado = sucesso;

    if(ingresso.getCodigoDeIngresso().getCodigoDeIngresso() != codigoDeIngresso.getCodigoDeIngresso()) estado = falha;

      return estado;

}


int tu_cartao::testeCartao() {

   numeroDeCartao.setNumeroDeCartao("5457623898234113");
    cartao.setNumeroDeCartao(numeroDeCartao);
   codigoDeSeguranca.setCodigoDeSeguranca("999");
    cartao.setCodigoDeSeguranca(codigoDeSeguranca);
   dataDeValidade.setDataDeValidade("12/99");
    cartao.setDataDeValidade(dataDeValidade);

   estado = sucesso;

   if(cartao.getNumeroDeCartao().getNumeroDeCartao() != numeroDeCartao.getNumeroDeCartao()) estado = falha;
   if(cartao.getCodigoDeSeguranca().getCodigoDeSeguranca() != codigoDeSeguranca.getCodigoDeSeguranca()) estado = falha;
   if(cartao.getDataDeValidade().getDataDeValidade() != dataDeValidade.getDataDeValidade()) estado = falha;

      return estado;

}
