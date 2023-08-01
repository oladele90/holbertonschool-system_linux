#include "hreadelf.h"

int process_file(char *file_name, int multiple, char **argv)
{
	int fd, exit_status = 0;
	size_t r, num_printed = 0;
	elf_t elf_header;

	memset(&elf_header, 0, sizeof(elf_header));

	fd = open_file(file_name, 0, argv);
	if (fd == -1)
		return (EXIT_FAILURE);

	r = read(fd, &elf_header.e64, sizeof(elf_header.e64));
	if (r != sizeof(elf_header.e64) || check_elf((char *)&elf_header.e64))
	{
		fprintf(stderr, "%s: %s: File format not recognized\n", argv[0], file_name);
		exit_status = EXIT_FAILURE;
	}
	else
	{
		if (IS_32(elf_header.e64))
		{
			lseek(fd, 0, SEEK_SET);
			r = read(fd, &elf_header.e32, sizeof(elf_header.e32));
			if (r != sizeof(elf_header.e32) || check_elf((char *)&elf_header.e32))
				exit_status = fprintf(stderr, ERR_NOT_MAGIC, argv[0]), EXIT_FAILURE;
		}
		if (multiple)
			printf("\n%s:\n", file_name);
		switch_all_endian(&elf_header);
		exit_status = print_all_symbol_tables(&elf_header, fd, &num_printed);
		if (!num_printed)
			fprintf(stderr, "%s: %s: no symbols\n", argv[0], file_name);
	}
	free(elf_header.s32);
	free(elf_header.s64);
	free(elf_header.p32);
	free(elf_header.p64);
	close(fd);
	return (exit_status);
}

void read_section_headers(elf_t *elf_header, int fd)
{
	size_t i = EGET(e_shnum), r;
	char *headers;
	size_t read_size = EGET(e_shentsize) * EGET(e_shnum);

	if (!i)
		return;
	headers = calloc(i, read_size * i);
	if (!headers)
		exit(1);
	lseek(fd, EGET(e_shoff), SEEK_SET);
	r = read(fd, headers, read_size);
	if (r < read_size)
		exit(1);
	if (IS_32(elf_header->e64))
		elf_header->s32 = (void *)headers;
	else
		elf_header->s64 = (void *)headers;
}

char *read_string_table(elf_t *elf_header, int fd)
{
	char *str;

	str = calloc(1, SGET(EGET(e_shstrndx), sh_size));
	if (!str)
		exit(1);

	lseek(fd, SGET(EGET(e_shstrndx), sh_offset), SEEK_SET);
	read(fd, str, SGET(EGET(e_shstrndx), sh_size));
	return (str);
}

char *get_section_type(unsigned int sh_type)
{
	static char buf[32];

	switch (sh_type)
	{
	case SHT_NULL:		return ("NULL");
	case SHT_PROGBITS:		return ("PROGBITS");
	case SHT_SYMTAB:		return ("SYMTAB");
	case SHT_STRTAB:		return ("STRTAB");
	case SHT_RELA:		return ("RELA");
	case SHT_HASH:		return ("HASH");
	case SHT_DYNAMIC:		return ("DYNAMIC");
	case SHT_NOTE:		return ("NOTE");
	case SHT_NOBITS:		return ("NOBITS");
	case SHT_REL:		return ("REL");
	case SHT_SHLIB:		return ("SHLIB");
	case SHT_DYNSYM:		return ("DYNSYM");
	case SHT_INIT_ARRAY:	return ("INIT_ARRAY");
	case SHT_FINI_ARRAY:	return ("FINI_ARRAY");
	case SHT_PREINIT_ARRAY:	return ("PREINIT_ARRAY");
	case SHT_GNU_HASH:		return ("GNU_HASH");
	case SHT_GROUP:		return ("GROUP");
	case SHT_SYMTAB_SHNDX:	return ("SYMTAB SECTION INDICIES");
	case SHT_GNU_verdef:	return ("VERDEF");
	case SHT_GNU_verneed:	return ("VERNEED");
	case SHT_GNU_versym:	return ("VERSYM");
	case 0x6ffffff0:		return ("VERSYM");
	case 0x6ffffffc:		return ("VERDEF");
	case 0x7ffffffd:		return ("AUXILIARY");
	case 0x7fffffff:		return ("FILTER");
	case 0x6ffffff1:		return ("LOOS+ffffff1");
	case 0x6ffffff3:		return ("LOOS+ffffff3");
	case SHT_GNU_LIBLIST:	return ("GNU_LIBLIST");
	default:
		sprintf(buf, "%08x: <unknown>", sh_type);
		return (buf);
	}
}

int check_elf(char *elf_header)
{
	if (elf_header[0] == 0x7f && elf_header[1] == 0x45 &&
		elf_header[2] == 0x4c && elf_header[3] == 0x46)
		return (0);
	return (1);
}
