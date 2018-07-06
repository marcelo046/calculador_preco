int terminaComTxt(char *nome) {
  int t = strlen(nome);

  if (t < 5) return 0;
  if (strcmp(nome, REG_ARQS) == 0) return 0;
  if (strcmp(nome, ATUAL) == 0) return 0;
  if(nome[t-1] != 't') return 0;
  if(nome[t-2] != 'x') return 0;
  if(nome[t-3] != 't') return 0;
  if(nome[t-4] != '.') return 0;
  return 1;
}

void atualListaArq() {
  FILE *salvos;
  DIR *dir;
  struct dirent *lsdir;
  dir = opendir(".");

  if ((salvos=abrirArq(REG_ARQS, "w+")) != NULL) {
    while ( ( lsdir = readdir(dir) ) != NULL ) {
      if (terminaComTxt(lsdir->d_name)) {
        fprintf(salvos,"%s\n", lsdir->d_name);
      }
    }
    closedir(dir);
    fclose(salvos);
  }
}
