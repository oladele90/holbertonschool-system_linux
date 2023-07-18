#include "h_elf.h"

int main(int ac, char **av)
{
    elf_t elf_head;
    int fd = 0, rl;
    char *fn = NULL;

    if (ac != 2)
        {
            fprintf(stderr, "./#-hreadelf <file name missing>\n");
            exit(1);
        }
    memset(&elf_head, 0, sizeof(elf_head));
    fn = av[1];
    fd = open(fn, O_RDONLY);
    if (fd == -1)
	{
		if (errno == ENOENT)
			fprintf(stderr, ERR_FILE_NOT_FOUND, av[0], fn);
		else if (errno == EACCES)
			fprintf(stderr, ERR_NOT_READ, av[0], fn);
		exit(1);
	}
    rl = read(fd, &elf_head.e64, sizeof(elf_head.e64));
    if (sizeof(elf_head.e64) != rl || !is_elf(elf_head.e64))
	{
		fprintf(stderr, ERR_NOT_ELF, av[0]);
		exit(1);
	}
    set_arch(&elf_head, fd, av);
	set_endian(&elf_head);
	print_head(&elf_head);
    close(fd);
    return (0);
}