#include "list.h"

int		list_remove(t_node **begin_list, int n)
{
	int i;
	t_node *tmp;

	if (n < 0)
		return (0);
	while (i < n && (*begin_list)->next)
	{
		*begin_list = (*begin_list)->next;
		i++;
	}
	if (i != n)
		return (0);
	else
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		tmp = 0;
		return (1);
	}
}
