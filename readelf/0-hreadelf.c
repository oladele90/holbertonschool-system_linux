#include "elf.h"

void convert_end(char *ptr, size_t size)
{
    size_t tmp, start, end;

    for (start = 0, end = size - 1; start < end; ++start, --end)
    {
        tmp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = tmp;
    }
}

int main(int argc, char **argv)
{
    int fd, exit_status = 0;
    size_t r;
    elf_t elf_head;

    memset(&elf_head, 0, sizeof(elf_head));
    if (argc != 2)
        return (EXIT_FAILURE);
    fd = open(argv[1], O_RDONLY);
        if (fd == -1)
            return (EXIT_FAILURE);
    r = read(fd, &elf_head.e64, sizeof(elf_head.e64));
    if (r != sizeof(elf_head.e64))
        exit_status = EXIT_FAILURE;
    else
    {
        if (IS_32(elf_head.e64))
        {
            lseek(fd, 0, SEEK_SET);
            r = read(fd, &elf_head.e32, sizeof(elf_head.e32));
			if (r != sizeof(elf_head.e32))
                exit_status = EXIT_FAILURE;
            convert_end((char *) &elf_head, sizeof(elf_head));
            exit_status = print_head(&elf_head);
        }
    }
    close(fd);
    printf("endy");
    return (exit_status);
}
