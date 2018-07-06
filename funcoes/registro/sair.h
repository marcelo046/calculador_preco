lista *sair(lista *itens) {
  limparTela();

  if (confirmar("Deseja salvar arquivo? [s/n]")) {
    printf("Salvando e saindo...\n");
    itens = escreveLista(itens);
  } else {
    printf("Saindo sem salvar...\n");
  }
  itens = apagaLista(itens);
  return itens;
}
