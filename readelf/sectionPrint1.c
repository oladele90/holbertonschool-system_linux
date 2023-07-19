#include "h_elf.h"

int print_section(elf_t *elf_head, int fd)
{
	size_t i = 0;

	if (is_64(elf_head->e64) && !elf_head->e64.e_shnum)
	{
		printf("No section in file\n");
		return (1);
	}
	if (!is_64(elf_head->e64) && !elf_head->e32.e_shnum)
	{
		printf("No section in file\n");
		return (1);
	}

	if (is_64(elf_head->e64))
		printf("There are %d section headers, starting at offset 0x%lx:\n",
			   elf_head->e64.e_shnum, elf_head->e64.e_shoff);
	else
		printf("There are %d section headers, starting at offset 0x%lx:\n",
			   elf_head->e32.e_shnum,
			   (unsigned long)elf_head->e32.e_shoff);
	handle_section(elf_head, fd);
	printf("\nSection Headers:\n");
    for (i = 0; i < EGET(e_shnum); i++)
		switch_endian_section(elf_head, i);
    if (is_64(elf_head->e64))
        print_64_section(elf_head, fd);
    else
        print_32_section(elf_head, fd);
	print_footer(elf_head);
	return (0);
}

int handle_section(elf_t *elf_head, int fd)
{
	uint16_t shnum_64 = elf_head->e64.e_shnum;
	uint16_t shnum_32 = elf_head->e32.e_shnum;
	uint16_t shentsize64 = elf_head->e64.e_shentsize;
	uint16_t shentsize32 = elf_head->e32.e_shentsize;
	int read_size = 0;

	if (is_64(elf_head->e64))
	{
		elf_head->es64 = calloc(shnum_64, shentsize64);
		if (!elf_head->es64)
			exit(1);
		lseek(fd, elf_head->e64.e_shoff, SEEK_SET);
		read_size = read(fd, elf_head->es64, shnum_64 * shentsize64);
		if (read_size < shnum_64 * shentsize64)
			exit(1);
	}
	else
	{
		elf_head->es32 = calloc(shnum_32, shentsize32);
		if (!elf_head->es32)
			exit(1);
		lseek(fd, elf_head->e32.e_shoff, SEEK_SET);
		read_size = read(fd, elf_head->es32, shnum_32 * shentsize32);
		if (read_size < shnum_32 * shentsize32)
			exit(1);
	}

	return (0);
}

int print_footer(elf_t *elf_head)
{
	char *str[] = {"Key to Flags:\n",
				   "  W (write), A (alloc), X (execute),",
				   " M (merge), S (strings)",
				   "  I (info), L (link order), G (group),",
				   " T (TLS), E (exclude), x (unknown)\n",
				   "  O (extra OS processing required) o (OS specific),",
				   " p (processor specific)\n"};
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		if (i == 2)
		{
			if (is_64(elf_head->e64))
				printf("%s%s\n", str[i], ", l (large)");
			else
				printf("%s\n", str[i]);
		}
		else
			printf("%s", str[i]);
	}

	return (0);
}

int print_64_section(elf_t *elf_head, int fd)
{
	unsigned int i = 0;
	char *str_table = NULL;

	str_table = get_table(elf_head, fd);
	printf("  [Nr] Name              Type            Address");
	printf("          Off    Size   ES Flg Lk Inf Al\n");
	for (i = 0; i < elf_head->e64.e_shnum; i++)
	{
		printf("  [%2u] %-17s %-15.15s %16.16lx %6.6lx",
			   i,
			   &str_table[elf_head->es64[i].sh_name],
			   get_type_64(elf_head, i),
			   elf_head->es64[i].sh_addr,
			   elf_head->es64[i].sh_offset);
		printf(" %6.6lx %2.2lx %3s %2u %3u %2lu\n",
			   elf_head->es64[i].sh_size,
			   elf_head->es64[i].sh_entsize,
			   get_flag(elf_head, i),
			   elf_head->es64[i].sh_link,
			   elf_head->es64[i].sh_info,
			   elf_head->es64[i].sh_addralign);
	}
	free(str_table);
	return (0);
}

int print_32_section(elf_t *elf_head, int fd)
{
	unsigned int i = 0;
	char *str_table = NULL;

	str_table = get_table(elf_head, fd);
	printf("  [Nr] Name              Type            Addr     ");
	printf("Off    Size   ES Flg Lk Inf Al\n");
	for (i = 0; i < elf_head->e32.e_shnum; i++)
	{
		printf("  [%2u] %-17s %-15.15s %8.8lx %6.6lx",
			   i,
			   &str_table[elf_head->es32[i].sh_name],
			   get_type_32(elf_head, i),
			   (unsigned long)elf_head->es32[i].sh_addr,
			   (unsigned long)elf_head->es32[i].sh_offset);
		printf(" %6.6lx %2.2lx %3s %2u %3u %2lu\n",
			   (unsigned long)elf_head->es32[i].sh_size,
			   (unsigned long)elf_head->es32[i].sh_entsize,
			   get_flag(elf_head, i),
			   elf_head->es32[i].sh_link,
			   elf_head->es32[i].sh_info,
			   (unsigned long)elf_head->es32[i].sh_addralign);
	}
	free(str_table);
	return (0);
}



