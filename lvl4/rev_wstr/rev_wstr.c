#include <unistd.h>

void	rev_wstr(char *str)
{
	int		i = 0;
	int		start = 0;
	int		end = 0;

	while (str[i++])
	end = i;
	while (i > 0)
	{
		while (i >= 0 && str[i] != ' ' && str[i] != '	')
			i--;
		start = i;
		i++;
		while (i < end)
			write(1, &str[i++], 1);
		if (start > 0)
			write(1, " ", 1);
		end = start;
		i = start - 1;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write (1, "\n", 1);
	return (0);
}
