// definir MAX na função principal

typedef struct Lista{
  float preco;
  char nome[MAX];
  struct Lista *ant;
  struct Lista *prox;
} lista;
