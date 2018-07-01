void listaRegistros(lista *l) {
    //Declarações
    float soma = 0;
    lista *item = l;
    int i = 0;
    //Instruções
    //limparTela();
    printf("\n\n\n");
    printf("=========== Lista de itens ===========\n");
    printf("item  Preco       | Nome\n");
    printf("--------------------------------------\n");
    while (item != NULL) {
      printf("%-6d", ++i);
      mostraRegistro(item);
      soma += item->preco;
      item = item->prox;
    }
    printf("======================================\n");
    printf("\n -> %d itens\n -> Soma = R$ %.2f\n", i, soma);
}
