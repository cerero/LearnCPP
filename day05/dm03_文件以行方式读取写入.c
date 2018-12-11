#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void test_fputs(char *content, char *fileName) {
  if (content == NULL || fileName == NULL)
    return;

  FILE *fp = fopen(fileName, "a");
  if (fp == NULL) {
    printf("error on open file: %s\n", fileName);
    return;
  }

  int ret_code = fputs(content, fp);

  if (ferror(fp)) {
    printf("write file:%s error \n", fileName);
  }

  if (fp != NULL) {
     fclose(fp);
  }
}

void test_fgets(char *fileName, char *buffer, int bufLen) {
  if (fileName == NULL || buffer == NULL)
    return;

  FILE *fp = fopen(fileName, "r");
  char *ret = NULL;
  int count = 0;
  while ((ret = fgets(buffer, bufLen, fp))) {
    count++;
    printf("%s", buffer);
  }

  if (ferror(fp)) {
    printf("read file:%s error\n", fileName);
  } else {
    printf("read file:%s success, readtimes:%d\n", fileName, count);
  }

  if (fp != NULL) {
    fclose(fp);
  }
}

int main() {
  test_fputs("I am Jack\n", "./test_fgets.txt");
  test_fputs("I love sugar\n", "./test_fgets.txt");
  test_fputs("I love suyi\n", "./test_fgets.txt");
  char buf[1024];
  test_fgets("./test_fgets.txt", buf, 1024);
  return 0;
}
