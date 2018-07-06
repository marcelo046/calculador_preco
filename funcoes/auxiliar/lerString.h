#ifndef LER_STRING
#define LER_STRING

#include <stdio.h>

void tiraTerminador(char *string) {
  if (string[strlen(string)-1] == '\n')
    string[strlen(string)-1] = '\0';
}

void lerString(char *string, int nroLetras, char *msg) {
  int valido, tamanho;
  printf("%s",msg);
  do {
    fgets(string, nroLetras, stdin);
    tiraTerminador(string);

    if ((tamanho=strlen(string)) < nroLetras-1) {
        valido = (tamanho > 0);
    } else if (getc(stdin) == '\n') {
      valido = 1;
    } else {
      limparBuffer();
      valido = 0;
    }
    if (!valido)
      printf("Escreva nome de 0 a %d letras:\n", nroLetras-1);
  } while(!valido);
}


#endif // LER_STRING
