lista *escreveLista(lista *l){
  //Declarações
  FILE *arq;
  lista *item = l;
  //Instruções
  if ((arq=abrirArq(currentFile,"w+"))==NULL) {
     return l;
  }
  while (item != NULL) {
    fprintf(arq, "%.2f / " , item->preco);
    fputs(item->nome, arq);
    fputs("\n", arq);
    item = item->prox;
  }
  fclose(arq);
  return l;
}
