#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

#include "struct_registro.h"
#include "funcoes/todas.h"

int main(int argc, char const *argv[]) {
  char nomeArq[] = "itens.txt";
  lista *itens = NULL;
  itens = carregaLista(itens, nomeArq);
  //itens = insereRegistro(itens);
  //itens = insereRegistro(itens);
  listaRegistros(itens);
  printf("\ndepois de apertar enter\n");
  pausar();
  return 0;
}
