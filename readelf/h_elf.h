#ifndef H_ELF_H_
#define H_ELF_H_

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define IS_BE(x) ((x).e_ident[EI_DATA] == ELFDATA2MSB)
#define ERR_NOT_READ "%s: Error: Input file '%s' is not readable.\n"
#define ERR_FILE_NOT_FOUND "%s: Error: '%s': No such file\n"
#define ERR_NOT_ELF "%s: Error: Not an ELF file - wrong magic\n"
#define EGET(x) \
	(IS_32(elf_head->e64) ? elf_head->e32.x : elf_head->e64.x)
#define IS_32(x) ((x).e_ident[EI_CLASS] == ELFCLASS32)

/**
 * struct ElfStructs - stores 32/64 structs
 * @e64: 64 bit struct
 * @e32: 32 bit struct
 * @es64: Pointer to an array of 64-bit section header structs.
 * @es32: Pointer to an array of 32-bit section header structs.
*/

typedef struct ElfStructs
{
	Elf64_Ehdr e64;
	Elf32_Ehdr e32;
	Elf64_Shdr *es64;
	Elf32_Shdr *es32;
} elf_t;



void switch_all_endian(elf_t *h);
unsigned long switch_endian8(unsigned long n);
unsigned int switch_endian4(unsigned int n);
unsigned short switch_endian2(unsigned short n);

int print_osabi(Elf64_Ehdr *elf_head);
int print_version(Elf64_Ehdr *elf_head);
int print_data(Elf64_Ehdr *elf_head);
int print_class(Elf64_Ehdr *elf_head);
int print_magic(Elf64_Ehdr *elf_head);
int print_osabi_b(Elf64_Ehdr *elf_head);
int print_machine(Elf64_Ehdr *elf_head);
char *get_machine(Elf64_Ehdr *elf_head);
int print_entry(elf_t *elf_head);
int print_type(elf_t *elf_head);
char *get_type(elf_t *elf_head);
int print_abiversion(Elf64_Ehdr *elf_head);
int print_head(elf_t *elf_head);
int print_flags(elf_t *elf_head);
int print_e_phoff_shoff(elf_t *elf_head);
int is_elf(Elf64_Ehdr e64);
int is_64(Elf64_Ehdr e64);
int is_little(Elf64_Ehdr e64);
int set_arch(elf_t *elf_head, int fd, char **av);
int set_endian(elf_t *elf_head);
int print_section(elf_t *elf_head, int fd);
int handle_section(elf_t *elf_head, int fd);
int print_footer(elf_t *elf_head);
int print_64_section(elf_t *elf_head, int fd);
int print_32_section(elf_t *elf_head, int fd);
char *get_type_32(elf_t *elf_head, int i);
char *get_type_32_2(elf_t *elf_head, int i);
char *get_type_64(elf_t *elf_head, int i);
char *get_type_64_2(elf_t *elf_head, int i);
char *get_flag(elf_t *elf_head, int i);
char *get_table(elf_t *elf_head, int fd);
int free_all(elf_t *elf_head);
void switch_endian_section(elf_t *h, size_t i);

#endif
