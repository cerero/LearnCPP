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

int getMem(char ***memPtr, int row, int col) {
  if (memPtr == NULL)
    return -1;

  char **tmpRowPtr = (char **)malloc(sizeof(char *) * row);
  if (tmpRowPtr == NULL)
    return -2;

  for(int i = 0; i < row; ++i) {
    tmpRowPtr[i] = (char *)malloc(sizeof(char) * col);
    if (tmpRowPtr[i] == NULL)
      return -3;
  }

  *memPtr = tmpRowPtr;
  return 0;
}

int freeMem(char ***buf, int row, int col) {
  char **tmp = NULL;
  if (buf == NULL)
    return -1;

  tmp = *buf;
  for (int i = 0; i < row; ++i) {
    free(tmp[0]);
    tmp[0] = NULL;
  }

  free(tmp);
  *buf = NULL;
  return 0;
}

int main(int argc, char **argv) {
  char **array = NULL;
  int ret = getMem(&array, 10, 30);
  if (ret == 0) {
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

    ret = freeMem(&array, 10, 30);
    if (ret) {
      printf("析构内存失败\n");
    }
  } else {
    printf("分配内存失败\n");
  }


  return 0;
}
