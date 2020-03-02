#include "list.h"

t_node	*list_get(t_node *begin_list, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (begin_list == 0)
			return (0);
		begin_list = begin_list->next;
	}
	return (begin_list->data);
}
