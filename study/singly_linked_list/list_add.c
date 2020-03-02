#include "list.h"

int	list_add(t_node **begin_list, int data, int n)
{
	int		i;
	t_node	*new;
	t_node	*tmp;

	if (begin_list == 0 || n < 0)
		return (-1);
	i = 0;
	while (i < n && *begin_list->next)
	{
		*begin_list = (*begin_list)->next;
		i++;
	}
	if (i < n)
	{
		(*begin_list)->next = new;
		new->next = 0;
	}
	else
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = new;
		new->next = tmp;
	}
	return (i);
}
