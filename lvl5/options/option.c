#include <unistd.h>

void	print_bits(char **tab, int ac)
{
	char	res_bit[26];
	int		i = 0;
	int		j = 0;
	int		k = 0;
	char	str[] = "abcdefghijklmnopqrstuvwxyz";

	while (i < 26)
	{
		res_bit[i] = '0';
		i++;
	}
	i = 0;
	while (i < ac)
	{
		while (tab[i][j])
		{
			if (j == 0 && tab[i][j] != '-')
				break ;
			while (str[k])
			{
				if (tab[i][j] == str[k])
					res_bit[25 - k] = '1';
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	write (1, "000000", 6);
	while (str[i])
	{
		if (i == 2 || i == 10 || i == 18)
			write (1, " ", 1);
		write (1, &res_bit[i], 1);
		i++;
	}
}

int		check_char(char **tab, int ac)
{
	int		i = 0;
	int		j = 0;
	int		check = 0;

	while (i < ac)
	{
		while (tab[i][j])
		{
			if (j == 0 && tab[i][j] != '-')
				break ;
			if (j > 0 && (tab[i][j] < 'a' || tab[i][j] > 'z'))
				return (0);
			if (j > 0 && tab[i][j] == 'h')
				check++;
			j++;
		}
		j = 0;
		i++;
	}
	if (check > 0)
		return (2);
	return (1);
}

void	options(char **tab, int ac)
{
	int		i = 0;

	tab++;
	i = check_char(tab, ac);
	if (i == 0)
	{
		write (1, "Invalid Option", 14);
		return ;
	}
	if (i == 2)
	{
		write (1, "options: abcdefghijklmnopqrstuvwxyz", 35);
		return ;
	}
	print_bits(tab, ac);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		write (1, "options: abcdefghijklmnopqrstuvwxyz", 35);
	else
		 options(av, ac - 1);
	write (1, "\n", 1);
	return (0);
}
