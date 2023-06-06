#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks if file is an ELF file
 * @e_ident: pointer to array containing ELF magic numbers
 *
 * Description: if file is not ELF file exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int start;

	for (start = 0; start < 4; start++)
	{
		if (e_ident[start] != 127 && e_ident[start] != 'E' &&
				e_ident[start] != 'L' && e_ident[start] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}

	}
}

/**
 * print_magic - prints magic numbers of ELF header
 * @e_ident: pointer to array containing ELF magic numbers
 *
 * Desc: Magic numbers are seperated by spaces
 */
void print_magic(unsigned char *e_ident)
{
	int start;

	printf("  Magic:  ");

	for (start = 0; start < EI_NIDENT; start++)
	{
		printf("%02x", e_ident[start]);

		if (start == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints class of ELF header
 * @e_ident: pointer to array conatining ELF file
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:        ");

	switch (e_ident[EI_CLASS])
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints data of ELF file
 * @e_ident: pointer array containing ELF class
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:         ");

	switch (e_ident[EI_DATA])
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
			printf("<unknown: %x\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - prints version of ELF header
 * @e_ident: pointer to array containing ELF version
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:         %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_abi - prints the ABI version of ELF header
 * @e_ident: pointer to array containing ELF ABI version
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:            %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_osabi - prints the OS/ABI of ELF header
 * @e_ident: pointer to array containing ELF version
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                ");

	switch (e_ident[EI_OSABI])
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
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_type - prints type of ELF header
 * @e_type: ELF type
 * @e_ident: pointer to array containing ELF class
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:               ");

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
 * print_entry - prints entry point of ELF file
 * @e_entry: address of ELF entry point
 * @e_ident: pointer to array containing ELF class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:                   ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file
 * @elf: file descriptor of ELF file
 *
 * Description: exit 98 if file cannot be closed
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays info contained in ELF header at start of ELF file
 * @argc: number of arguments
 * @argv: array of pointers to arguments
 *
 * Return: on success 0
 *
 * Desc: exit code 98 if not an ELF file or function fails
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int g, s;

	g = open(argv[1], O_RDONLY);
	if (g == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(g);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	s = read(g, header, sizeof(Elf64_Ehdr));
	if (s == -1)
	{
		free(header);
		close_elf(g);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_abi(header->e_ident);
	print_osabi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(g);
	return (0);
}
