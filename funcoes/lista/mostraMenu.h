int mostraMenu(){
    int opcao;
    limparTela();
    printf(">>>>>>> Menu <<<<<<<<<\n");
    printf(" 1 - Inserir novo item\n");
    printf(" 2 - Remover item\n");
    printf(" 3 - Trocar de arquivo\n");
    printf(" 4 - Apagar tudo\n");
    printf("-1 - Sair sem salvar\n");
    printf(" 0 - Sair salvando\n");
    scanf("%d",&opcao);
    return opcao;
}
