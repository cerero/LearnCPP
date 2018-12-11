#include "StringUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *trim(char *inStr/**in**/, char *outStr/**in out**/) {
  if (inStr == NULL || outStr == NULL)
    return NULL;

  int inStrLen = strlen(inStr);
  int writeInd = 0;
  for (int i = 0; i < inStrLen; i++) {
    if (isspace(inStr[i])) {
      continue;
    }

    outStr[writeInd++] = inStr[i];
  }

  outStr[writeInd] = '\0';
  return outStr;
}
