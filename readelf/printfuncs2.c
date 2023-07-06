#include "elf.h"

int print_osabi_b(Elf64_Ehdr *elf_head)
{
	switch (elf_head->e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("<unknown: %x>", elf_head->e_ident[EI_OSABI]);
			break;
	}
	printf("\n");
	return (0);
}

int print_abiversion(Elf64_Ehdr *elf_head)
{
	printf("  ABI Version: %d\n",
		elf_head->e_ident[EI_ABIVERSION]);
	return (0);
}

int print_type(elf_t *elf_head)
{
	printf("  Type: %s\n", get_type(elf_head));
	return (0);
}

int print_entry(elf_t *elf_head)
{
	if (IS_32(elf_head->e64))
		printf("  Entry point address: 0x%lx\n", EGET(e_entry));
	else
		printf("  Entry point address: 0x%lx\n", EGET(e_entry));
	return (0);
}

char *get_machine(Elf64_Ehdr *elf_head)
{
	switch (elf_head->e_machine)
	{
    case EM_PPC: return ("PowerPC");
    case EM_PPC64: return ("PowerPC64");
    case EM_S390: return ("IBM S/390");
    case EM_ARM: return ("ARM");
    case EM_SH: return ("Renesas / SuperH SH");
	case EM_SPARCV9: return ("Sparc v9");
    case EM_IA_64: return ("Intel IA-64");
    case EM_X86_64: return ("Advanced Micro Devices X86-64");
    case EM_VAX: return ("Digital VAX");
    case EM_NONE: return ("None");
    case EM_M32: return ("WE32100");
    case EM_SPARC: return ("Sparc");
	case EM_386: return ("Intel 80386");
    case EM_68K: return ("MC68000");
	case EM_88K: return ("MC88000");
	case EM_860: return ("Intel 80860");
    case EM_PARISC: return ("HPPA");
    case EM_SPARC32PLUS: return ("Sparc v8+");
    case EM_MIPS: return ("MIPS R3000");
    default: return (NULL);
    }
}

int print_machine(Elf64_Ehdr *elf_head)
{
	printf("  Machine:                           ");
	if (get_machine(elf_head))
		printf("%s", get_machine(elf_head));
	else
		printf("<unknown>: 0x%x", elf_head->e_machine);
	printf("\n");
	return (0);
}
