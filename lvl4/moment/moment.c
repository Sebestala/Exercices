#include <stdlib.h>

char	*str_join(char *str, char *str2)
{
	int		i = 0;
	int		j = 0;

	while (str[i])
		i++;
	while (str2[j])
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*itoa(unsigned int nbr)
{
	int				i = 1;
	unsigned int	j = nbr;
	char			*str;

	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	if (!(str = (char *)malloc(i)))
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i-- - 1] = j % 10 + 48;
		j /= 10;
	}
	return (str);
}

char	*moment(unsigned int duration)
{
	char	*str = NULL;
	char	*str2 = NULL;
	int		i = 0;

	if (duration / 60 >= 1)
	{
		i++;
		duration /= 60;
		if (duration / 60 >= 1)
		{
			i++;
			duration /= 60;
			if (duration / 24 >= 1)
			{
				i++;
				duration /= 24;
				if (duration / 30 >= 1)
				{
					i++;
					duration /= 30;
				}
			}
		}
	}
	str = itoa(duration);
	if (i == 0)
	{
		if (duration == 1)
			str2 = " second ago.";
		else
			str2 = " seconds ago.";
	}
	if (i == 1)
	{
		if (duration == 1)
			str2 = " minute ago.";
		else
			str2 = " minutes ago.";
	}
	if (i == 2)
	{
		if (duration == 1)
			str2 = " hour ago.";
		else
			str2 = " hours ago.";
	}
	if (i == 3)
	{
		if (duration == 1)
			str2 = " day ago.";
		else
			str2 = " days ago.";
	}
	if (i == 4)
	{
		if (duration == 1)
			str2 = " month ago.";
		else
			str2 = " months ago.";
	}
	str = str_join(str, str2);
	return (str);
}
