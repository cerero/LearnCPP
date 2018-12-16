#include "des.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
测试加密
**/
int testEncryp(const char *sourceFileName, const char *encFileName) {
  // int DesEnc(
  // 		unsigned char *pInData,
  // 		int            nInDataLen,
  // 		unsigned char *pOutData,
  // 		int           *pOutDataLen);

  int ret = 0;
  FILE *sourceFP = NULL;
  FILE *encFP = NULL;

  if (sourceFileName == NULL || encFileName == NULL) {
    ret = -1;
    goto END;
  }

  sourceFP = fopen(sourceFileName, "r+b");
  if (sourceFP == NULL) {
    printf("open file %s fail\n", sourceFileName);
  }

  encFP = fopen(encFileName, "w+b");
  if (encFP == NULL) {
    printf("open file %s fail\n", encFileName);
  }

  unsigned char readBuffer[1024] = {0};//1k大小
  unsigned char writeBuffer[4096] = {0};
  int writeLen = 0;
  int readRet = 0;
  int writeRet = 0;
  int encRet = 0;
  while (!feof(sourceFP)) {
    readRet = fread(readBuffer, 1, 1024, sourceFP);
    if (readRet != 1024) {
      //可能读取失败
      //可能剩余内容少于1024
      break;
    }
    printf("encry the bytes that length euqal 1024\n");
    // memcpy(writeBuffer, readBuffer, 1024);
    // writeLen = 1024;

    encRet = DesEnc(readBuffer, 1024, writeBuffer, &writeLen);
    if (encRet != 0) {
      printf("call DesEnc() error: %d\n", encRet);
      ret = -3;
      goto END;
    }

    writeRet = fwrite(writeBuffer, 1, writeLen, encFP);
    if (writeRet != writeLen) {
      printf("wirte file %s fail\n", encFileName);
      ret = -2;
      goto END;
    }
  }

  if (readRet != 1024) {
    printf("encry the bytes that length less then 1024, len=%d\n", readRet);
    // memcpy(writeBuffer, readBuffer, readRet);
    // writeLen = readRet;
    encRet = DesEnc(readBuffer, readRet, writeBuffer, &writeLen);
    if (encRet != 0) {
      printf("call DesEnc() error: %d\n", encRet);
      ret = -3;
      goto END;
    }
    writeRet = fwrite(writeBuffer, 1, writeLen, encFP);
    if (writeRet != writeLen) {
      printf("wirte file %s fail\n", encFileName);
      ret = -2;
      goto END;
    }
  }

  END:
  if (sourceFP) {
    fclose(sourceFP);
  }
  if (encFP) {
    fclose(encFP);
  }

  return ret;
}

/**测试解密**/
int testDecryp(const char *decFileName, const char *encFileName) {
  return 0;
}

int main() {
  // int ret = 0;
  // ret = testEncryp("raw.txt", "raw_enc.txt");
  // if (ret != 0) {
  //   printf("call testEncryp() error: %d\n", ret);
  //   return ret;
  // }

  int		ret = 0;
	char *plain = "1232343444";
	int plainlen = strlen(plain);

	char plain2[4096] = {0};
	int plainlen2 = 0;

	unsigned char cryptbuf[4096] = {0};
	int cryptlen = 0;
	ret =  DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if (ret != 0)
	{
		printf("func DesEnc() err:%d \n", ret);
		return ret;
	}

  return ret;
}
