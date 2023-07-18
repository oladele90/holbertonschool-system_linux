#include "h_elf.h"

int main(int ac, char **av)
{
    elf_t new_elf;
    int fd = 0, rl;
    char *fn = NULL;

    if (ac != 2)
        {
            fprintf(stderr, "./#-hreadelf <file name missing>\n");
            exit(1);
        }
    memset(&new_elf, 0, sizeof(new_elf));
    fn = av[1];
    fd = open(fn, O_RDONLY);
    printf("im fd %d\n", fd);
    if (fd == -1)
	{
		if (errno == ENOENT)
			fprintf(stderr, ERR_FILE_NOT_FOUND, av[0], fn);
		else if (errno == EACCES)
			fprintf(stderr, ERR_NOT_READ, av[0], fn);
		exit(1);
	}
    rl = read(fd, &new_elf.e64, sizeof(new_elf.e64));
    printf("im rl %d\n", rl);
    if (sizeof(new_elf.e64) != rl || !is_elf(new_elf.e64))
	{
		fprintf(stderr, ERR_NOT_ELF, av[0]);
		exit(1);
	}
    set_arch(&new_elf, fd, av);
	set_endian(&new_elf);
	print_head(&new_elf);
    close(fd);
    return (0);
}