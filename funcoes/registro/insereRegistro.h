
lista *insereRegistro(lista *l){
   //Declarações
   lista item;
   //Instruções
   limparTela();

   lerString(item.nome, MAX, "Nome do produto: ");
   printf("\nValor do produto: \n");
   scanf("%f", &item.preco);
   limparBuffer();

   l = insereEmOrdem(l,&item);
   //debug("sera se o item foi inserido?");
   return l;
}
