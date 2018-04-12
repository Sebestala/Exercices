#include <unistd.h>

void	biggest_pal(char *str)
{
	int		i = 0;
	int		start = 0;
	int		len = 0;
	int		len_max = 0;

	while (str[i])
	{
		if (str[i + 1] && i > 0 && str[i + 1] == str[i - 1])
		{
			while (str[i + len] && i - len >= 0 && str[i + len] == str[i - len])
				len++;
			if (len > len_max)
			{
				len_max = len - 1;
				start = i;
			}
			len = 0;
		}
		i++;
	}
	len_max = len_max * 2 + 1;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i + 1] == str[i])
		{
			while (str[i + len] && i - len >= 0 && str[i + len + 1] == str[i - len])
				len++;
			if (len * 2 >= len_max)
			{
				len_max = len * 2;
				start = i;
			}
			len = 0;
		}
		i++;
	}
	len = 0;
	if (len_max > 1)
	{
		if (len_max % 2 > 0)
		{
			while (len < len_max)
			{
				write(1, &str[start - len_max / 2 + len], 1);
				len++;
			}
		}
		else
		{
			while (len < len_max)
			{
				write(1, &str[start - len_max / 2 + 1 + len], 1);
				len++;
			}
		}
	}
	else
		write(1, &str[i - 1], 1);
}

int		main(int ac, char **av)
{
	if (ac == 2 && av[1][0] != '\0')
		biggest_pal(av[1]);
	write(1, "\n", 1);
	return (0);
}
