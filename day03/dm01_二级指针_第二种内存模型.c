#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printArray(char array[10][30], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%s\n", array[i]);
  }
}

void sortArray(char array[10][30], int size) {
  char tmp[100];
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
        if (strcmp(array[i], array[j]) < 0) {
          strcpy(tmp, array[i]);
          strcpy(array[i], array[j]);
          strcpy(array[j], tmp);
        }
    }
  }
}

int main(int argc, char **argv) {
  char array[10][30] = {"aaa", "bbb", "ccc", "111" , "222"};
  printf("排序前\n");
  printArray(array, 5);
  sortArray(array, 5);
  printf("降序后\n");
  printArray(array, 5);
  return 0;
}
