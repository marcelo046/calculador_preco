lista *sair(lista *itens, char *nomeArquivo) {
  limparTela();

  if (confirmar("Deseja salvar arquivo? [s/n]")) {
    printf("Salvando e saindo...\n");
    itens = escreveLista(itens, nomeArquivo);
  } else {
    printf("Saindo sem salvar...\n");
  }
  itens = apagaLista(itens);
  return itens;
}
