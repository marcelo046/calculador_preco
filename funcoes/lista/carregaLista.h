#include "../registro/mostraRegistro.h"

lista *carregaLista(lista *l, char *nomeArq) {
  //Declarações
  FILE *arq;
  FILE *salvos;
  lista temp;
  
  //Instruções

  // caso não existir nenhum arquivo
  if ((salvos=fopen(REG_ARQS, "r")) == NULL) {
    if ((salvos=abrirArq(REG_ARQS, "w+")) == NULL) {
      return NULL;
    }
    strcpy(nomeArq,"lista_de_itens.txt"); // nome default inicial

    if ((arq=abrirArq(nomeArq, "w+")) == NULL) {
      fclose(salvos);
      return NULL;
    }
    fprintf(salvos, "%s\n",nomeArq);
    fclose(salvos);
    fclose(arq);

    return NULL; // arq n existia, então lista é nula
  }

  // caso já existir algum arquivo
  lerStringArq(salvos, nomeArq, MAX);
  fclose(salvos);
  if ((arq=abrirArq(nomeArq,"r"))==NULL) {
    return NULL;
  } else {
    while(!feof(arq)) {
      fscanf(arq, "%f / ", &temp.preco);
      if (lerStringArq(arq, temp.nome, MAX) == 0) break;
      l = insereEmOrdem(l,&temp);
    }
    fclose(arq);
    return l;
  }
}
