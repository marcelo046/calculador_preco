#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

#include "struct_registro.h"
#include "funcoes/todas.h"

int main(int argc, char const *argv[]) {
  char nomeArq[] = "itens.txt";
  char opcao;
  lista *itens = NULL;
  itens = carregaLista(itens, nomeArq);

  do {
    //limparTela();
    listaRegistros(itens);
    opcao = mostraMenu();

    switch (opcao) {
      case '1':
        itens = insereRegistro(itens);
        break;
      case '2':
        //itens = removeRegistro(itens); // terminar
        break;
      case '3':
        //escolhe arquivo
        break;
      case '4':
        itens = apagaLista(itens);
        break;
      case '0':
        itens = sair(itens, nomeArq);
        break;
      default:
        printf("\nOpcao [%c] invalida!!!\n",opcao);
        pausar();
    }
  }while(opcao != '0');

  //itens = insereRegistro(itens);
  //listaRegistros(itens);
  //itens = insereRegistro(itens);
  //listaRegistros(itens);
  //itens = escreveLista(itens, nomeArq);

  return 0;
}
