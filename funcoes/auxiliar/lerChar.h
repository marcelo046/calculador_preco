char lerChar() {
  char c;
  c = getc(stdin);
  if(c != '\n') limparBuffer();
  return c;
}
