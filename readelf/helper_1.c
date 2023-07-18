#include "h_elf.h"

int set_arch(elf_t *new_elf, int fd, char **av)
{
	int rl = 0;

	if (is_64(new_elf->e64))
		return (0);
	lseek(fd, 0, SEEK_SET);
	rl = read(fd, &(new_elf->e32), sizeof(new_elf->e32));
	if (sizeof(new_elf->e32) != rl)
	{
		fprintf(stderr, ERR_NOT_ELF, av[0]);
		exit(1);
	}
    printf("arch checked\n");
	return (1);
}

int is_elf(Elf64_Ehdr e64)
{
	if (e64.e_ident[EI_MAG0] == ELFMAG0 &&
		e64.e_ident[EI_MAG1] == ELFMAG1 &&
		e64.e_ident[EI_MAG2] == ELFMAG2 &&
		e64.e_ident[EI_MAG3] == ELFMAG3)
		return (1);
    printf("checked elfness\n");
	return (0);
}

int is_64(Elf64_Ehdr e64)
{
	switch (e64.e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		return (0);
	case ELFCLASS64:
		return (1);
	default:
		fprintf(stderr, "No Class\n");
		exit(1);
	}
    printf("class checked\n");
	return (0);
}

int set_endian(elf_t *new_elf)
{
	if (is_little(new_elf->e64))
		return (0);
	switch_all_endian(new_elf);
    printf("end set\n");
	return (1);
}

int is_little(Elf64_Ehdr e64)
{
	switch (e64.e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		return (1);
	case ELFDATA2MSB:
		return (0);
	default:
		fprintf(stderr, "Endian Unknown\n");
		exit(1);
	}
    printf("end checked\n");
	return (0);
}

