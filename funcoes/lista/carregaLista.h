#include "../registro/mostraRegistro.h"

lista *carregaLista(lista *l) {
  //Declarações
  FILE *arq;
  FILE *registros;
  lista temp;

  //Instruções

  atualListaArq();
  if ((registros=abrirArq(REG_ARQS, "r")) == NULL) {
    return l;
  }

   // caso não houver registros, cria novo registro
  if (contaLinhasArq(registros) == 0) {
    if ((arq=abrirArq(INICIAL, "w+")) == NULL) {
      fclose(registros);
      return l;
    }
    fclose(arq);
    fclose(registros);
    setRegistrAtual(INICIAL);
    atualListaArq();
    return NULL;
  }

  // caso já existir algum registro
  getRegistrAtual(currentFile);
  fclose(registros);

  if ((arq=abrirArq(currentFile,"r"))==NULL) {
    return NULL;
  }

  if(contaLinhasArq(arq) == 0) { // caso não houver itens, lista é vazia
    fclose(arq);
    atualListaArq();
    return NULL;
  }
  while(!feof(arq)) {
    fscanf(arq, "%f / ", &temp.preco);
    if (lerStringArq(arq, temp.nome, MAX) == 0) break;
    l = insereEmOrdem(l,&temp);
  }
  fclose(arq);
  return l;
}
