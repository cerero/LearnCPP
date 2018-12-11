#include "ConfigUtil.h"
#include "StringUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int GetCfgItem(cosnt char *fileName/*in*/, const char *key/*in*/, char *pValue/*in out*/, int *pValueLen/*out*/) {
  if (fileName == NULL || key == NULL || pValue == NULL || pValueLen == NULL)
    return -1;

  const int bufLen = 1024;
  char buffer[bufLen] = {0};

  FILE *fp = fopen(fileName, "r");
  if (!fp) {
    printf("error on open file:%s\n", fileName);
    return -2;
  }

  char *ret = NULL;
  while ((ret = fgets(buffer, bufLen, fp))) {

  }

  if (fp) {
    fclose(fp);
  }
  return 0;
}

int WriteCfgItem(cosnt char *fileName/*in*/, const char *key/*in*/, const char *val/*int*/, int valueLen/*in*/) {
  return 0;
}
