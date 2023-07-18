#include "h_elf.h"

/**
 * print_e_version - Prints the ELF version.
 * @elf_head: Pointer to the ELF header structure.
 *
 * Return: Always 0.
 */
int print_e_version(elf_t *elf_head)
{
	printf("  Version:                           0x%lx\n",
		IS_32(elf_head->e64)
			? (unsigned long)elf_head->e32.e_version
			: (unsigned long)elf_head->e64.e_version);
	return (0);
}

/**
 * print_flags - Prints the ELF header flags.
 * @elf_head: Pointer to the ELF header structure.
 *
 * Return: Always 0.
 */
int print_flags(elf_t *elf_head)
{
	printf("  Flags:                             0x");
	if (IS_32(elf_head->e64))
		printf("%lx", (unsigned long)elf_head->e32.e_flags);
	else
		printf("%lx", (unsigned long)elf_head->e64.e_flags);
	printf("\n");

	printf("  Size of this header:               %ld (bytes)\n",
		IS_32(elf_head->e64) ? (long)elf_head->e32.e_ehsize
		: (long)elf_head->e64.e_ehsize);

	printf("  Size of program headers:           %ld (bytes)\n",
		IS_32(elf_head->e64) ? (long)elf_head->e32.e_phentsize
		: (long)elf_head->e64.e_phentsize);

	printf("  Number of program headers:         %ld\n",
		IS_32(elf_head->e64) ? (long)elf_head->e32.e_phnum
		: (long)elf_head->e64.e_phnum);
	printf("  Size of section headers:           %ld (bytes)\n",
		IS_32(elf_head->e64) ? (long)elf_head->e32.e_shentsize
		: (long)elf_head->e64.e_shentsize);
	printf("  Number of section headers:         %ld\n",
		IS_32(elf_head->e64) ? (long)elf_head->e32.e_shnum
		: (long)elf_head->e64.e_shnum);
	printf("  Section header string table index: %ld\n",
		IS_32(elf_head->e64) ? (long)elf_head->e32.e_shstrndx
		: (long)elf_head->e64.e_shstrndx);
	return (0);
}

/**
 * print_head - Prints the ELF header information.
 * @elf_head: Pointer to the ELF header structure.
 *
 * Return: Always 0.
 */
int print_head(elf_t *elf_head)
{
	printf("ELF Header:\n");
	print_magic(&elf_head->e64);
	print_class(&elf_head->e64);
	print_data(&elf_head->e64);
	print_version(&elf_head->e64);
	print_osabi(&elf_head->e64);
	print_abiversion(&elf_head->e64);
	print_type(elf_head);
	print_machine(&elf_head->e64);
	print_e_version(elf_head);
	print_entry(elf_head);
	print_e_phoff_shoff(elf_head);
	print_flags(elf_head);
	return (0);
}

/**
 * get_type - Returns a string representation of the ELF file type.
 * @elf_head: Pointer to the ELF header structure.
 *
 * Return: String representing the ELF file type.
 */
char *get_type(elf_t *elf_head)
{
	static char buf[32];

	switch (EGET(e_type))
	{
		case ET_NONE:
			return ("NONE (None)");
		case ET_REL:
			return ("REL (Relocatable file)");
		case ET_EXEC:
			return ("EXEC (Executable file)");
		case ET_DYN:
			return ("DYN (Shared object file)");
		case ET_CORE:
			return ("CORE (Core file)");
		default:
			sprintf(buf, "<unknown>: %x", EGET(e_type));
	}
	return (buf);
}

/**
 * print_e_phoff_shoff - Prints the program header and section header offsets.
 * @elf_head: Pointer to the ELF header structure.
 *
 * Return: Always 0.
 */
int print_e_phoff_shoff(elf_t *elf_head)
{
	printf("  Start of program headers:          ");
	if (is_64(elf_head->e64))
	{
		printf("%lu (bytes into file)\n",
			(unsigned long)elf_head->e64.e_phoff);
	}
	else
	{
		printf("%lu (bytes into file)\n",
			(unsigned long)elf_head->e32.e_phoff);
	}
	printf("  Start of section headers:          ");
	if (is_64(elf_head->e64))
	{
		printf("%lu (bytes into file)\n",
			(unsigned long)elf_head->e64.e_shoff);
	}
	else
	{
		printf("%lu (bytes into file)\n",
			(unsigned long)elf_head->e32.e_shoff);
	}
	return (0);
}
