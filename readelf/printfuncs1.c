#include "h_elf.h"
int print_magic(Elf64_Ehdr *elf_head)
{
    size_t i;

	printf("  Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%.2x ", elf_head->e_ident[i]);
	printf("\n");
	return (0);
}

int print_class(Elf64_Ehdr *elf_head)
{
	printf("  Class: ");
	switch (elf_head->e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
		break;
		case ELFCLASS32:
			printf("ELF32");
		break;
		case ELFCLASSNONE:
			printf("none");
		break;
		default:
			printf("<unknown: %x>", elf_head->e_ident[EI_CLASS]);
		break;
	}
	printf("\n");
	return (0);
}

int print_data(Elf64_Ehdr *elf_head)
{
	printf("  Data: ");
	switch (elf_head->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian");
		break;
		case ELFDATA2MSB:
			printf("2's complement, big endian");
		break;
		case ELFDATANONE:
			printf("none");
		break;
		default:
			printf("<unknown: %x>", elf_head->e_ident[EI_DATA]);
		break;
	}
	printf("\n");
	return (0);
}

int print_version(Elf64_Ehdr *elf_head)
{
	printf("  Version: %d ",
		elf_head->e_ident[EI_VERSION]);
	if (elf_head->e_ident[EI_VERSION] == EV_CURRENT)
		printf("(current)");
	else if (elf_head->e_ident[EI_VERSION] != EV_NONE)
		printf("<unknown: %x", elf_head->e_ident[EI_VERSION]);
	printf("\n");
	return (0);
}

int print_osabi(Elf64_Ehdr *elf_head)
{
	printf("  OS/ABI: ");
	switch (elf_head->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			return (print_osabi_b(elf_head));
		break;
	}
	printf("\n");
	return (0);
}
