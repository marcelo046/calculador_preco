#ifndef PAUSAR
#define PAUSAR

#include <stdio.h>

void pausar() {
  int i = 0;
  char lixo;
  printf("\nPressione enter para continuar...\n");
  scanf("%c", &lixo);
  if (lixo != '\n') limparBuffer();
}

void debug(char *msg) {
  int i = 0;
  char lixo;
  printf("%s\n", msg);
  printf("\nPressione enter para continuar...\n");
  scanf("%c", &lixo);
  if (lixo != '\n') limparBuffer();
}

#endif // PAUSAR
