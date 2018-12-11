#ifndef _CONFIGUTIL_H
#define _CONFIGUTIL_H

#ifdef __cplusplus
extern "C" {
#endif

int GetCfgItem(cosnt char *fileName/*in*/, const char *key/*in*/, char *pValue/*in out*/, int *pValueLen/*out*/);
int WriteCfgItem(cosnt char *fileName/*in*/, const char *key/*in*/, const char *val/*int*/, int valueLen/*in*/);

#ifdef __cplusplus
}
#endif

#endif
