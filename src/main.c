#include <buffer.h>
#include <error_code.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <log.h>
#include <utility.h>
#include <uv.h>

int main(int argc, char **argv)
{
    log_info("starting up jaggrab node");
    uv_setup_args(argc, argv);

    uv_loop_t *loop = malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);

    struct buffer *b = NULL;
    int error = buffer_init(b, 32);
    sysd_check_error(error, "buffer_init");

    uv_run(loop, UV_RUN_DEFAULT);

    uv_loop_close(loop);
    free(loop);
    return EXIT_SUCCESS;
}
