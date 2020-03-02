#include "list.h"

int		list_add1(t_node **begin_list, int data)
{
	int		i;
	t_node	*current;

	if (begin_list == 0)
		return (-1);
	current = *begin_list;
	i = 0;
	if (current == 0)
		current = create_elem(data);
	else
	{
		while (current->next)
		{
			current = current->next;
			i++;
		}
		current->next = create_elem(data);
		if (current->next == 0)
			return (-1);
		current = current->next;
	}
	current->next = 0;
	return (i + 1);
}
