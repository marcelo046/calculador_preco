#include "../registro/mostraRegistro.h"

int lerStringArq(FILE *arq, char *nome) {
  char letra;
  int i = 0;
  while (!feof(arq) && (letra = fgetc(arq)) != '\n') {
    nome[i++] = letra;
  }
  if (feof(arq))
    return 0;

  nome[i] = '\0';
  return 1;
}

lista *carregaLista(lista *l, char *nomeArquivo) {
  //Declarações
  FILE *arq;
  lista temp;
  //Instruções

  if ((arq=fopen(nomeArquivo,"r"))==NULL) {
    printf("arquivo nao existe, criando novo\n");
    if ((arq=fopen(nomeArquivo,"w+"))==NULL) {
      printf("arquivo nao pode ser criado\n");
      pausar();
      return NULL;
    }
    pausar();
    fclose(arq);
    return NULL;
  }
  else {
    while(!feof(arq)) {
      fscanf(arq, "%f / ", &temp.preco);
      if (lerStringArq(arq, temp.nome) == 0) break;
      l = insereEmOrdem(l,&temp);
    }
    fclose(arq);
    return l;
  }
}
