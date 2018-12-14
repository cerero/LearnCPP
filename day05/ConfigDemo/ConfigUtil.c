#include "ConfigUtil.h"
#include "StringUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1024
int GetCfgItem(const char *fileName/*in*/, const char *key/*in*/, char *pValue/*in out*/, int *pValueLen/*out*/) {
  if (fileName == NULL || key == NULL || pValue == NULL || pValueLen == NULL)
    return -1;

  char *ret = NULL;
  char *tmpKey = NULL;
  char *tmpVal = NULL;
  char *pBegin, *pEnd = NULL;
  char buffer[MAXLENGTH];
  FILE *fp = fopen(fileName, "r");

  if (!fp) {
    printf("error on open file:%s\n", fileName);
    return -2;
  }

  while(!feof(fp) && !ferror(fp)) {
    ret = fgets(buffer, MAXLENGTH, fp);
    if (ret == NULL)
      continue;

    tmpKey = strstr(buffer, key);
    if (tmpKey == NULL)
      continue;

    tmpVal = strchr(tmpKey + strlen(key), '=');
    if (tmpVal == NULL)
      continue;

    tmpVal += 1;
    pBegin = tmpVal;

    if (*pBegin == '\0' || *pBegin == '\n') {//value是空字符串
      goto END;
    }

    while (*pBegin == ' ') {//把左边空白字符扣掉
      pBegin++;
      if (*pBegin == '\n' || *pBegin == '\0') {//value是空白字符串
        goto END;
      }
    }

    pEnd = tmpVal + strlen(tmpVal) - 1;
    while (*pEnd == ' ' || *pEnd == '\n') {
      pEnd--;
    }

    strncat(pValue, pBegin, pEnd - pBegin + 1);
    *pValueLen = strlen(pValue);
    break;
  }

  END:
  if (fp) {
    fclose(fp);
  }

  if (tmpVal == NULL)
    return -3;
  else
    return 0;
}

int WriteCfgItem(const char *fileName/*in*/, const char *key/*in*/, const char *val/*int*/, int valueLen/*in*/) {
  if (fileName == NULL || key == NULL || val == NULL)
    return -1;

  int ret = 0;
  char buffer[MAXLENGTH] = {0};
  char cache[MAXLENGTH * MAXLENGTH] = {0};
  int occurence = 0;
  FILE *fp = fopen(fileName, "r+");
  if (fp == NULL) {
    printf("%s 文件不存在，重新创建\n", fileName);
    fp = fopen(fileName, "w+");
  }

  if (fp == NULL) {
    printf("%s 创建失败\n", fileName);
    return -2;
  }

  fseek(fp, 0L, SEEK_END);
  long int length = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  if (length > MAXLENGTH * MAXLENGTH) {
    ret = -6;
    printf("%s 内容过大，不能超过1MB\n", fileName);
    goto END;
  }

  while (!feof(fp) && !ferror(fp)) {
    if (fgets(buffer, MAXLENGTH, fp)) {
      if (strstr(buffer, key)) {
        occurence++;
        sprintf(buffer, "%s = %s\n", key, val);
        // printf("替换后%s\n", buffer);
      }
      strcat(cache, buffer);
    }
  }

  if (ferror(fp)) {
    printf("error on read file:%s\n", fileName);
    ret = -3;
    goto END;
  }

  if (occurence > 0) {//修改
    fclose(fp);
    fp = fopen(fileName, "w+");
    if (fp == NULL) {
      printf("concat file failed:%s\n", fileName);
      ret = -4;
      goto END;
    }

    // printf("%s\n", cache);

    fputs(cache, fp);
    if (ferror(fp)) {
      printf("modify key failed:%s\n", fileName);
      ret = -5;
      goto END;
    }
  } else {//追加
    // printf("追加key=%s, newValue=%s\n", key, val);
    fprintf(fp, "%s = %s\n", key, val);
  }

  END:
  if (fp) {
    fclose(fp);
  }
  return ret;
}
