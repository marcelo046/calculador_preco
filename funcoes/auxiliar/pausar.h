#ifndef PAUSAR
#define PAUSAR

#include <stdio.h>

void pausar() {
  int i = 0;
  char lixo;
  limparBuffer();
  printf("\nPressione enter para continuar...\n");
  scanf("%c", &lixo);
  //limparBuffer();
}

void debug(char *msg) {
  int i = 0;
  char lixo;
  limparBuffer();
  printf("%s\n", msg);
  printf("\nPressione enter para continuar...\n");
  scanf("%c", &lixo);
  //limparBuffer();
}

#endif // PAUSAR
