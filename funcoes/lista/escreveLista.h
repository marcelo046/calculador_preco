lista *escreveLista(lista *l, char *nomeArquivo){
  //Declarações
  FILE *arq;
  lista *item = l;
  //Instruções
  if ((arq=fopen(nomeArquivo,"w"))==NULL) {
     printf("Arquivo nao pode ser aberto.");
     pausar();
     return l;
  }
  else
  {
   while (item != NULL) {
     fprintf(arq, "%.2f / " , item->preco);
     fputs(item->nome, arq);
     fputs("\n", arq);
     item = item->prox;
   }
  }
  fclose(arq);
  return l;
}
