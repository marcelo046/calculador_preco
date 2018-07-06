int contaLinhasArq(FILE *arq) {
  FILE *f = arq;
  int nro = 0;
  char aux[MAX];
  rewind(f);
  while (lerStringArq(f, aux, MAX)) {
    nro++;
  }
  rewind(f);
  return nro;
}
