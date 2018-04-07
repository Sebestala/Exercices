#include <stdio.h>
#include <stdlib.h>

void	itoa_base(long value, int base, char *str, int *i)
{
	char	base_str [] = "0123456789ABCDEF";

	if (value >= base)
		itoa_base(value / base, base, str, i);
	str[(*i)++] = base_str[value % base];
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	long	val;
	char	*str;

	val = (long)value;
	i = 0;
	if (base < 2 || base > 16 || !(str = (char *)malloc(36)))
		return (NULL);
	if (base == 10 && val < 0)
	{
		str[i++] = '-';
		val = -val;
	}
	itoa_base(val, base, str, &i);
	str[i] = '\0';
	return (str);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("%s", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
