#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void test_fputc(char *content, char *fileName) {
  if (content == NULL || fileName == NULL)
    return;

  FILE *fp = fopen(fileName, "a");
  if (fp == NULL) {
    printf("error on open file: %s\n", fileName);
    return;
  }

  int ret_code = 0;
  while (ret_code != EOF && *content != '\0') {
    ret_code = fputc(*content++, fp);
  }

  if (ferror(fp)) {
    printf("write file:%s error \n", fileName);
  } else {
    printf("write file:%s success\n", fileName);
  }

  if (fp != NULL) {
     fclose(fp);
  }
}

void test_fgetc(char *fileName) {
  if (fileName == NULL)
    return;

  FILE *fp = fopen(fileName, "r");
  int ret = 0;
  while ((ret = fgetc(fp)) != EOF) {
    printf("%c", ret);
  }

  if (ferror(fp)) {
    printf("read file:%s error\n", fileName);
  } else {
    printf("read file:%s success\n", fileName);
  }

  if (fp != NULL) {
    fclose(fp);
  }
}

int main() {
  test_fputc("I am Jack\n", "./test_fgetc.txt");
  test_fputc("I love sugar\n", "./test_fgetc.txt");
  test_fputc("I love suyi\n", "./test_fgetc.txt");

  test_fgetc("./test_fgetc.txt");
  return 0;
}
