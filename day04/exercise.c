#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sort(char *p[], int count, char **p, int *ncount);
int sort(char *p[], int count, char (*p)[30], int *ncount);
int sort(char (*p)[30], int ncount,  char **p, int *ncount);

//把第一种内存模型第二种内存模型结果copy到第三种内存模型中，并排序，打印
char ** sort(char **p1, int num1, char (*p)[30], int num2, int *num3 );


int main() {
  //第一种内存模型 指针指向常量区
  char *array1[] = {"I love sugar", "I love suyi", "I love jack"};
  //第二种内存模型 栈分配内存
  char array2[3][30] = {"I love sugar", "I love suyi", "I love jack"};
  //第三种内存模型 堆分配内存
  char **array3;
  return 0;
}

int sort(char *p[], int count, char **p, int *ncount) {

}

char ** sort(char **p1, int num1, char (*p)[30], int num2, int *num3 ) {
  if (p1 == NULL)
    return -1;


}
