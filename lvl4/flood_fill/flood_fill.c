#include "t_point.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_tab(char **tab)
{
	int		i = 0;
	int		j = 0;

	while (i <= 5)
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			if (tab[i][j + 1])
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**make_area(char **zone, t_point size)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	if (!(copy = (char **)malloc((size.y + 1) * sizeof(char *))))
		return (NULL);
	copy[size.y] = NULL;
	while (i <= size.y)
	{
		if (!(copy[i] = (char *)malloc((size.x + 1) * sizeof(char))))
			return (NULL);
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
		copy[i][j] = '\0';
		j = 0;
		i++;
	}
	return (copy);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int		check = 0;
	int		x;
	int		y;
	char	c;

	if (begin.x >= size.x || begin.x < 0 || begin.y >= size.y || begin.y < 0)
		return ;
	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	while (check <= 3)
	{
		y = 0;
		while (y < size.y)
		{
			x = 0;
			while (x < size.x)
			{
				if (tab[y][x] == c)
				{
					if (x - 1 >= 0 && tab[y][x - 1] == 'F')
					{
						tab[y][x] = 'F';
						check = 0;
					}
					if (x + 1 < size.x && tab[y][x + 1] == 'F')
					{
						tab[y][x] = 'F';
						check = 0;
					}
					if (y - 1 >= 0 && tab[y - 1][x] == 'F')
					{
						tab[y][x] = 'F';
						check = 0;
					}
					if (y + 1 < size.y && tab[y + 1][x] == 'F')
					{
						tab[y][x] = 'F';
						check = 0;
					}
				}
				x++;
			}
			y++;
		}
		check++;
	}
}

int		main(void)
{
	char **area;
	t_point size = { 8, 6 };
	t_point begin = { 2, 4 };
	char *zone[] = {
		"10111101",
		"01001000",
		"10010001",
		"1011P001",
		"01100010",
		"10000101",
	};
	area = make_area(zone, size);
	print_tab(area);
	flood_fill(area, size, begin);
	ft_putchar('\n');
	print_tab(area);
	return (0);
}
