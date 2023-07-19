#include "h_elf.h"

/**
 * get_type_64 - Retrieves the string representation of section type (64-bit).
 * @elf_head: Pointer to the ELF header structure.
 * @i: Index of the section header.
 * Return: Pointer to the string representation of section type.
 */
char *get_type_64(elf_t *elf_head, int i)
{
	switch (elf_head->es64[i].sh_type)
	{
	case SHT_NULL:
		return ("NULL");
	case SHT_PROGBITS:
		return ("PROGBITS");
	case SHT_SYMTAB:
		return ("SYMTAB");
	case SHT_STRTAB:
		return ("STRTAB");
	case SHT_RELA:
		return ("RELA");
	case SHT_HASH:
		return ("HASH");
	case SHT_DYNAMIC:
		return ("DYNAMIC");
	case SHT_NOTE:
		return ("NOTE");
	case SHT_NOBITS:
		return ("NOBITS");
	case SHT_REL:
		return ("REL");
	case SHT_SHLIB:
		return ("SHLIB");
	case SHT_DYNSYM:
		return ("DYNSYM");
	case SHT_INIT_ARRAY:
		return ("INIT_ARRAY");
	case SHT_FINI_ARRAY:
		return ("FINI_ARRAY");
	case SHT_GROUP:
		return ("GROUP");
	case SHT_SYMTAB_SHNDX:
		return ("SYMTAB SECTION INDICIES");
	default:
		return (get_type_64_2(elf_head, i));
	}
}

/**
 * get_type_64_2 - Retrieves the string representation of section type.
 * @elf_head: Pointer to the ELF header structure.
 * @i: Index of the section header.
 * Return: Pointer to the string representation of section type.
 */
char *get_type_64_2(elf_t *elf_head, int i)
{
	static char str[25];

	switch (elf_head->es64[i].sh_type)
	{
	case SHT_PREINIT_ARRAY:
		return ("PREINIT_ARRAY");
	case SHT_GNU_HASH:
		return ("GNU_HASH");
	case SHT_GNU_verdef:
		return ("VERDEF");
	case SHT_GNU_verneed:
		return ("VERNEED");
	case SHT_GNU_versym:
		return ("VERSYM");
	case 0x6ffffff0:
		return ("VERSYM");
	case 0x6ffffffc:
		return ("VERDEF");
	case 0x7ffffffd:
		return ("AUXILIARY");
	case 0x7fffffff:
		return ("FILTER");
	case 0x6ffffff1:
		return ("LOOS+ffffff1");
	case 0x6ffffff3:
		return ("LOOS+ffffff3");
	case SHT_GNU_LIBLIST:
		return ("GNU_LIBLIST");
	default:
		sprintf(str, "%08x: <unknown>",
				elf_head->es64[i].sh_type);
		break;
	}
	return (str);
}

/**
 * get_type_32 - Retrieves the string representation of section type (32-bit).
 * @elf_head: Pointer to the ELF header structure.
 * @i: Index of the section header.
 * Return: Pointer to the string representation of section type.
 */
char *get_type_32(elf_t *elf_head, int i)
{
	switch (elf_head->es32[i].sh_type)
	{
	case SHT_NULL:
		return ("NULL");
	case SHT_PROGBITS:
		return ("PROGBITS");
	case SHT_SYMTAB:
		return ("SYMTAB");
	case SHT_STRTAB:
		return ("STRTAB");
	case SHT_RELA:
		return ("RELA");
	case SHT_HASH:
		return ("HASH");
	case SHT_DYNAMIC:
		return ("DYNAMIC");
	case SHT_NOTE:
		return ("NOTE");
	case SHT_NOBITS:
		return ("NOBITS");
	case SHT_REL:
		return ("REL");
	case SHT_SHLIB:
		return ("SHLIB");
	case SHT_DYNSYM:
		return ("DYNSYM");
	case SHT_INIT_ARRAY:
		return ("INIT_ARRAY");
	case SHT_FINI_ARRAY:
		return ("FINI_ARRAY");
	case SHT_GROUP:
		return ("GROUP");
	case SHT_SYMTAB_SHNDX:
		return ("SYMTAB SECTION INDICIES");
	default:
		return (get_type_32_2(elf_head, i));
	}
}

/**
 * get_type_32_2 - Retrieves the string representation of section type.
 * @elf_head: Pointer to the ELF header structure.
 * @i: Index of the section header.
 * Return: Pointer to the string representation of section type.
 */
char *get_type_32_2(elf_t *elf_head, int i)
{
	static char str[25];

	switch (elf_head->es32[i].sh_type)
	{
	case SHT_PREINIT_ARRAY:
		return ("PREINIT_ARRAY");
	case SHT_GNU_HASH:
		return ("GNU_HASH");
	case SHT_GNU_verdef:
		return ("VERDEF");
	case SHT_GNU_verneed:
		return ("VERNEED");
	case SHT_GNU_versym:
		return ("VERSYM");
	case 0x6ffffff0:
		return ("VERSYM");
	case 0x6ffffffc:
		return ("VERDEF");
	case 0x7ffffffd:
		return ("AUXILIARY");
	case 0x7fffffff:
		return ("FILTER");
	case 0x6ffffff1:
		return ("LOOS+ffffff1");
	case 0x6ffffff3:
		return ("LOOS+ffffff3");
	case SHT_GNU_LIBLIST:
		return ("GNU_LIBLIST");
	default:
		sprintf(str, "%08x: <unknown>",
				elf_head->es32[i].sh_type);
		break;
	}
	return (str);
}
