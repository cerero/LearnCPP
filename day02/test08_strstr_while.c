#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getCount(const char *str /*in*/, const char *substr /*in*/, int *count) {
  const char *tmpStr = str;
  const char *tmpSubStr = substr;

  if (str == NULL || substr == NULL || count == NULL)
    return 1;

  while ((tmpStr = strstr(tmpStr, tmpSubStr))) {
    ++*count;
    tmpStr += strlen(tmpSubStr);
    if (*tmpStr == '\0') {
      break;
    }
  }

  return 0;
}

int main(int argc, char **argv) {
  char *str = NULL;
  char *substr = NULL;

  if (argc > 2) {
    str = argv[1];
    substr = argv[2];
  } else {
    str = "abc08108abced";
    substr = "abc";
  }

  int count = 0;
  int ret = getCount(str, substr, &count);
  printf("%s count = %d\n", substr, count);
  return ret;
}
