/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:46:09 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/03 21:55:50 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Locates first occurrence of 'c'(converted to unsigned char) in 's'.
** - Returns a pointer to the byte located, or NULL if no such byte exists
**   within 'n'.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*my_s;

	my_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (my_s[i] == (unsigned char)c)
			return (my_s + i);
		i++;
	}
	return (0);
}

/*
** line 23 : declare my_s, because adding add value i to void * is impossible
** line 29 : explicitly cast c into unsigned char
*/
