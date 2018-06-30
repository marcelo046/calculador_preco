
lista *insereRegistro(lista *l){
   //Declarações
   lista item;
   //Instruções
   limparTela();
   printf("Nome do produto: \n");
   lerString(item.nome, MAX);
   printf("Valor do produto: \n");
   scanf("%f", &item.preco);

   l = insereEmOrdem(l,&item);
   //debug("sera se o item foi inserido?");
   return l;
}
