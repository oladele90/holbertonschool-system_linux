#include "h_elf.h"

int set_arch(elf_t *elf_head, int fd, char **av)
{
	int rl = 0;

	if (is_64(elf_head->e64))
		return (0);
	lseek(fd, 0, SEEK_SET);
	rl = read(fd, &(elf_head->e32), sizeof(elf_head->e32));
	if (sizeof(elf_head->e32) != rl)
	{
		fprintf(stderr, ERR_NOT_ELF, av[0]);
		exit(1);
	}
	return (1);
}

int is_elf(Elf64_Ehdr e64)
{
	if (e64.e_ident[EI_MAG0] == ELFMAG0 &&
		e64.e_ident[EI_MAG1] == ELFMAG1 &&
		e64.e_ident[EI_MAG2] == ELFMAG2 &&
		e64.e_ident[EI_MAG3] == ELFMAG3)
		return (1);
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
	return (0);
}

int set_endian(elf_t *elf_head)
{
	if (is_little(elf_head->e64))
		return (0);
	switch_all_endian(elf_head);
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
	return (0);
}

