int limparBuffer() {
  char lixo = 'a';
  while (lixo != '\n') { lixo = getc(stdin); }
}
