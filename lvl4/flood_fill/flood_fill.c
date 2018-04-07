#include "t_point.h"
#include "libft/libft.h"
#include <stdio.h>
int		pri(int i, int j)
{
	printf(" i = %d    j = %d\n", i, j);
	fflush(stdout);
	return (i);
}

char	**make_area(char **zone, t_point size)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	if ((copy = (char **)malloc((size.y) * sizeof(char*))) == NULL)
		return (NULL);
	copy[size.y] = NULL;
	while (zone[i])
	{
		while (zone[i][j])
			j++;
		copy[i] = ft_memalloc(j + 1);
		j = 0;
		i++;
	}
	i = 0;
	while (i < size.y)
	{
		while (zone[i][j])
		{
			copy[i][j] = zone[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (copy);
}

char	**check(char **tab, char c, t_point size)
{
	int check;
	int i;
	int j;

	check = 0;
	i = 0;
	j = 0;
	while (check < 3)
	{
		while (tab[i])
		{
			while (tab[i][j])
			{
				if (tab[i][j] == c)
				{
					if (i - 1 >= 0 && tab [i - 1][j] == 'F')
					{
						tab[i][j] = 'F';
						check = 0;
					}
					if (i + 1 < size.y && tab [i + 1][j] == 'F')
					{
						tab[i][j] = 'F';
						check = 0;
					}
					if (j - 2 >= 0 && tab [i][j - 2] == 'F')
					{
						tab[i][j] = 'F';
						check = 0;
					}
					if (j + 2 <= size.x * 2 - 1 && tab [i][j + 2] == 'F')
					{
						tab[i][j] = 'F';
						check = 0;
					}
				print_tab(tab);
				ft_putstr("\n\n");
				}
				j++;
			}
			j = 0;
			i++;
		}
		check++;
		i = 0;
	}
	return (tab);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char c;

	size.x = size.x;
	c = tab[begin.x][begin.y];
	tab[begin.x][begin.y] = 'F';
	tab = check(tab, c, size);
}

int		main(void)
{
	char **area;
	t_point size = { 8, 6 };
	t_point begin = { 10, 2 };
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 P P 0 1",
		"1 0 1 0 0 0 0 1",
		"1 0 0 0 0 0 0 1",
	};
	area = make_area(zone, size);
	ft_putchar('A');
	print_tab(area);
	ft_putchar('B');
	flood_fill(area, size, begin);
	ft_putchar('\n');
	print_tab(area);
	return (0);
}
