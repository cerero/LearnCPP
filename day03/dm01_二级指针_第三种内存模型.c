#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printArray(char **array, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%s\n", *(array + i));
  }
}

void sortArray(char **array, int size) {
  // char *tmp = NULL;
  char tmp[100];
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
        if (strcmp(array[i], array[j]) < 0) {
          // tmp = array[i];
          // array[i] = array[j];
          // array[j] = tmp;

          strcpy(tmp, array[i]);
          strcpy(array[i], array[j]);
          strcpy(array[j], tmp);
        }
    }
  }
}

char **getMem(int row, int col) {
  char **tmpRowPtr = (char **)malloc(sizeof(char *) * row);
  for(int i = 0; i < row; ++i) {
    tmpRowPtr[i] = (char *)malloc(sizeof(char) * col);
  }
  return tmpRowPtr;
}

void freeMem(char **buf, int row, int col) {
  for (int i = 0; i < row; ++i) {
    free(buf[0]);
    buf[0] = NULL;
  }

  free(buf);
}

int main(int argc, char **argv) {
  char **array = getMem(10, 30);
  strcpy(array[0], "aaa");
  strcpy(array[1], "bbb");
  strcpy(array[2], "ccc");
  strcpy(array[3], "111");
  strcpy(array[4], "222");

  printf("排序前\n");
  printArray(array, 5);
  sortArray(array, 5);
  printf("降序后\n");
  printArray(array, 5);

  freeMem(array, 10, 30);
  array = NULL;

  return 0;
}
