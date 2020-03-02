/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:50:48 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/27 18:43:06 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Copies 'len' bytes from string 'src' to 'dst'.
** - The two strings may overlap (i.e. src+5, src); 
**   copy is always done in a non-destructive manner.
** - Returns original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *_src;
	unsigned char *_dst;
	unsigned char temp[len];

	_src = (unsigned char *)src;
	_dst = (unsigned char *)dst;
	ft_memcpy(temp, _src, len);
	ft_memcpy(_dst, temp, len);
	return (dst);
}
