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
    printf("获取成功 value=%s, length=%d\n", value, valueLen);
  } else {
    printf("获取 key:%s 失败, errorcode:%d\n", key, ret);
  }
}

void testWriteCfgItem(const char *key, char *value) {
  // printf("开始写入 %s = %s\n", key, value);
  int ret = WriteCfgItem("cfg.ini", key, value, strlen(value));
  if (ret == 0) {
    printf("写入key成功 key=%s, value=%s\n", key, value);
  } else {
    printf("写入key失败 key=%s, value=%s --> errorcode:%d\n", key, value, ret);
  }
}

int main(int argc, char **argv) {
  int choice;
  char key[1024];
  char value[1024];
  int flag = 1;
  while(flag) {
    memset(key, 0, 1024);
    memset(value, 0, 1024);
    menu();
    scanf("%d", &choice);
    getchar();
    switch (choice) {
      case 1:
        printf("key=");
        gets(key);
        printf("value=");
        gets(value);
        testWriteCfgItem(key, value);
        break;
      case 2:
        printf("key=");
        gets(key);
        testGetCfgItem(key, value);
        break;
      case 0:
        flag = 0;
        break;
    }
  }

  return 0;
}
