#include <unistd.h>

int		check_queen(char **tab, int king_i, int king_j, int ac)
{
	int		i = 1;

	while (king_i - i >= 0)
	{
		if (tab[king_i - i][king_j] == 'Q')
			return (1);
		if (tab[king_i - i][king_j] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_j - i >= 0)
	{
		if (tab[king_i][king_j - i] == 'Q')
			return (1);
		if (tab[king_i][king_j - i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (tab[king_i][king_j + i])
	{
		if (tab[king_i][king_j + i] == 'Q')
			return (1);
		if (tab[king_i][king_j + i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i + i < ac)
	{
		if (tab[king_i + i][king_j] == 'Q')
			return (1);
		if (tab[king_i + i][king_j] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i - i >= 0 && king_j - i >= 0)
	{
		if (tab[king_i - i][king_j - i] == 'Q')
			return (1);
		if (tab[king_i - i][king_j - i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i - i >= 0 && tab[king_i][king_j + i])
	{
		if (tab[king_i - i][king_j + i] == 'Q')
			return (1);
		if (tab[king_i - i][king_j + i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i + i < ac && king_j - i >= 0)
	{
		if (tab[king_i + i][king_j - i] == 'Q')
			return (1);
		if (tab[king_i + i][king_j - i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i + i < ac && tab[king_i + i][king_j + i])
	{
		if (tab[king_i + i][king_j + i] == 'Q')
			return (1);
		if (tab[king_i + i][king_j + i] != '.')
			break ;
		i++;
	}
	return (0);
}

int		check_rook(char **tab, int king_i, int king_j, int ac)
{
	int		i = 1;

	while (king_i - i >= 0)
	{
		if (tab[king_i - i][king_j] == 'R')
			return (1);
		if (tab[king_i - i][king_j] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_j - i >= 0)
	{
		if (tab[king_i][king_j - i] == 'R')
			return (1);
		if (tab[king_i][king_j - i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (tab[king_i][king_j + i])
	{
		if (tab[king_i][king_j + i] == 'R')
			return (1);
		if (tab[king_i][king_j + i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i + i < ac)
	{
		if (tab[king_i + i][king_j] == 'R')
			return (1);
		if (tab[king_i + i][king_j] != '.')
			break ;
		i++;
	}
	return (0);
}

int		check_bishop(char **tab, int king_i, int king_j, int ac)
{
	int		i = 1;

	while (king_i - i >= 0 && king_j - i >= 0)
	{
		if (tab[king_i - i][king_j - i] == 'B')
			return (1);
		if (tab[king_i - i][king_j - i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i - i >= 0 && tab[king_i][king_j + i])
	{
		if (tab[king_i - i][king_j + i] == 'B')
			return (1);
		if (tab[king_i - i][king_j + i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i + i < ac && king_j - i >= 0)
	{
		if (tab[king_i + i][king_j - i] == 'B')
			return (1);
		if (tab[king_i + i][king_j - i] != '.')
			break ;
		i++;
	}
	i = 1;
	while (king_i + i < ac && tab[king_i + i][king_j + i])
	{
		if (tab[king_i + i][king_j + i] == 'B')
			return (1);
		if (tab[king_i + i][king_j + i] != '.')
			break ;
		i++;
	}
	return (0);
}

int		check_pawn(char **tab, int king_i, int king_j, int ac)
{
	if (king_i + 1 < ac)
	{
		if (tab[king_i + 1][king_j - 1] == 'P' || tab[king_i + 1][king_j + 1] == 'P')
		return (1);
	}
	return (0);
}

int		mate(char **tab, int ac)
{
	int		i = 0;
	int		king_i = 0;
	int		j = 0;
	int		king_j = 0;

	while (i < ac)
	{
		while (tab[i][j])
		{
			if (tab[i][j] == 'K')
			{
				king_i = i;
				king_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (check_pawn(tab, king_i, king_j, ac))
		return (1);
	if (check_bishop(tab, king_i, king_j, ac))
		return (1);
	if (check_rook(tab, king_i, king_j, ac))
		return (1);
	if (check_queen(tab, king_i, king_j, ac))
		return (1);
	return (0);
}

char	**make_area(char **tab, int ac)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;

	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == 'K')
				k++;
			if (tab[i][j] != ' ' && tab[i][j] != 'K' && tab[i][j] != 'P' &&
					tab[i][j] != 'B' && tab[i][j] != 'Q' && tab[i][j] != '.' && tab[i][j] != 'R')
				tab[i][j] = '.';
			j++;
		}
		if (j != ac)
			return (NULL);
		j = 0;
		i++;
	}
	if (k != 1)
		return (NULL);
	return (tab);
}

void	check_mate(char **tab, int ac)
{
	tab++;
	tab = make_area(tab, ac);
	if (tab == NULL)
		return ;
	if (mate(tab, ac))
		write (1, "Success", 7);
	else
		write (1, "Fail", 4);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		check_mate(av, ac - 1);
	write (1, "\n", 1);
	return (0);
}
