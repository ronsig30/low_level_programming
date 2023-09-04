#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 64

void check_elf(int fd, char *filename);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_ident);
void print_data(unsigned char e_ident);
void print_version(unsigned char e_ident);
void print_osabi(unsigned char e_ident);
void print_abi_version(unsigned char e_ident);
void print_type(unsigned int e_type);
void print_entry(unsigned long int e_entry);
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	int fd;
	char *filename = argv[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", filename);
		return (98);
	}

	check_elf(fd, filename);

	return (0);
}

/**
 * check_elf - Checks if the file is an ELF file and displays its header.
 * @fd: The file descriptor of the ELF file.
 * @filename: The name of the ELF file.
 */
void check_elf(int fd, char *filename)
{
	Elf64_Ehdr header;
	ssize_t n;

	n = read(fd, &header, sizeof(header));
	if (n == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", filename);
		close(fd);
		exit(98);
	}
	if (n < sizeof(header))
	{
		fprintf(stderr, "Error: %s is not an ELF file\n", filename);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident[EI_CLASS]);
	print_data(header.e_ident[EI_DATA]);
	print_version(header.e_ident[EI_VERSION]);
	print_osabi(header.e_ident[EI_OSABI]);
	print_abi_version(header.e_ident[EI_ABIVERSION]);
	print_type(header.e_type);
	print_entry(header.e_entry);

	close(fd);
}

/**
 * print_magic - Prints the ELF magic numbers.
 * @e_ident: A pointer to the ELF identification bytes.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], (i == EI_NIDENT - 1) ? '\n' : ' ');
}
/**
 * print_class - Prints the ELF class (32-bit or 64-bit).
 * @e_ident: A pointer to the ELF identification bytes.
 */
void print_class(unsigned char e_ident)
{
	printf("  Class:                             ");
	switch (e_ident)
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident);
	}
}
/**
 * print_data - Prints the ELF data encoding (little-endian or big-endian).
 * @e_ident: A pointer to the ELF identification bytes.
 */
void print_data(unsigned char e_ident)
{
	printf("  Data:                              ");
	switch (e_ident)
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident);
	}
}
/**
 * print_version - Prints the ELF version.
 * @e_ident: A pointer to the ELF identification bytes.
 */
void print_version(unsigned char e_ident)
{
	printf("  Version:                           %d", e_ident);
	switch (e_ident)
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}
}
/**
 * print_osabi - Prints the ELF OS/ABI (Operating System/ABI) name.
 * @e_ident: A pointer to the ELF identification bytes.
 */
void print_osabi(unsigned char e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident)
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident);
	}
}
/**
 * print_abi_version - Prints the ELF ABI
 * (Application Binary Interface) version.
 *
 * @e_ident: A pointer to the ELF identification bytes.
 */
void print_abi_version(unsigned char e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident);
}
/**
 * print_type - Prints the ELF type (e.g., executable, shared object, etc.).
 * @e_type: The ELF type value.
 */
void print_type(unsigned int e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}
/**
 * print_entry - Prints the ELF entry point address.
 * @e_entry: The ELF entry point address value.
 */
void print_entry(unsigned long int e_entry)
{
	printf("  Entry point address:               %#lx\n", e_entry);
}
