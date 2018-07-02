int contaArquivos(FILE *salvos) {
  FILE *f = salvos;
  int nro = 0;
  char aux[MAX];
  rewind(f);
  while (lerStringArq(f, aux, MAX)) {
    nro++;
  }
  return nro;
}
int validaOpcao(FILE *salvos) {
  int qtd, opcao;
  printf("\nescolha o arquivo para carregar (0 para criar novo):\n");
  qtd = contaArquivos(salvos);
  do {
    scanf("%d", &opcao);
    limparBuffer();
    if (opcao < 0 && opcao>=qtd) printf("Digite valor entre 0 e %d\n",qtd);
  } while(opcao < 0 && opcao>=qtd);
}



// =============================================================================

lista *trocarArquivo(lista *itens, char *nomeArq) {
  FILE *temp;
  FILE *salvos;
  FILE *novoArq;
  char nomes[MAX];
  char novo[MAX];
  int i = 0, opcao;

  if ((salvos=fopen(REG_ARQS, "r")) == NULL) {
    return itens;
  }

  limparTela();
  printf("Lista de arquivos:\n\n");
  printf("0: Novo arquivo\n");
  while (lerStringArq(salvos, nomes, MAX)) {
    printf("%d: %s\n", ++i, nomes);
  }

  opcao = validaOpcao(salvos);

  rewind(salvos);

  if (opcao == 0) {
    limparTela();
    printf("Digite nome do novo arquivo:\n");
    lerString(nomes, MAX);
    if ((novoArq=abrirArq(nomes, "w+")) == NULL) {
      fclose(salvos);
      return itens;
    }
    fclose(novoArq);

  }
  else {
    for (i=1; lerStringArq(salvos, nomes, MAX) && (i<opcao); i++) {} //
  }


  if (confirmar("Deseja salvar arquivo anterior? [s/n]:")) {
    itens = escreveLista(itens, nomeArq);
  }
  itens = apagaLista(itens);

  strcpy(nomeArq, nomes);
  if (opcao != 0)
    itens = carregaLista(itens, nomes);

  if ((temp=fopen(".tem.txt", "w+")) == NULL) {
    fclose(salvos);
    return itens;
  }
  rewind(salvos);
  fprintf(temp, "%s\n", nomeArq);
  while (lerStringArq(salvos, nomes, MAX)) {
    if(strcmp(nomes, nomeArq)) fprintf(temp, "%s\n", nomes);
  }
  //if (opcao == 0) fprintf(temp, "%s\n", nomes); // ???

  fclose(temp);
  remove(REG_ARQS);
  rename(".tem.txt", REG_ARQS);

  fclose(salvos);

  return itens;
}
