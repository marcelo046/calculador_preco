FILE *abrirArq(char *nomeArq, char *modo) {
  FILE *arq;
  if ((arq=fopen(nomeArq, modo)) == NULL) {
    printf("arquivo '%s' nao pode ser aberto\n", nomeArq);
    pausar();
  }
  return arq;
}
