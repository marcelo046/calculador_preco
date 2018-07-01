lista *sair(lista *itens, char *nomeArquivo) {
  char opcao;
  limparTela();
  do {
    printf("Deseja salvar arquivo? [s/n]\n");
    opcao = getc(stdin);
    limparBuffer();
    opcao = tolower(opcao);
    if (opcao == 's') {
      printf("Salvando e saindo...\n");
      itens = escreveLista(itens, nomeArquivo);
    } else if (opcao == 'n') {
      printf("Saindo sem salvar...\n");
    } else {
      printf("opcao invalida!\n");
    }
  } while (opcao != 's' && opcao != 'n');
  itens = apagaLista(itens);
  return itens;
}
