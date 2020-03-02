#ifndef LIST_H
# define LIST_H

#include <stdlib.h>

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node

t_node	*create_elem(int data);
int		list_add1(t_node **begin_list, int data);
int		list_size(t_node *begin_list);
t_node	*list_get(t_node *begin_list, int n);
int		list_remove(t_node **begin_list, int n);
int		list_add(t_node **begin_list, int data, int n);

#endif
