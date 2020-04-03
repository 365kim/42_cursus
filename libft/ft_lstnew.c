/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:57:25 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/03 21:58:25 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Allocates (with malloc) and returns a new element
** - The variable 'content' is initialized with the value of 'content'
** - The variable 'next' is initialized to Null
*/

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list *));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}
