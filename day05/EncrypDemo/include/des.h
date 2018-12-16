#ifndef _OPENDESS_H_
#define _OPENDESS_H_

#ifdef __cplusplus
extern "C" {
#endif

int DesEnc(
		unsigned char *pInData,
		int            nInDataLen,
		unsigned char *pOutData,
		int           *pOutDataLen);

int DesDec(
	   unsigned char *pInData,
	   int            nInDataLen,
	   unsigned char *pOutData,
	   int           *pOutDataLen);

#ifdef __cplusplus
}
#endif

#endif
