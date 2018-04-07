#include <unistd.h>

void	rostring(char *str)
{
	int		i = 0;
	int		start = 0;
	int		end = 0;

	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	start = i;
	while (str[i] && (str[i] != ' ' && str[i] != '	'))
		i++;
	end = i;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '	'))
			i++;
		if (str[i] && (str[i] != ' ' && str[i] != '	'))
		{
			while (str[i] && (str[i] != ' ' && str[i] != '	'))
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1);
		}
	}
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}


int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
