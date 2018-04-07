#include <unistd.h>
#include <stdlib.h>

void	brainfuck(char *str)
{
	int		i;
	int		check;
	char	*ptr;

	i = 0;
	if (!(ptr = (char*)malloc(2048)))
		return ;
	while (str[i])
	{
		if (str[i] == '+')
			*ptr += 1;
		if (str[i] == '-')
			*ptr -= 1;
		if (str[i] == '>')
			ptr++;
		if (str[i] == '<')
			ptr--;
		check = 1;
		if (str[i] == '[' && *ptr == 0)
		{
			while (str[i] != ']' || check > 0)
			{
				i++;
				if (str[i] == '[')
					check++;
				if (str[i] == ']')
					check--;
			}
		}
		check = 1;
		if (str[i] == ']' && *ptr != 0)
		{
			while (str[i] != '[' || check > 0)
			{
				i--;
				if (str[i] == '[')
					check--;
				if (str[i] == ']')
					check++;
			}
		}
		if (str[i] == '.')
			write(1, ptr, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0])
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
