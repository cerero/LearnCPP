#include <stdlib.h>
#include <stdio.h>
// #include "mp4_parse.h"
#include "stream.h"
#include "trace.h"
#include <string.h>

int main(int argc, char* argv[])
{
	// mp4_box_node_t *root = (mp4_box_node_t*)calloc(1, sizeof(mp4_box_node_t));
	// get_mp4_box_tree(argv[1], root);
	// show_mp4_box_tree(root);
	// extract_mp4_track_data(root);
	// free_mp4_box_tree(root);
	// free(root);

	TRACE_FUNC_HEAD
	stream_t *stream = create_file_stream();
	char file_path[1024] = {0};
	strcpy(file_path, argv[1]);

	int open_ret = stream_open_file(stream, file_path, "rb");
	TRACE_LOG("path:%s, open_ret:%d", file_path, open_ret);
	if (open_ret == 0) {
		long file_size = stream_size(stream);
		TRACE_LOG("file_size: %ld", file_size);
		long left_size = stream_left_size(stream);
		TRACE_LOG("left_size: %ld", left_size);
		TRACE_LOG("after seek to 100");
		stream_seek(stream, 100, SEEK_CUR);
		left_size = stream_left_size(stream);
		TRACE_LOG("left_size: %ld", left_size);

		stream_close(stream);
		destroy_file_stream(stream);
	}

	TRACE_FUNC_TAIL

	return 0;
}
