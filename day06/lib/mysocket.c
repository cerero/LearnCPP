#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysocket.h"

typedef struct SocketInfo {
  char ip[100];
  int port;
  char **resHistory;
  int revIndex;
} SocketInfo;

int initSocket(void **handler, const char *ip, const int port) {
  int ret = 0;
  SocketInfo *outHandler = NULL;

  if (handler == NULL || ip == NULL) {
    ret = -1;
    goto END;
  }

  outHandler = (SocketInfo *)malloc(sizeof(SocketInfo));
  if (outHandler == NULL) {
    ret = -1;
    printf("init socket error: %d\n", ret);
    goto END;
  }

  memset(outHandler, 0, sizeof(SocketInfo));
  strcpy(outHandler->ip, ip);
  outHandler->port = port;
  *handler = outHandler;

END:
  return ret;
}

int sendSocket(void *handler, const char *content, int contentLength);
int receiveSocket(void *handler, char **response, int *responseLength);
int destroyResponse(char **response);
int destroySocket(void **handler);
