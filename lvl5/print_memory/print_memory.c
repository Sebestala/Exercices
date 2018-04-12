#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putascii(unsigned char c)
{
	if (c > 31 && c < 127)
		ft_putchar(c);
	else
		ft_putchar('.');
}

void	ft_puthex(unsigned char c)
{
	char	tab[16] = "0123456789abcdef";

	ft_putchar(tab[c / 16]);
	ft_putchar(tab[c % 16]);
}

void	print_line(unsigned char *str, size_t start, size_t max)
{
	size_t	i;

	i = start;
	while (i < start + 16 && i < max)
	{
		ft_puthex(str[i]);
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	while (i < start + 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	i = start;
	while(i < start + 16 && i < max)
	{
		ft_putascii(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*str;
	size_t	c;
	int		i = 0;

	str = (unsigned char *)addr;
	c = 0;
	while (str[i])
	{
		printf("||%c||", str[i]);
		i++;
	}
	while (c < size)
	{
		print_line(str, c, size);
		c += 16;
	}
}

int		main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}

