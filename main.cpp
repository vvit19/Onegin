#include <cstdlib>
#include <cassert>
#include <cstdio>

#include "file_work.h" 

static void free_all_memory(File_to_Buffer* file_and_buffer);
static int check_arg_cmd(int num_of_args);

int main(int argc, const char** argv)
{
    int exit_code = check_arg_cmd(argc);

    if (exit_code != 0)
    {
        return exit_code;
    }

    File_to_Buffer* file_and_buffer = get_buffer_from_file(argv[1]);

    print_to_file(file_and_buffer, argv[2]);

    free_all_memory(file_and_buffer);

    return 0;
}

static void free_all_memory(File_to_Buffer* file_and_buffer)
{
    assert(file_and_buffer);

    file_and_buffer->buffer = nullptr;
    free(file_and_buffer->buffer);

    file_and_buffer->text = nullptr;
    free(file_and_buffer->text);

    file_and_buffer = nullptr;
    free(file_and_buffer);
}

static int check_arg_cmd(int num_of_args)
{
    if (num_of_args == 3)
    {
        return 0;
    }

    else
    {
        printf("Incorrect flag input!\n"
               "Correct input is: .\\a.exe input_filename.txt output_filename.txt\n");
               
        return -1;
    }
}
