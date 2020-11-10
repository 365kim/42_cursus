/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:39:22 by mihykim           #+#    #+#             */
/*   Updated: 2020/10/29 15:01:58 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_longest_node_len(t_list *lst)
{
	int max;

	max = -1;
	while (lst)
	{
		if (max < ft_strlen((char *)lst->content))
			max = ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (max);
}
