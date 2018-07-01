lista *apagaLista(lista *l){
  //Declarações
  lista *item = l,*aux;
  //Instruções

  while (item != NULL) {
    aux = item;
    item = item->prox;
    free(aux);
  }

  return NULL;
}
