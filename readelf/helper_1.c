#include "h_elf.h"

/**
 * set_arch - sets architecture of file either 64 bit or 32
 * @elf_head: struct
 * @fd: file descriptor
 * @av: argument vector holds filename and program name
 * Return: exit status or 0
*/
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

/**
 * is_elf - checks if file is elf file
 * @e64: 64 bi elf header
 * Return: 1 or 0
*/

int is_elf(Elf64_Ehdr e64)
{
	if (e64.e_ident[EI_MAG0] == ELFMAG0 &&
		e64.e_ident[EI_MAG1] == ELFMAG1 &&
		e64.e_ident[EI_MAG2] == ELFMAG2 &&
		e64.e_ident[EI_MAG3] == ELFMAG3)
		return (1);
	return (0);
}

/**
 * is_64 - checks if arch is 32 or 64 bit
 * @e64: struct
 * Return: 0 or exit status
*/
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

/**
 * set_endian - sets endianess
 * @elf_head: struct
 * Return: 1 or 0
 */

int set_endian(elf_t *elf_head)
{
	if (is_little(elf_head->e64))
		return (0);
	switch_all_endian(elf_head);
	return (1);
}

/**
 * is_little - check if endian is little
 * @e64: 64-bit struct
 * Return: 0, 1, or exit status
*/
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

