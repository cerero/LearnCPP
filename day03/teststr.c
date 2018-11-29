#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char g_buf[100];

void reverseStr(char *str) {
  if (str == NULL)
    return;

  if (*str == '\0')
    return;

  reverseStr(str + 1);
  printf("%c", *str);
}
int main(int argc, char **argv) {
  char str[] = "I love sugar";
  memset(g_buf, 0, sizeof(g_buf));
  reverseStr(str);
  printf("\n");
  printf("%s\n", g_buf);
  return 0;
}
