int lerEscolhaArq(FILE *salvos, char *acao) {
  int qtd, opcao;
  printf("\nDigite n° do arquivo para %s: ", acao);
  qtd = contaLinhasArq(salvos);
  do {
    scanf("%d", &opcao);
    limparBuffer();
    if (opcao < 1 && opcao>qtd) printf("Digite valor entre 1 e %d\n",qtd);
  } while(opcao < 1 && opcao>qtd);
  return opcao;
}

// -----------------------------------------------------------------------------
void lerEssaLinhaArq(FILE *arq, int linha, char *strLido) {
  FILE *p = arq;
  int i = 0;
  rewind(p);
  do {
    if(lerStringArq(p, strLido, MAX) == 0) {
      printf("Erro! linha nao encontrada\n");
      pausar();
      break;
    }
    i++;
  } while(i != linha);
}

int existeStringEm(FILE *arq, char *str) {
  FILE *p = arq;
  rewind(p);
  char comp[MAX];

  while (lerStringArq(p, comp, MAX)) {
    if (strcmp(comp, str) == 0) {
      rewind(p);
      return 1;
    }
  }
  rewind(p);
  return 0;
}


// -----------------------------------------------------------------------------
int listaArquivos() {
  FILE *registros;
  int i = 0;
  char nomes[MAX];

  if ((registros = abrirArq(REG_ARQS, "r")) == NULL) {
    return 0;
  }

  limparTela();
  printf("Lista de arquivos:\n\n");
  while (lerStringArq(registros, nomes, MAX)) {
    printf("%d: %s\n", ++i, nomes);
  }
  fclose(registros);
  return 1;
}

// -----------------------------------------------------------------------------
char menuOpcoesArq() {
  char nomeArq[MAX];
  getRegistrAtual(nomeArq);
  printf("\n\n Arq atual: %s\n\n",nomeArq);
  printf("=== Menu Opcoes de Arquivo ===\n");
  printf("|  1 - Trocar de arquivo     |\n");
  printf("|  2 - Apagar arquivo        |\n");
  printf("|  3 - Renomear arquivo      |\n");
  printf("|  4 - criar arquivo         |\n");
  printf("|  0 - Voltar                |\n");
  printf("==============================\n");
  printf("\nOpcao: ");
  return lerChar();
}
// #1 -----------------------------------------------------------------------------
lista *trocarDeArquivo(lista *itens) {
  FILE *registros;
  char novoArq[MAX];
  int opcao;

  atualListaArq(); // tirar ???
  registros=abrirArq(REG_ARQS, "r");
  listaArquivos(registros);
  opcao = lerEscolhaArq(registros, "escolher");
  lerEssaLinhaArq(registros, opcao, novoArq);
  fclose(registros);

  if (confirmar("Deseja salvar arquivo anterior? [s/n]:"))
    itens = escreveLista(itens);

  itens = apagaLista(itens);

  setRegistrAtual(novoArq);
  itens = carregaLista(itens);
  return itens;
}

// #3 -----------------------------------------------------------------------------
void renomearArquivo() {

  FILE *registros;
  int escolha, valido=0, qtd, cancelou=0, mudouAtual;
  char nomeAntigo[MAX];
  char nomeNovo[MAX];

  atualListaArq();
  listaArquivos();
  // if sucesso em abrir fix
  registros = abrirArq(REG_ARQS, "r");
  qtd = contaLinhasArq(registros);

  // para ler nome antigo
  do {
    // add menu
    printf("\n >> Bem vindo ao menu de renomear arquivo <<\n\n");
    printf("Digite...\n'0' para cancelar\n'A' para alterar nome do arquivo atual [%s], ou\n\n",currentFile);
    lerString(nomeAntigo, MAX, "Digite n° ou nome do arquivo que quer alterar: ");
    if(strcmp(nomeAntigo, "0") == 0)
      cancelou = 1;
    else {
      // se escolheu o numero
      if (escolha=isInteger(nomeAntigo)) {
        if (escolha < 1 || escolha>qtd) {
          printf("Digite valor entre 1 e %d\n",qtd);
          valido = 0;
        } else {
          lerEssaLinhaArq(registros, escolha, nomeAntigo);
          mudouAtual = (strcmp(currentFile, nomeAntigo) == 0);
          valido = 1;
        }
      } else { // se escreveu o nome
        mudouAtual = (strcmp(nomeAntigo, "A") == 0) || (strcmp(nomeAntigo, "a") == 0);
        debug(nomeAntigo);
        if (mudouAtual) {
          strcpy(nomeAntigo, currentFile);
          valido = 1;
        } else {
          valido = existeStringEm(registros,nomeAntigo);
          if(strcmp(nomeAntigo, ATUAL) == 0) valido = 0;
          if(strcmp(nomeAntigo, REG_ARQS) == 0) valido = 0;
          if (!valido) printf("\nDigite nome que exista no arquivo!!!\n");
        }
      }
    }
  } while(!valido && !cancelou);

  // ler nome novo
  if (!cancelou) {
    do {
      lerString(nomeNovo, MAX, "Digite novo nome do arquivo: ");
      valido = !existeStringEm(registros,nomeNovo);
      if (!valido) printf("\nDigite nome que nao exista!\n");
    } while(!valido);
    // caso a pessoa va alterar arquivo q esta usando
    if (mudouAtual) {
      debug("mudou atual");
      setRegistrAtual(nomeNovo);
      strcpy(currentFile, nomeNovo);
    }
    fclose(registros);
    rename(nomeAntigo, nomeNovo);
    atualListaArq();
  } else {
    printf("\nCancelando e voltando...\n");
    pausar();
  }

}

