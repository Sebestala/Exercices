#include <unistd.h>
#include <stdio.h>

/*
void	print_memory(const void *addr, size_t size)
{



}
*/

int		main()
{
	printf("char = %lu\n", sizeof(char));
	printf("char * = %lu\n", sizeof(char *));
	printf("char ** = %lu\n", sizeof(char **));
	printf("int = %lu\n", sizeof(int));
	printf("int * = %lu\n", sizeof(int *));
	printf("int ** = %lu\n", sizeof(int **));
	printf("size_t = %lu\n", sizeof(size_t));
	printf("size_t * = %lu\n", sizeof(size_t *));
	printf("long = %lu\n", sizeof(long));
	printf("long * = %lu\n", sizeof(long *));
	printf("long long = %lu\n", sizeof(long long));
	printf("long long * = %lu\n", sizeof(long long *));

	printf("unsigned char = %lu\n", sizeof(unsigned char));
	printf("unsigned char * = %lu\n", sizeof(unsigned char *));
	printf("unsigned char ** = %lu\n", sizeof(unsigned char **));
	printf("unsigned int = %lu\n", sizeof(unsigned int));
	printf("unsigned int * = %lu\n", sizeof(unsigned int *));
	printf("unsigned int ** = %lu\n", sizeof(unsigned int **));
	printf("unsigned long = %lu\n", sizeof(unsigned long));
	printf("unsigned long * = %lu\n", sizeof(unsigned long *));
	printf("unsigned long long = %lu\n", sizeof(unsigned long long));
	printf("unsigned long long * = %lu\n", sizeof(unsigned long long *));
	return (0);
}
