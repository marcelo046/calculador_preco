int lerStringArq(FILE *f, char *nome, int tam) {
  FILE *arq = f;
  char letra;
  int i = 0;
  while (!feof(arq) && (letra = fgetc(arq)) != '\n' && i<tam) {
    nome[i++] = letra;
  }
  nome[i] = '\0';

  if (feof(arq))
    return 0; // chegou no fim do arquivo

  return 1; // sucesso
}
