
lista *carregaLista(lista *l, char *nomeArquivo) {
  //Declarações
  FILE *arq;
  lista temp;
  //Instruções

  if ((arq=fopen(nomeArquivo,"r"))==NULL) {
    printf("arquivo nao pode ser aberto\n");
    pausar();
    return NULL;
  }
  else {
    while(!feof(arq)) {
      fscanf(arq, "%f ," , &temp.preco);
      fgets(temp.nome, MAX, arq);
      l = insereEmOrdem(l,&temp);
    }
    fclose(arq);
    return l;
  }
}
