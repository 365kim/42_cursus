/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 05:36:31 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/27 07:29:28 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Writes 'len' bytes of value 'c'(converted to an unsigned char) to string 'b'.
** - Returns its first argument.
** - SIZE_T : unsigned type of the result of "sizeof"
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while(i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}
