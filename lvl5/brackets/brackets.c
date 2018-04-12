#include <unistd.h>

char	convert_char(char c)
{
	if (c == ']')
		c = '[';
	if (c == '}')
		c = '{';
	if (c == ')')
		c = '(';
	return (c);
}

int		check(char *str)
{
	int		i = 0;
	int		j = 0;

	while (str[i])
	{
		if (str[i] == convert_char(str[i + 1]) && str[i] != str[i + 1])
		{
			while (str[i + 2])
			{
				str[i] = str[i + 2];
				i++;
			}
			str[i] = '\0';
			i = 0;
		}
		i++;
	}
	i = 0;
	while (str[j])
		j++;
	if (j == 0 || (str[i] == convert_char(str[i + 1]) && j == 2))
		return (1);
	return (0);
}

char	*clean_str(char *str, int i)
{
	char	copy[i + 1];
	int		j = 0;

	i = 0;
	while (str[i])
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(' || str[i] == ']' || str[i] == '}' || str[i] == ')')
			copy[j++] = str[i];
		i++;
	}
	copy[j] = '\0';
	i = 0;
	while (copy[++i])
		str[i] = copy[i];
	str[i] = '\0';
	return (str);
}

int		brackets(char *str)
{
	int		i = 0;
	int		open = 0;
	int		close = 0;

	while (str[i])
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(')
			open++;
		if (str[i] == ']' || str[i] == '}' || str[i] == ')')
			close++;
		i++;
	}
	if (close == 0 && open == 0)
		return (1);
	if (close != open)
		return (0);
	str = clean_str(str, i);
	return (check(str));
}

int		main(int ac, char **av)
{
	int		i = 1;

	if (ac > 1)
	{
		while (av[i])
		{
			if (brackets(av[i]))
				write(1, "OK", 2);
			else
				write(1, "Error", 5);
			i++;
			write (1, "\n", 1);
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}
