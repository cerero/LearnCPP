#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Teacher {
  char name[30];
  int age;
  int id;
} Teacher;

void writeTeacher(char *fileName) {
  if (fileName == NULL)
    return;

  FILE *fp = fopen(fileName, "wb");
  if (fp == NULL) {
    printf("error on open file:%s\n", fileName);
    return;
  }

  Teacher teacher[3];
  for (int i = 0; i < 3; i++) {
    sprintf(teacher[i].name, "name%d", i);
    teacher[i].id = i*i;
    teacher[i].age = i*30;
  }
  int write_count = sizeof(teacher) / sizeof(Teacher);
  //size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );

  int ret_count = fwrite(teacher, sizeof(Teacher), write_count, fp);
  if (ret_count != write_count) {
    printf("error on write file:%s, ret_count:%d\n", fileName, ret_count);
  }
  fclose(fp);
}

void readTeacher(char *fileName, int count) {
  if (fileName == NULL)
    return;

  FILE *fp = fopen(fileName, "rb");
  if (fp == NULL) {
    printf("error on open file:%s\n", fileName);
    return;
  }

  Teacher *teacher = (Teacher *)malloc(sizeof(Teacher) * count);
  if (teacher == NULL) {
    printf("error on create Teacher memory\n");
    goto END;
  }

  //size_t fread(void  *buffer, size_t size, size_t count, FILE *stream);
  int ret_count = fread(teacher, sizeof(Teacher), count, fp);
  if (ret_count != count) {
    printf("error on read file:%s\n", fileName);
    goto END;
  }

  for (int i = 0; i < count; i++) {
    printf("----read %d's teacher data-----\n", i);
    printf("name=%s\n", teacher[i].name);
    printf("age=%d\n", teacher[i].age);
    printf("id=%d\n", teacher[i].id);
    printf("\n");
  }

  END:
    // printf("goto END\n");
    if (teacher != NULL) {
      free(teacher);
      teacher = NULL;
    }

    if (fp != NULL) {
      fclose(fp);
    }
}

int main() {
  writeTeacher("./test_teacher.bin");
  readTeacher("./test_teacher.bin", 3);
  return 0;
}
