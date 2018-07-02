char mostraMenu(char *nomeArq){

    printf("\n\n\n  > %s <\n",nomeArq);
    printf("============ Menu ============\n");
    printf("|  1 - Inserir item          |\n");
    printf("|  2 - Remover item          |\n");
    printf("|  3 - Trocar de arquivo     |\n");
    printf("|  4 - Apagar tudo           |\n");
    printf("|  0 - Sair                  |\n");
    printf("==============================\n");
    printf("\nOpcao: ");
    return lerChar();
}
