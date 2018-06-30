#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

#include "struct_registro.h"
#include "funcoes/todas.h"

int main(int argc, char const *argv[]) {

  lista *itens = NULL;
  itens = insereRegistro(itens);
  itens = insereRegistro(itens);
  itens = insereRegistro(itens);
  listaRegistros(itens);
  
  return 0;
}
