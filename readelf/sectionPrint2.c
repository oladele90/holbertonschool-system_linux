#include "h_elf.h"

char *get_table(elf_t *elf_head, int fd)
{
	char *str;

	if (is_64(elf_head->e64))
	{
		str = calloc(1,
			elf_head->es64[elf_head->e64.e_shstrndx].sh_size);
		if (!str)
			exit(1);

		lseek(fd, elf_head->es64[elf_head->e64.e_shstrndx].sh_offset,
			SEEK_SET);
		read(fd, str,
			elf_head->es64[elf_head->e64.e_shstrndx].sh_size);
	}
	else
	{
		str = calloc(1,
			elf_head->es32[elf_head->e32.e_shstrndx].sh_size);
		if (!str)
			exit(1);

		lseek(fd, elf_head->es32[elf_head->e32.e_shstrndx].sh_offset,
			SEEK_SET);
		read(fd, str,
			elf_head->es32[elf_head->e32.e_shstrndx].sh_size);
	}
	return (str);
}

char *get_flag(elf_t *elf_head, int i)
{
	static char str[6];
	char *str_cpy = str;

	if (is_64(elf_head->e64))
	{
		if (elf_head->es64[i].sh_flags & SHF_WRITE)
			*str_cpy++ = 'W';
		if (elf_head->es64[i].sh_flags & SHF_ALLOC)
			*str_cpy++ = 'A';
		if (elf_head->es64[i].sh_flags & SHF_EXECINSTR)
			*str_cpy++ = 'X';
		if (elf_head->es64[i].sh_flags & SHF_MERGE)
			*str_cpy++ = 'M';
		if (elf_head->es64[i].sh_flags & SHF_STRINGS)
			*str_cpy++ = 'S';
		if (elf_head->es64[i].sh_flags & SHF_INFO_LINK)
			*str_cpy++ = 'I';
		if (elf_head->es64[i].sh_flags & SHF_EXCLUDE)
			*str_cpy++ = 'E';
	}
	else
	{
		if (elf_head->es32[i].sh_flags & SHF_WRITE)
			*str_cpy++ = 'W';
		if (elf_head->es32[i].sh_flags & SHF_ALLOC)
			*str_cpy++ = 'A';
		if (elf_head->es32[i].sh_flags & SHF_EXECINSTR)
			*str_cpy++ = 'X';
		if (elf_head->es32[i].sh_flags & SHF_MERGE)
			*str_cpy++ = 'M';
		if (elf_head->es32[i].sh_flags & SHF_STRINGS)
			*str_cpy++ = 'S';
		if (elf_head->es32[i].sh_flags & SHF_INFO_LINK)
			*str_cpy++ = 'I';
		if (elf_head->es32[i].sh_flags & SHF_EXCLUDE)
			*str_cpy++ = 'E';
	}
	*str_cpy = 0;
	return (str);
}

int free_all(elf_t *elf_head)
{
	if (is_64(elf_head->e64))
		free(elf_head->es64);
	else
		free(elf_head->es32);

	return (0);
}