#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>

#define MAX 50
// arquivo que guarda nome dos outros arquivos
#define REG_ARQS "_arquivos.txt"
#define INICIAL "_listaDeItens.txt"
#define ATUAL "_arq_atual.txt"

char currentFile[MAX];

#include "struct_registro.h"
#include "funcoes/todas.h"

int main(int argc, char const *argv[]) {

  char opcao;
  lista *itens = NULL;

  //getRegistrAtual(currentFile);

  //atualListaArq();
  //return 0;

  itens = carregaLista(itens);

  // area de destes
  /*
  FILE *a = fopen(nomeArq, "r");
  printf("\ntotal de linhas %d\n", contaLinhasArq(a));
  fclose(a);
  return 0;
  //*/

  do {
    //limparTela();
    listaRegistros(itens);
    opcao = mostraMenu();

    switch (opcao) {
      case '1':
        itens = insereRegistro(itens);
        break;
      case '2':
        itens = apagaLista(itens);
        break;
      case '3':
        itens = opcoesArquivo(itens);
        break;
      case '4':
        itens = apagaLista(itens);
        break;
      case '0':
        itens = sair(itens);
        break;
      default:
        printf("\nOpcao [%c] invalida!!!\n",opcao);
        pausar();
    }
  }while(opcao != '0');

  return 0;
}
