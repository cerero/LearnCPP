#ifndef __STREAM_H__
#define __STREAM_H__

#define ERR_STREAM_OK 0
#define ERR_STREAM_IS_NULL (-1)
#define ERR_STREAM_FILE_NOT_OPEN (-2)
#define ERR_STREAM_SYSTEM_ERROR (-3)

#define true 1
#define false 0
typedef struct _stream stream_t;

/**创建stream_t结构体，并返回指向它的指针
   必须通过destroy_file_stream删除这个结构体
**/
stream_t* create_file_stream();

/**
删除stream_t结构体
**/
void destroy_file_stream(stream_t* stream);

/**
打开本地mp4文件
成功时返回 0
@param file_path 文件路径
@param mode 用于fopen的mode参数
**/
int stream_open_file(stream_t* stream, const char* file_path, const char*  mode);
/**读取size个字节到buf对应的内存空间**/
int stream_read(stream_t *stream, void* buf, int size);
/**写入size字节到stream所指向的文件**/
int stream_write(stream_t *stream, void *buf, int size);

/**
文件跳转
offset	-	number of characters to shift the position relative to origin
origin	-	position to which offset is added. It can have one of the following values: SEEK_SET, SEEK_CUR, SEEK_END
**/
int stream_seek(stream_t *stream, long offset, int origin);
long stream_left_size(stream_t *stream);
long stream_size(stream_t *stream);
int stream_close(stream_t *stream);

#endif //__STREAM_H__
