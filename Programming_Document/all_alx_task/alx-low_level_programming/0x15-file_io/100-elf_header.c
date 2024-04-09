#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

void print_elf_header(const Elf64_Ehdr *header)
{
	int i;
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             %s\n", (header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", (header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Unknown");
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", (header->e_type == ET_EXEC) ? "EXEC (Executable file)" : "Unknown");
	printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;
	ssize_t bytes_read;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return 98;
	}

	bytes_read = read(fd, &header, sizeof(header));

	if (bytes_read != sizeof(header))
	{
		fprintf(stderr, "Error reading ELF header\n");
		close(fd);
		return 98;
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: %s is not an ELF file\n", argv[1]);
		close(fd);
		return 98;	
	}

	print_elf_header(&header);

	close(fd);
	return 0;
}

