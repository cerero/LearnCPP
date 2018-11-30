#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int changeToArray(const char *inStr, const char *delimiter,char ***outPtr, int *row) {
  char *subStr = NULL;
  if (inStr == NULL || delimiter == NULL || outPtr == NULL || row == NULL)
    return -1;

  char **array = NULL;
  const char *tempInStr = NULL;
  char *nextToken = NULL;
  int tmpRow = 0;

  tempInStr = inStr;
  while ((nextToken = strstr(tempInStr, delimiter))) {//计算行数，有点啰嗦，暂时想不到好的办法
    ++tmpRow;
    tempInStr = nextToken + strlen(delimiter);
  }
  array = (char **)malloc(sizeof(char *) * tmpRow);
  if (array == NULL)
    return -2;

  tempInStr = inStr;
  while ((nextToken = strstr(tempInStr, delimiter))) {//生成每行的字符串
    int sizeOfStr = nextToken - tempInStr + 1;
    char *element = (char *)malloc(sizeof(char) * sizeOfStr);
    if (element == NULL)
      return -3;

    strncat(element, tempInStr, nextToken - tempInStr);
    tempInStr = nextToken + strlen(delimiter);
    *array = element;
    ++array;
  }

  *row = tmpRow;
  *outPtr = array - tmpRow;
  return 0;
}

int freeArrayMemory(char ***inPtr, int row) {
  if (inPtr == NULL)
    return -1;

  char **tmpArray = *inPtr;
  for (int i = 0; i < row; ++i) {
    free(tmpArray[i]);
  }
  free(tmpArray);
  *inPtr = NULL;
  return 0;
}

int main(int argc, char **argv) {
  char *inStr = "aaa,bbb,ccc,ddd,";
  char **array = NULL;
  int row = 0;

  int ret = changeToArray(inStr, ",", &array, &row);
  if (ret) { //changeToArray 运行错误
    printf("changeToArray error:%d\n", ret);
    return ret;
  }

  printf("%s 转换为二维数组, row: %d\n", inStr, row);
  for (int i = 0; i < row; ++i) {
    printf("%s\n", array[i]);
  }

  ret = freeArrayMemory(&array, row);
  if (ret) {
    printf("析构内存失败: %d\n", ret);
    return ret;
  }

  return 0;
}
