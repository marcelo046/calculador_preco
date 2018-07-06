void setRegistrAtual(char *atual) {
  FILE *arqAtual;
  if ((arqAtual=abrirArq(ATUAL, "w+")) != NULL) {
    fprintf(arqAtual, "%s\n", atual);
    strcpy(currentFile, atual);
    fclose(arqAtual);
  }
}

void getRegistrAtual(char *nomeArq) {
  FILE *arqAtual;
  if ((arqAtual=abrirArq(ATUAL, "r")) != NULL) {
    lerStringArq(arqAtual, nomeArq, MAX);
    fclose(arqAtual);
  }
}
