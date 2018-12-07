#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// int sort(char *p[], int count, char **p, int *ncount);
// int sort(char *p[], int count, char (*p)[30], int *ncount);
// int sort(char (*p)[30], int ncount,  char **p, int *ncount);

//把第一种内存模型第二种内存模型结果copy到第三种内存模型中，并排序，打印
int sort(char **p1, int num1, char (*p)[30], int num2, char ***outArray, int *num3);
int freeSortedArray(char ***sortedArray, int rows);

int main() {
  //第一种内存模型 指针指向常量区
  char *array1[] = {"I love sugar", "I love suyi", "I love jack"};
  //第二种内存模型 栈分配内存
  char array2[3][30] = {"my name is sugar", "your name is suyi", "we are family"};
  //第三种内存模型 堆分配内存
  char **sortedArray = NULL;
  int sortedRows = 0;
  int ret = sort(array1, 3, array2, 3, &sortedArray, &sortedRows);
  if (ret == 0) {
    printf("before sorted \n");
    for (int i = 0; i < 3; i++) {
      printf("%s\n", array1[i]);
    }
    for (int i = 0; i < 3; i++) {
      printf("%s\n", array2[i]);
    }
    printf("------after sorted, has %d rows-------\n", sortedRows);
    for (int i = 0; i < sortedRows; i++) {
      printf("%s\n", sortedArray[i]);
    }
    int ret2 = freeSortedArray(&sortedArray, sortedRows);
    printf("free ret:%d\n", ret2);
  } else {
    printf("sort error:%d\n", ret);
  }
  return ret;
}


int sort(char **p1, int num1, char (*p)[30], int num2, char ***outArray, int *num3) {
  if (p1 == NULL || p == NULL || num3 == NULL)
    return -1;

  int times = 0;
  char **sortedArray = NULL;
  sortedArray = (char **)malloc(sizeof(char *) * (num1 + num2));
  if (sortedArray == NULL)
    return -2;

  ++times;
  int rows = 0;

  for (int i = 0; i < num1; i++) {
    int subCols = strlen(p1[i]) + 1;
    sortedArray[rows] = (char *)malloc(sizeof(char) * subCols);
    if (sortedArray[rows] == NULL) {
      freeSortedArray(&sortedArray, rows);
      return -3;
    }
    ++times;
    strcpy(sortedArray[rows], p1[i]);
    ++rows;
  }

  for (int i = 0; i < num2; i++) {
    sortedArray[rows] = (char *)malloc(31);
    if (sortedArray[rows] == NULL) {
      freeSortedArray(&sortedArray, rows);
      return -3;
    }
    ++times;
    strcpy(sortedArray[rows], p[i]);
    ++rows;
  }

  char *tmp = NULL;
  for (int i = 0; i < rows; i++) {
    for (int j = i + 1; j < rows; j++) {
      if (strcmp(sortedArray[i], sortedArray[j]) < 0) {
        tmp = sortedArray[i];
        sortedArray[i] = sortedArray[j];
        sortedArray[j] = tmp;
      }
    }
  }

  *num3 = rows;
  *outArray = sortedArray;
  printf("malloc times:%d\n", times);
  return 0;
}

int freeSortedArray(char ***sortedArray, int rows) {
  if (sortedArray == NULL)
    return -1;

  char **tmp = *sortedArray;
  int times = 0;
  if (tmp == NULL)
    return -2;

  for (int i = 0; i < rows; i++) {
    if (tmp[i] != NULL) {
      ++times;
      free(tmp[i]);
    }
    tmp[i] = NULL;
  }
  ++times;
  free(*sortedArray);
  *sortedArray = NULL;
  printf("free times: %d\n", times);
  return 0;
}
