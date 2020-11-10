/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:50:48 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/07 13:18:13 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Copies 'len' bytes from string 'src' to 'dst'.
** - The two strings may overlap (i.e. src+5, src)
**   copy is always done in a non-destructive manner.
** - Returns original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *usrc;
	unsigned char *udst;
	unsigned char temp[len];

	if (dst == NULL && src == NULL)
		return (NULL);
	usrc = (unsigned char *)src;
	udst = (unsigned char *)dst;
	ft_memcpy(temp, usrc, len);
	ft_memcpy(udst, temp, len);
	return (dst);
}

/*
** line 28-29 : Added protection
*/
