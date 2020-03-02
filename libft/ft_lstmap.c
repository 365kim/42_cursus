/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:46:15 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/02 01:13:32 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Iterates the list 'lst' and applies function 'f' to the content of each element.
** - 'del' function is used to delete the content of an element if needed.
** - Returns the new list, or NULL if the allocation fails
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_head;
	t_list *current;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	new_head = ft_lstnew(f(lst->content));
	if (new_head == 0)
		return (0);
	current = new_head;
	lst = lst->next;
	while (lst)
	{
		if ((current->next = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&new_head, del);
			break ;
		}
		current = current->next;
		lst = lst->next;
	}
	return (new_head);
}
