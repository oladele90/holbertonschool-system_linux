#include "_getline.h"

char *_getline(const int fd)
{
    static size_t buf_probe = 0;
    char *temp;
    static ssize_t read_bytes;
    size_t total_size = 0;
    static char r_buf[READ_SIZE];
    char *string_form = malloc(sizeof(char) * READ_SIZE);
    for (; buf_probe < READ_SIZE && read_bytes == READ_SIZE; buf_probe++)
    {
        if (r_buf[buf_probe] == '\n')
        {
            memset(&r_buf[buf_probe], '\0', 1);
            memset(&string_form[total_size], r_buf[buf_probe], 1);
            total_size += 1;
            return (string_form);
        }
        if (r_buf[buf_probe] != '\0')
        {
            memset(&string_form[total_size], r_buf[buf_probe], 1);
            total_size += 1;
        }
    }
    read_bytes = read(fd, r_buf, READ_SIZE);
    if (read_bytes <= 0)
            return (NULL);
    
    while (!strstr(r_buf, "\n") && read_bytes == READ_SIZE)
    {
        temp = realloc(string_form, total_size + read_bytes + 1);
        string_form = temp;
        memcpy(string_form + total_size, r_buf, read_bytes);
        total_size += read_bytes;
        read_bytes = read(fd, r_buf, READ_SIZE);
    }
    temp = realloc(string_form, total_size + read_bytes + 1);
    string_form = temp;
    for (buf_probe = 0; buf_probe < READ_SIZE; buf_probe++)
    {
        if (r_buf[buf_probe] == '\n')
        {
            memset(&r_buf[buf_probe], '\0', 1);
            memset(&string_form[total_size], r_buf[buf_probe], 1);
            total_size += 1;
            return (string_form);
        }
        if (r_buf[buf_probe] != '\0')
        {
            memset(&string_form[total_size], r_buf[buf_probe], 1);
            total_size += 1;
        }
    }
    return (string_form);
}