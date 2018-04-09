#include <unistd.h>

void	rev_wstr(char *str)
{
	int		i = 0;
	int		start = 0;
	int		end = 0;

	while (str[i])
		i++;
	end = i;
	while (i > 0)
	{
		while (i >= 0 && str[i] != ' ' && str[i] != '	')
			i--;
		if (str[i + 1] != ' ' && str[i + 1] != '	')
		{
			start = i;
			i++;
			while (i < end)
			{
				write(1, &str[i], 1);
				i++;
			}
			i = start;
			if (i > 0)
				write(1, " ", 1);
		}
		if (str[i] == ' ' || str[i] == '	')
			end = i;
		i--;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write (1, "\n", 1);
	return (0);
}
