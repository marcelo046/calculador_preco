char mostraMenu(){
    char opcao;
    printf("\n\n\n");
    printf("============ Menu ============\n");
    printf("|  1 - Inserir item          |\n");
    printf("|  2 - Remover item          |\n");
    printf("|  3 - Trocar de arquivo     |\n");
    printf("|  4 - Apagar tudo           |\n");
    printf("|  0 - Sair                  |\n");
    printf("==============================\n");
    printf("\nOpcao: ");
    //lerString(&opcao, 1);
    opcao = getc(stdin);
    limparBuffer();
    return opcao;
    //return '1';
}
