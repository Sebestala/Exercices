#include <unistd.h>

void	ft_putascii(unsigned char c)
{
	if (c > 31 && c < 127)
		write (1, &c, 1);
	else
		write (1, ".", 1);
}

void	ft_puthex(unsigned char c)
{
	char	tab[16] = "0123456789abcdef";

	write(1, &tab[c / 16], 1);
	write(1, &tab[c % 16], 1);
}

void	print_line(unsigned char *str, size_t start, size_t max)
{
	size_t	i;

	i = start;
	while (i < start + 16 && i < max)
	{
		ft_puthex(str[i]);
		if (i % 2)
			write (1, " ", 1);
		i++;
	}
	while (i < start + 16)
	{
		write (1, "  ", 2);
		if (i % 2)
			write (1, " ", 1);
		i++;
	}
	i = start;
	while(i < start + 16 && i < max)
		ft_putascii(str[i++]);
	write (1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*str;
	size_t	start;

	str = (unsigned char *)addr;
	start = 0;
	while (start < size)
	{
		print_line(str, start, size);
		start += 16;
	}
}

int		main(void)
{
	int	tab[17] = {0, 23, 35560, 255, 12, 16,  42, 178903, 444687, 900445, 555467, 9999999, 6746516, 2646, 199999, 1};
	print_memory(tab, sizeof(tab));
	return (0);
}
