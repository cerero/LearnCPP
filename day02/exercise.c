#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int trimSpace(char *inbuf, char **outbuf) {
  char *left = NULL;
  char *right = NULL;

  if (inbuf == NULL || outbuf == NULL) {
    printf("error in trimSpace(): inbuf=%d and outbuf=%d, must be not NULL\n", inbuf, outbuf);
    return 1;
  }

  left = inbuf;
  right = inbuf + strlen(inbuf) - 1;

  while (left < right) {
    // printf("left:%d, right:%d\n", left, right);

    int testSpace = 0;
    if (isspace(*left)) {
      testSpace = 1;
      ++left;
    }

    // printf("left:%d\n", left);
    if (isspace(*right)) {
      testSpace = 1;
      *right = '\0';
      --right;
    }
    // printf("right:%d\n", right);

    if (!testSpace)
      break;
  }

  *outbuf = left;
  return 0;
}

int main(int argc, char **argv) {
  char testStr1[] = "   abc   ";
  char testStr2[] = "   abc";
  char testStr3[] = "abc   ";
  char testStr4[] = "   ";
  char testStr5[] = "";
  char testStr6[] = "a   b   c";

  char *afterTrim = NULL;
  int ret = 0;

  ret = trimSpace(testStr1, &afterTrim);
  if (ret == 0) {
    printf("%s(%d) after trim %s(%d)\n", testStr1, strlen(testStr1), afterTrim, strlen(afterTrim));
  }

  ret = trimSpace(testStr2, &afterTrim);
  if (ret == 0) {
    printf("%s(%d) after trim %s(%d)\n", testStr2, strlen(testStr2), afterTrim, strlen(afterTrim));
  }

  ret = trimSpace(testStr3, &afterTrim);
  if (ret == 0) {
    printf("%s(%d) after trim %s(%d)\n", testStr3, strlen(testStr3), afterTrim, strlen(afterTrim));
  }

  ret = trimSpace(testStr4, &afterTrim);
  if (ret == 0) {
    printf("%s(%d) after trim %s(%d)\n", testStr4, strlen(testStr4), afterTrim, strlen(afterTrim));
  }

  ret = trimSpace(testStr5, &afterTrim);
  if (ret == 0) {
    printf("%s(%d) after trim %s(%d)\n", testStr5, strlen(testStr5), afterTrim, strlen(afterTrim));
  }

  ret = trimSpace(testStr6, &afterTrim);
  if (ret == 0) {
    printf("%s(%d) after trim %s(%d)\n", testStr6, strlen(testStr6), afterTrim, strlen(afterTrim));
  }

  return ret;
}
