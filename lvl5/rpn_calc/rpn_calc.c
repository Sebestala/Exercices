#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*rev_str(char *str)
{
	int	i = 0;
	int	j = 0;
	char	*copy;

	while (str[i])
		i++;
	if (!(copy = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i--;
	while (i >= 0)
		copy[j++] = str[i--];
	copy[j] = '\0';
	return (copy);
}

void	it_rec(char *str, int res, int *i)
{
	if (res > 9)
		it_rec(str, res / 10, i);
	str[(*i)++] = res % 10 + 48;
}

char	*itoa(int res)
{
	char	*str;
	int		i = 0;

	if (!(str = (char *)malloc(36)))
		return (NULL);
	if (res < 0)
	{
		res = -res;
		str[i++] = '-';
	}
	it_rec(str, res, &i);
	str[i] = '\0';
	return (str);
}

char	*str_calc(char *str, int i, int op)
{
	char	*tmp;
	int		nb2;
	int		nb1;
	int		res;
	int		j;

	if (!(tmp = (char *)malloc(36)))
		return (NULL);
	i -= 2;
	j = 0;
	while (str[i] != ' ' && i >= 0)
		tmp[j++] = str[i--];
	i--;
	tmp[j] = '\0';
	tmp = rev_str(tmp);
	nb2 = atoi(tmp);
	j = 0;
	while (str[i] != ' ' && i >= 0)
		tmp[j++] = str[i--];
	tmp[j] = '\0';
	tmp = rev_str(tmp);
	nb1 = atoi(tmp);
	i++;
	if (str[op] == '+')
		res = nb1 + nb2;
	if (str[op] == '-')
		res = nb1 - nb2;
	if (str[op] == '/')
	{
		if (nb2 == 0)
		{
			printf("Error\n");
			return (NULL);
		}
		res = nb1 / nb2;
	}
	if (str[op] == '*')
		res = nb1 * nb2;
	if (str[op] == '%')
	{
		if (nb2 == 0)
		{
			printf("Error\n");
			return (NULL);
		}
		res = nb1 % nb2;
	}
	j = 0;
	tmp = itoa(res);
	while (tmp[j])
		str[i++] = tmp[j++];
	op++;
	while (str[op])
		str[i++] = str[op++];
	str[i] = '\0';
	return (str);
}

void	rpn_calc(char *str)
{
	int		i = 0;
	int		op = 0;

	while (str[i])
	{
		while (str[i])
			i++;
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
			break ;
		while (str[op] && !(str[op] == '+' || str[op] == '*' || str[op] == '/' || str[op] == '%'))
		{
			if (str[op] == '-' && (str[op + 1] == ' ' || str[op + 1] == '\0'))
				break ;
			op++;
		}
		str = str_calc(str, op, op);
		if (str == NULL)
			return ;
		i = 0;
		op = 0;
	}
	printf("%s\n", str);
}

int		is_valid(char *str)
{
	int		i = 0;
	int		op = 0;
	int		nb = 0;

	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && !(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'))
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			nb++;
		}
		if ((str[i + 1] == ' ' || str[i + 1] == '\0') && 
			(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'))
			op++;
		i++;
	}
	if (nb == op + 1 && nb > 0)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2 || is_valid(av[1]) == 0)
	{
		printf("Error\n");
		return (0);
	}
	rpn_calc(av[1]);
	return (0);
}
