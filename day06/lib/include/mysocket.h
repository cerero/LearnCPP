#ifndef _MYSOCKET_H_
#define _OPENDESS_H_

#ifdef __cplusplus
extern "C" {
#endif

int initSocket(void **handler, const char *ip, const int port);
int sendSocket(void *handler, const char *content, int contentLength);
int receiveSocket(void *handler, char **response, int *responseLength);
int destroyResponse(char **response);
int destroySocket(void **handler);

#ifdef __cplusplus
}
#endif

#endif
