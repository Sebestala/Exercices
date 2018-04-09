#include "list.h"
#include <stdlib.h>

int		cycle_detector(const t_list *list)
{
	t_list	**tab;
	int			i = 0;
	int			j;

	if (!(tab = (t_list**)malloc(sizeof(t_list*) * 142)))
		return (1);
	while (list->next != NULL)
	{
		j = 0;
		while (j < i)
		{
			if (list->next == tab[j])
				return (1);
			j++;
		}
		tab[i++] = list->next;
		list = list->next;
	}
	return (0);
}
