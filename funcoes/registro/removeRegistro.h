void removeRegistro(lista *l)
{
  //Declarações
  char nome[MAX];
  lista *aux = l;
  //Instruções
  if (l == NULL) {
    printf("\nNinguem cadastrado!\n");
  } else {
    printf("Informe o nome do item que quer remover: ");
    // ler nome

    while(aux != NULL) {
      if (strcmp(nome,aux->nome) == 0) {
        printf("Apagando item %s...\n", nome);
        if (aux->ant == NULL) {
          l = l->prox;
          free(aux);
          l->ant = NULL;
        }
        pausar();
        if (aux->prox == NULL) {
          aux = aux->ant;
          free(aux->prox);
          aux->prox = NULL;
        } else {
          (aux->ant)->prox = aux->prox;
          (aux->prox)->ant = aux->ant;
          free(aux);
        }
        break;
      }
      aux = aux->prox;
    }
    pausar("Nao ha listas cadastradas com esse nome!");
  }
}
