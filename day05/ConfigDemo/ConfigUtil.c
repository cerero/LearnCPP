#include "ConfigUtil.h"
#include "StringUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1024
int GetCfgItem(const char *fileName/*in*/, const char *key/*in*/, char *pValue/*in out*/, int *pValueLen/*out*/) {
  if (fileName == NULL || key == NULL || pValue == NULL || pValueLen == NULL)
    return -1;

  char buffer[MAXLENGTH];

  FILE *fp = fopen(fileName, "r");
  if (!fp) {
    printf("error on open file:%s\n", fileName);
    return -2;
  }

  char *ret = NULL;
  char *tmpKey = NULL;
  char *tmpVal = NULL;

  while(!feof(fp) && !ferror(fp)) {
    fgets(buffer, MAXLENGTH, fp);
    tmpKey = strstr(buffer, key);
    if (tmpKey == NULL)
      continue;

    tmpVal = strchr(tmpKey + strlen(key), '=');
    if (tmpVal == NULL)
      continue;

    tmpVal += 1;
    strcpy(pValue, tmpVal);
    *pValueLen = strlen(pValue);
    break;
  }

  if (fp) {
    fclose(fp);
  }

  if (tmpVal == NULL)
    return -3;
  else
    return 0;
}

int WriteCfgItem(const char *fileName/*in*/, const char *key/*in*/, const char *val/*int*/, int valueLen/*in*/) {
  return 0;
}
