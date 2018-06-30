#ifndef MOSTRA_REG
#define MOSTRA_REG

void mostraRegistro (lista *item) {
  printf("R$ %8.2f | %s\n", item->preco, item->nome);
}

#endif