// #4 term -----------------------------------------------------------------------------
/*void criarArquivo() {
  limparTela();

  lerString(nomes, MAX, "Digite nome do novo arquivo: ");
  if ((novoArq=abrirArq(nomes, "w+")) == NULL) {
    fclose(salvos);
    return itens;
  }
  fclose(novoArq);
}*/

// -----------------------------------------------------------------------------
void colocarNoTopoArq(FILE *arq, char *linha, int aberto) {
  // pega um uma linha e coloca no topo, arquivo deve já estar aberto
  FILE *p;
  FILE *temp;
  char nomes[MAX];

  if (aberto) {
    p = arq;
    rewind(p);
  } else {
    p = abrirArq(REG_ARQS,"r");
  }

  if ((temp=abrirArq(".temp.txt","w+")) != NULL) {
    fprintf(temp, "%s\n", linha);
    while (lerStringArq(p, nomes, MAX))
      if(strcmp(nomes, linha)) fprintf(temp, "%s\n", nomes);
    fclose(temp);
    if(!aberto) fclose(p);
    remove(REG_ARQS);
    rename(".tem.txt", REG_ARQS);
  }
}


void RemoverLinha() {

}


// =============================================================================

lista *opcoesArquivo(lista *itens) {
  //FILE *temp;
  //FILE *registros; // salvos
  //FILE *novoArq;
  //char nomes[MAX];
  //char novo[MAX];
  //int i = 0;
  char opcao;
  //
  do {
    if(!listaArquivos()) return itens;

    opcao = menuOpcoesArq();

    switch (opcao) {
      case '1':
        itens = trocarDeArquivo(itens);
        break;
      case '2':
        //itens = apagarArquivo(itens);
        break;
      case '3':
        renomearArquivo(); // ok
        break;
      case '4':
        //itens = criarArquivo(itens);
        break;
      case '0':
        //itens = voltar(itens, nomeArq);
        break;
      default:
        printf("\nOpcao [%c] invalida!!!\n",opcao);
        pausar();
    }
  }while(opcao != '0');
  //
  //if ((salvos=fopen(REG_ARQS, "r")) == NULL) {
  //  return itens;
  //}

  /*limparTela();
  printf("Lista de arquivos:\n\n");
  while (lerStringArq(salvos, nomes, MAX)) {
    printf("%d: %s\n", ++i, nomes);
  }*/
  //printf("\n0: Novo arquivo\n");

  //opcao = lerEscolhaArq(salvos);

  //rewind(salvos);
  // para criar novo arquivo
  /*if (opcao == 0) {
    limparTela();
    printf("Digite nome do novo arquivo:\n");
    lerString(nomes, MAX);
    if ((novoArq=abrirArq(nomes, "w+")) == NULL) {
      fclose(salvos);
      return itens;
    }
    fclose(novoArq);
  }
  else {
    for (i=1; lerStringArq(salvos, nomes, MAX) && (i<opcao); i++) {} //
  }


  if (confirmar("Deseja salvar arquivo anterior? [s/n]:")) {
    itens = escreveLista(itens, nomeArq);
  }
  itens = apagaLista(itens);

  strcpy(nomeArq, nomes);

  itens = carregaLista(nomeArq, nomes);

  if ((temp=fopen(".tem.txt", "w+")) == NULL) {
    fclose(salvos);
    return itens;
  }

  // coloca arq escolhido no topo
  /*rewind(salvos);
  fprintf(temp, "%s\n", nomeArq);
  while (lerStringArq(salvos, nomes, MAX))
    if(strcmp(nomes, nomeArq)) fprintf(temp, "%s\n", nomes);
  fclose(temp);
  remove(REG_ARQS);
  rename(".tem.txt", REG_ARQS);*/

  //fclose(salvos);

  return itens;
}
