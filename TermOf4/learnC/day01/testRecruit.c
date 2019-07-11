#include <stdio.h>
#include <string.h>
/**
递归练习
**/
void decimalToBinary(int decimal, char *outBinay) {
  int leftDecimal = decimal / 2;
  int modeDecimal = decimal % 2;

  if (leftDecimal > 0) {
    decimalToBinary(leftDecimal, outBinay);
  }

  sprintf(outBinay + strlen(outBinay), "%d", modeDecimal);
}

int main(int argc, char **argv) {
  char buf[1024] = {};

  int decimal = 0;
  if (argc > 1) {
    decimal = atoi(argv[1]);
  } else {
    printf("请出入要转码的十进制\n");
    return 0;
  }

  decimalToBinary(decimal, buf);
  printf("decimal of %d, binary is %s\n", decimal, buf);

  // printf("Hello World\n");
  return 0;
}
