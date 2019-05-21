// #include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
// #include <sys/types.h>
// #include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "stream.h"
#include "trace.h"

struct _stream
{
	FILE* fd;
	int file_opened;
};

stream_t* create_file_stream()
{
	stream_t *stream = (stream_t*)calloc(1, sizeof(stream_t));
	return stream;
}

void destroy_file_stream(stream_t* stream)
{
	if(stream)
		free(stream);
}

int stream_open_file(stream_t* stream, const char* file_path, const char* mode)
{
	if(!stream)
	{
		TRACE_ERROR("stream is NULL!");
		return ERR_STREAM_IS_NULL;
	}
	stream->fd = fopen(file_path, mode);
	if(!stream->fd)
	{
		TRACE_ERROR("Failed to open file:%s, error(%s)", file_path, strerror(errno));
		return ERR_STREAM_SYSTEM_ERROR;
	}
	stream->file_opened = true;
	return ERR_STREAM_OK;
}

int stream_read(stream_t *stream, void* buf, int size)
{
	if(!stream)
	{
		TRACE_ERROR("stream is NULL!");
		return ERR_STREAM_IS_NULL;
	}
	if(!stream->file_opened)
	{
		TRACE_ERROR("file not open!");
		return ERR_STREAM_FILE_NOT_OPEN;
	}
	return fread(buf, 1, size, stream->fd);
}

int stream_write(stream_t *stream, void *buf, int size)
{
	if(!stream)
	{
		TRACE_ERROR("stream is NULL!");
		return ERR_STREAM_IS_NULL;
	}
	if(!stream->file_opened)
	{
		TRACE_ERROR("file not open!");
		return ERR_STREAM_FILE_NOT_OPEN;
	}
	return fwrite(buf, 1, size, stream->fd);
}

int stream_seek(stream_t *stream, long offset, int origin)
{
	if(!stream)
	{
		TRACE_ERROR("stream is NULL!");
		return ERR_STREAM_IS_NULL;
	}
	if(!stream->file_opened)
	{
		TRACE_ERROR("file not open!");
		return ERR_STREAM_FILE_NOT_OPEN;
	}
	return fseek(stream->fd, offset, origin);
}

long stream_left_size(stream_t *stream) {
	if(!stream)
	{
		TRACE_ERROR("stream is NULL!");
		return ERR_STREAM_IS_NULL;
	}

	if(!stream->file_opened)
	{
		TRACE_ERROR("file not open!");
		return ERR_STREAM_FILE_NOT_OPEN;
	}

	long cur_pos = ftell(stream->fd);
	fseek(stream->fd, 0, SEEK_END);
	long file_size = ftell(stream->fd);
	fseek(stream->fd, cur_pos, SEEK_SET);

	return file_size - cur_pos;
}

long stream_size(stream_t *stream) {
	if(!stream)
	{
		TRACE_ERROR("stream is NULL!");
		return ERR_STREAM_IS_NULL;
	}

	if(!stream->file_opened)
	{
		TRACE_ERROR("file not open!");
		return ERR_STREAM_FILE_NOT_OPEN;
	}

	long cur_pos = ftell(stream->fd);
	fseek(stream->fd, 0, SEEK_END);
	long file_size = ftell(stream->fd);
	fseek(stream->fd, cur_pos, SEEK_SET);

	return file_size;
}

int stream_close(stream_t *stream)
{
	if(!stream)
	{
		TRACE_ERROR("stream is NULL!");
		return ERR_STREAM_IS_NULL;
	}
	if(!stream->file_opened)
	{
		TRACE_ERROR("file not open!");
		return ERR_STREAM_FILE_NOT_OPEN;
	}
	int ret = fclose(stream->fd);
	if(ret)
	{
		TRACE_ERROR("Failed to close file!, error(%s)", strerror(errno));
		return ERR_STREAM_SYSTEM_ERROR;
	}
	stream->file_opened = false;
	return ERR_STREAM_OK;
}
