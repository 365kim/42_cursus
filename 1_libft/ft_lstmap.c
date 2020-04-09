/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:46:15 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/09 13:13:05 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Iterates the list 'lst' and applies function 'f' to the content of
**   each element.
** - 'del' function is used to delete the content of an element if needed.
** - Returns the new list, or NULL if the allocation fails
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_head;
	t_list *tmp;
	t_list *curr;

	if (lst == NULL || (new_head = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	curr = new_head;
	tmp = lst->next;
	while (tmp)
	{
		if ((curr->next = ft_lstnew(f(tmp->content))) == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		curr = curr->next;
		tmp = tmp->next;
	}
	return (new_head);
}

/*
** line 38 : Changed statement from 'break' to 'return NULL'
** line 29 : Removed 'f == NULL || del == NULL' from if condition
*/
