#include "h_elf.h"

/**
 * print_machine - Prints the machine architecture of the ELF file.
 * @elf_head: Pointer to the ELF header structure.
 *
 * Return: Always 0.
 */

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
