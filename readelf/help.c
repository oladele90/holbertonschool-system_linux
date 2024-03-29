#include "h_elf.h"

/**
 * switch_all_endian - switches endianess of architecture
 * @h: header struct to switch
 * Return: none
*/
void switch_all_endian(elf_t *h)
{
	if (IS_BE(h->e64))
	{
		h->e64.e_machine = switch_endian2(h->e64.e_machine);
		h->e64.e_version = switch_endian4(h->e64.e_version);
		h->e64.e_type = switch_endian2(h->e64.e_type);
		h->e64.e_flags = switch_endian4(h->e64.e_flags);
		h->e64.e_ehsize = switch_endian2(h->e64.e_ehsize);
		h->e64.e_phentsize = switch_endian2(h->e64.e_phentsize);
		h->e64.e_phnum = switch_endian2(h->e64.e_phnum);
		h->e64.e_shentsize = switch_endian2(h->e64.e_shentsize);
		h->e64.e_shnum = switch_endian2(h->e64.e_shnum);
		h->e64.e_shoff = switch_endian8(h->e64.e_shoff);
		h->e64.e_phoff = switch_endian8(h->e64.e_phoff);
		h->e64.e_entry = switch_endian8(h->e64.e_entry);
		h->e64.e_shstrndx = switch_endian2(h->e64.e_shstrndx);
	}
	if (IS_BE(h->e64) && IS_32(h->e64))
	{
		h->e32.e_machine = switch_endian2(h->e32.e_machine);
		h->e32.e_version = switch_endian4(h->e32.e_version);
		h->e32.e_type = switch_endian2(h->e32.e_type);
		h->e32.e_flags = switch_endian4(h->e32.e_flags);
		h->e32.e_ehsize = switch_endian2(h->e32.e_ehsize);
		h->e32.e_phentsize = switch_endian2(h->e32.e_phentsize);
		h->e32.e_phnum = switch_endian2(h->e32.e_phnum);
		h->e32.e_shentsize = switch_endian2(h->e32.e_shentsize);
		h->e32.e_shnum = switch_endian2(h->e32.e_shnum);
		h->e32.e_shoff = switch_endian4(h->e32.e_shoff);
		h->e32.e_phoff = switch_endian4(h->e32.e_phoff);
		h->e32.e_entry = switch_endian4(h->e32.e_entry);
		h->e32.e_shstrndx = switch_endian2(h->e32.e_shstrndx);
	}
}

/**
 * switch_endian2 - switches endianness on 2 byte unsigned int
 * @n: the unsigned int whose bytes to switch
 * Return: unsigned int with switched bytes
 */
unsigned short switch_endian2(unsigned short n)
{
	return (((n >> 8)  & 0x00ff) |
			((n << 8)  & 0xff00));
}

/**
 * switch_endian4 - switches endianness on 4 byte unsigned int
 * @n: the unsigned int whose bytes to switch
 * Return: unsigned int with switched bytes
 */
unsigned int switch_endian4(unsigned int n)
{
	return (((n >> 24) & 0x000000ff) |
			((n >> 8)  & 0x0000ff00) |
			((n << 8)  & 0x00ff0000) |
			((n << 24) & 0xff000000));
}

/**
 * switch_endian8 - switches endianness on 8 byte unsigned int
 * @n: the unsigned int whose bytes to switch
 * Return: unsigned int with switched bytes
 */
unsigned long switch_endian8(unsigned long n)
{
	return (((n >> 56) & 0x00000000000000ff) |
			((n >> 40) & 0x000000000000ff00) |
			((n >> 24) & 0x0000000000ff0000) |
			((n >> 8)  & 0x00000000ff000000) |
			((n << 8)  & 0x000000ff00000000) |
			((n << 24) & 0x0000ff0000000000) |
			((n << 40) & 0x00ff000000000000) |
			((n << 56) & 0xff00000000000000));
}

/**
 * switch_endian_section - Switches the endianness of the section at index i.
 * @h: Pointer to the ELF header structure.
 * @i: Index of the section header to switch endianness.
 * Return: none
 */

void switch_endian_section(elf_t *h, size_t i)
{
	if (IS_BE(h->e64) && !IS_32(h->e64))
	{
		h->es64[i].sh_name = switch_endian4(h->es64[i].sh_name);
		h->es64[i].sh_type = switch_endian4(h->es64[i].sh_type);
		h->es64[i].sh_flags = switch_endian8(h->es64[i].sh_flags);
		h->es64[i].sh_addr = switch_endian8(h->es64[i].sh_addr);
		h->es64[i].sh_offset = switch_endian8(h->es64[i].sh_offset);
		h->es64[i].sh_size = switch_endian8(h->es64[i].sh_size);
		h->es64[i].sh_link = switch_endian4(h->es64[i].sh_link);
		h->es64[i].sh_info = switch_endian4(h->es64[i].sh_info);
		h->es64[i].sh_addralign = switch_endian8(h->es64[i].sh_addralign);
		h->es64[i].sh_entsize = switch_endian8(h->es64[i].sh_entsize);
	}
	if (IS_BE(h->e64) && IS_32(h->e64))
	{
		h->es32[i].sh_name = switch_endian4(h->es32[i].sh_name);
		h->es32[i].sh_type = switch_endian4(h->es32[i].sh_type);
		h->es32[i].sh_flags = switch_endian4(h->es32[i].sh_flags);
		h->es32[i].sh_addr = switch_endian4(h->es32[i].sh_addr);
		h->es32[i].sh_offset = switch_endian4(h->es32[i].sh_offset);
		h->es32[i].sh_size = switch_endian4(h->es32[i].sh_size);
		h->es32[i].sh_link = switch_endian4(h->es32[i].sh_link);
		h->es32[i].sh_info = switch_endian4(h->es32[i].sh_info);
		h->es32[i].sh_addralign = switch_endian4(h->es32[i].sh_addralign);
		h->es32[i].sh_entsize = switch_endian4(h->es32[i].sh_entsize);
	}
}
