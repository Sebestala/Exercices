#include "list.h"
#include "stdlib.h"

int		cycle_detector(const t_list *list)
{
	long long	*tab;
	int			i = 0;
	int			j;
	long long	nb;

	if (!(tab = (long long *)malloc(sizeof(long long) * 142)))
		return (1);
	while (list->next != NULL)
	{
		j = 0;
		nb = (long long)&list->next;
		while (j < i)
		{
			if (nb == tab[j])
				return (1);
			j++;
		}
		tab[i++] = (long long)&list->next;
		list = list->next;
	}
	return (0);
}
