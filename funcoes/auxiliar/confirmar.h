int confirmar(char *msg) {
  char opcao;
  int valido;

  printf("%s\n", msg);
  do {
    opcao = getc(stdin);
    limparBuffer();
    opcao = tolower(opcao);
    valido = (opcao == 's' || opcao == 'n');
    if (!valido)
      printf("\nDigite 's' ou 'n':\n");
  } while(!valido);

  return (opcao == 's');
}
