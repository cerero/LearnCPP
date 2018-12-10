#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
  char name[64];
  int age;
  int id
} Teacher;

//可以通过age的内存地址，去求整个Teacher的内存地址
int main(int argc, char **args, char **env) {
  Teacher *p = NULL;
  //不能访问id，因为p是NULL指针
  // printf("id = %d, offsetOfId %d\n", p->id, offsetOfId);
  int offsetOfId = &(p->id);
  offsetOfId = &(((Teacher *) 0)->id);
  //但通过NULL指针，可以用来来计算结构体字段的地址偏移量 ， 牛逼
  printf("offsetOfId %d\n", offsetOfId);

  Teacher teacher;
  p = &teacher;
  //通过实际的内存布局，来计算出id的地址偏移量
  offsetOfId = (int)(&(p->id)) - (int)p;
  printf("offsetOfId %d\n", offsetOfId);
  return 0;
}
