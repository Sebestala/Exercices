#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	multi_putchar(int *chess)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ft_putchar('0' + chess[i]);
		i++;
	}
	ft_putchar('\n');
}

void	recu(int *chess, int pos, int co, int i, int test)
{
	if (chess[7] == 1 && chess[6] == 2 && chess[5] == 3 && 
			chess[4] == 4 && chess[3] == 5 && chess[2] == 6 && chess[1] == 7 
			&& chess[0] == 8 && pos == 9)
		return;
	if (co == 8)
	{
		test++;
		multi_putchar(chess);
		pos = chess[co - 1] + 1;
		printf("T=%d ", test);
		recu(chess, pos, co - 1, 0, test);
		return;
	}
	if (pos == 9)
	{
		pos = chess[co - 1] + 1;
		recu(chess, pos, co - 1, 0, test);
		return;
	}
	while (i < co)
	{
		if (pos == chess[i] || pos == chess[i] + (co - i) 
				|| pos == chess[i] - (co - i))
		{
			recu(chess, pos + 1, co, 0, test);
			return;
		}
		i++;
	}
	if (i > 0 || (i == 0 && co == 0))
	{
		chess[co] = pos;
		recu(chess, 1, co + 1, 0, test);
		return;
	}
}



void	ft_eight_queens_puzzle_2(void)
{
	int		pos;
	int		co;
	int		i;
	int		chess[8];
	int test;

	test = 0;
	pos = 1;
	co = 0;
	i = 0;
	chess[0] = 0;
	recu(chess, pos, co, i, test);
}

int		main()
{
	ft_eight_queens_puzzle_2();
	return (0);
}
