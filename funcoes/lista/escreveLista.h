void escreveLista(lista *l, char *nomeArquivo){
  //Declarações
  FILE *arq;
  lista *item = l,*aux;
  //Instruções
  if ((arq=fopen(nomeArquivo,"w"))==NULL) {
     printf("Arquivo nao pode ser aberto.");
     pausar();
  }
  else
  {
   while (item != NULL) {
     fprintf(arq, "%.2f ," , item->preco);
     fputs(item->nome, arq);
     fputs("\n", arq);
     aux = item;
     item = item->prox;
     free(aux);
   }
  }
  fclose(arq);
}
