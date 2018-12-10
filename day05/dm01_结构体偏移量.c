#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
  char name[64];
  int age;
  int id
} Teacher;

int main(int argc, char **args, char **env) {
  Teacher *p = NULL;
  int offsetOfId = &(p->id);
  //不能访问id，因为p是NULL指针
  // printf("id = %d, offsetOfId %d\n", p->id, offsetOfId);

  //但通过NULL指针，可以用来来计算结构体字段的地址偏移量 ， 牛逼
  printf("offsetOfId %d\n", offsetOfId);
  return 0;
}
