#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class_and_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi_and_type(unsigned char *e_ident, unsigned int e_type);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * process_elf_header - Process and print ELF header information.
 * @header: Pointer to the ELF header structure.
 *
 * Description:
 *     This function processes and prints various fields from the ELF header.
 */
void process_elf_header(Elf64_Ehdr *header)
{
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class_and_data(header->e_ident);
	print_version(header->e_ident);
	print_abi_and_type(header->e_ident, header->e_type);
	print_entry(header->e_entry, header->e_ident);
}

/**
 * main - Main entry point of the program.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	process_elf_header(header);

	free(header);
	close_elf(o);
	return (0);
}

