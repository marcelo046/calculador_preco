int isInteger(char *str) {
  int i, num=0;
  char *a;
  if(str[0] == '\0') return 0;
  for (i = 0; str[i]; i++)
    if(str[i] < '0' || str[i] > '9') return 0;
  num = atoi(str);
  return num;
}
