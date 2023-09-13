#include <cstdlib>
#include <cassert>

#include "file_work.h" 

static void free_all_memory(File_to_Buffer* file_and_buffer);

int main()
{
    File_to_Buffer* file_and_buffer = get_buffer_from_file();
    print_to_file(file_and_buffer);

    free_all_memory(file_and_buffer);
    return 0;
}

static void free_all_memory(File_to_Buffer* file_and_buffer)
{
    assert(file_and_buffer);

    free(file_and_buffer->buffer);
    free(file_and_buffer->text);
    free(file_and_buffer);
}