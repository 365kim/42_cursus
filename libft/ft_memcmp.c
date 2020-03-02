/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:53:46 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/28 17:12:48 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Compares 's1' against 's2', both strings are assumed 'n' bytes long.
** - Returns 0 if the two strings are identical or if n is 0.
**   (because zero-length strings are also always identical)
**   Otherwise, returns difference between the first two differing bytes.
**   (treated as unsigned char values, i.e. '200' is greater than '').
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*_s1;
	unsigned char	*_s2;

	if (n == 0)
		return (0);
	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && _s1[i] && _s2[i])
	{
		if (_s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (_s1[i] - _s2[i]);
}

/*
** line 34 : change if condition from 'i < n'  to 'i < n - 1'
**           (n may include terminated-null.)
*/
