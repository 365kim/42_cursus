/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:10:28 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/28 17:23:06 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Copies bytes from string 'src' to string 'dst'.
** - Stops copying when 'c' converted to an unsigned char occurs in 'src'
** - Returns a pointer to the byte after the copy of c in 'dst',
**   otherwise, returns a NULL pointer after n bytes are copied
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	int				occured;
	unsigned char	*_src;

	_src = (unsigned char *)src;
	i = 0;
	occured = 0;
	while (i < n && _src[i] && !occured)
	{
		occured = ((_src)[i] == (unsigned char)c) ? 1 : 0;
		i++;
	}
	if (occured)
	{
		ft_memcpy(dst, _src, i);
		return (dst + i);
	}
	else 
	{
		ft_memcpy(dst, _src, n);
		return (0);
	}
}

/*
** line 31 : add while condition 'i < n', preventioning from over searching.
*/
