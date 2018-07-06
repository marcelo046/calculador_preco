char mostraMenu(){

    printf("\n\n\n  Arquivo em uso [%s]\n\n",currentFile);
    printf("============ Menu ============\n");
    printf("|  1 - Inserir item          |\n");
    printf("|  2 - Remover item          |\n");
    printf("|  3 - Opcoes de arquivo     |\n");
    printf("|  4 - Apagar tudo           |\n");
    printf("|  0 - Sair                  |\n");
    printf("==============================\n");
    printf("\nOpcao: ");
    return lerChar();
}
