/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:57:26 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/27 07:25:25 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Appends 'src' to end of 'dst' at most 'dstsize - strlen(dst) - 1' characters.
** - Then NUL-terminates,
**   unless dstsize is 0 or original 'dst' string was longer than dstsize
**   (room for the NUL should be included in dstsize)
**   If return value is >= dstsize, output string has been truncated.
** - Returns the total length of the string they tried to create.
**   : initial length of dst + length of src.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d;
	size_t s;
	size_t i;
	size_t _d;

	_d = 0;
	while (_d < dstsize && dst[_d])
		_d++;
	s = ft_strlen(src);
	d = ft_strlen(dst);
	i = 0;
	while (i < s && d + i + 1 < dstsize)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = 0;
	return (_d + s);
}
