void listaRegistros(lista *l) {
    //Declarações
    lista *item = l;
    //Instruções
    limparTela();
    printf("=========== Lista de itens ===========\n");
    printf("Preco       | Nome\n\n");
    while (item != NULL) {
      mostraRegistro(item);
      item = item->prox;
    }
    pausar();
}
