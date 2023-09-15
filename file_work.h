#ifndef FILE_WORK_H
#define FILE_WORK_H

struct File_to_Buffer {
    int file_size;
    char* buffer;
    int nlines;
    char** text;
};

File_to_Buffer* get_buffer_from_file(const char* filename);
void print_to_file(File_to_Buffer* file_and_buffer, const char* filename);

#endif