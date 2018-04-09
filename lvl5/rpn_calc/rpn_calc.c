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
	if (!(copy = (char *)malloc(i + 1)))
		return (NULL);
	i--;
	while (i >= 0)
		copy[j++] = str[i--];
	copy[j] = '\0';
	free(str);
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
	while (str[i] >= '0' && str[i] <= '9')
		tmp[j++] = str[i--];
	i--;
	tmp[j] = '\0';
	tmp = rev_str(tmp);
	nb2 = atoi(tmp);
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
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
		res = nb1 / nb2;
	if (str[op] == '*')
		res = nb1 * nb2;
	if (str[op] == '%')
		res = nb1 % nb2;
	j = 0;
	free(tmp);
	tmp = itoa(res);
	while (tmp[j])
		str[i++] = tmp[j++];
	op++;
	while (str[op])
		str[i++] = str[op++];
	str[i] = '\0';
	free(tmp);
	return (str);
}

void	rpn_calc(char *str)
{
	int		i = 0;
	int		op;
	char	*copy;

	while (str[i])
	{
		while (str[i] && !(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'))
			i++;
		op = i;
		if (str[i])
		{
			copy = str_calc(str, i, op);
			i = 0;
		}
	}
	printf("%s\n", copy);
}

int		is_valid(char *str)
{
	int		i = 0;
	int		j = 0;
	int		op = 0;
	int		nb = 0;
	char	*tmp;

	if (!(tmp = (char *)malloc(36)))
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				tmp[j++] = str[i++];
			tmp[j] = '\0';
			j = atoi(tmp);
			if (j == 0)
			{
				free(tmp);
				return (0);
			}
			j = 0;
			nb++;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
			op++;
		i++;
	}
	free(tmp);
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
