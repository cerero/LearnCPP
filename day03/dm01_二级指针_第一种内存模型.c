#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printArray(char **array, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%s\n", *(array + i));
  }
}

void sortArray(char **array, int size) {
  char *tmp = NULL;
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
        if (strcmp(array[i], array[j]) < 0) {
          tmp = array[i];
          array[i] = array[j];
          array[j] = tmp;
        }
    }
  }
}

int main(int argc, char **argv) {
  char *array[] = {"aaa", "bbb", "ccc", "111" , "222"};
  int size = sizeof(array) / sizeof(char *);
  printf("排序前\n");
  printArray(array, size);
  sortArray(array, size);
  printf("降序后\n");
  printArray(array, size);
  return 0;
}
