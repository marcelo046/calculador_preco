void listaRegistros(lista *l) {
    //Declarações
    lista *item = l;
    //Instruções
    limparTela();
    printf("=========== lista de itens ===========\n");
    printf("preco | nome\n\n");
    while (item != NULL) {
      mostraRegistro(item);
      item = item->prox;
    }
    pausar();
}
