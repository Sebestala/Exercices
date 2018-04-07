#include <stdlib.h>
#include <stdio.h>

void	itoa(long val, char *str, int *i)
{
	if (val >= 10)
		itoa(val/10, str, i);
	str[(*i)++] = val % 10 + 48;
}

char	*ft_itoa(int nbr)
{
	int		i;
	long	val;
	char	*str;

	val = (long)nbr;
	i = 0;
	if (!(str = (char *)malloc(36)))
		return (NULL);
	if (val < 0)
	{
		str[i++] = '-';
		val = -val;
	}
	itoa(val, str, &i);
	str[i] = '\0';
	return (str);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%s\n", ft_itoa(atoi(av[1])));
	return (0);
}
