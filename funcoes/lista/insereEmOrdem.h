
lista *insereEmOrdem(lista *a, lista *n) {
  lista *novo = (lista*)malloc(sizeof(lista));
  lista *aux = a;

  if(novo == NULL) {
    printf("\nnao foi possivel alocar memoria\n");
    pausar();
    return a;
  }

  strcpy(novo->nome,n->nome);
  novo->preco = n->preco;
  novo->prox = NULL;
  novo->ant = NULL;

  if(a == NULL)
    return novo;

  while (novo->preco > aux->preco) {
    if (aux->prox == NULL) {
      aux->prox = novo;
      novo->ant = aux;
      novo->prox = NULL;
      return a;
    }
    aux = aux->prox;
  }

  if(aux->ant != NULL) {
    novo->prox = aux;
    novo->ant = aux->ant;
    (novo->ant)->prox = novo;
    (novo->prox)->ant = novo;
  }
  else {
    aux->ant = novo;
    novo->prox = aux;
    novo->ant = NULL;
    a = novo;
  }
  return a;
}
