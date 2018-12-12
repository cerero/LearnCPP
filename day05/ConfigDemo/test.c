#include "ConfigUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StringUtil.h"

void menu() {
  printf("===========================\n");
  printf("退出测试(输入0)\n");
  printf("测试写配置文件(输入1)\n");
  printf("测试读配置文件(输入2)\n");
  printf("===========================\n");
}

void testGetCfgItem(const char *key, char *value) {
  int valueLen = 0;
  int ret = GetCfgItem("cfg.ini", key, value, &valueLen);
  if (ret == 0) {
    printf("获取成功 value=%s\n", value);
  } else {
    printf("获取 key:%s 失败, errorcode:%d\n", key, ret);
  }
}
int main() {
  int choice;
  char key[1024];
  char value[1024];
  int flag = 1;
  while(flag) {
    menu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("key=");
        scanf("%s", key);
        printf("value=");
        scanf("%s", value);
        break;
      case 2:
        printf("key=");
        scanf("%s", key);
        testGetCfgItem(key, value);
        break;
      case 0:
        flag = 0;
        break;
    }
  }

  return 0;
}
