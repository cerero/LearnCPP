#include "ConfigUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void menu() {
  printf("===========================\n", );
  printf("测试写配置文件\n";
  printf("测试读配置文件\n");
  printf("===========================\n", );
}
int main() {
  int choice;

  while(true) {
    menu();
    scanf("%d\n", &choice);
    switch (choice) {
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
    }
  }
  return 0;
}
