/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 08:43:40 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/03 22:11:16 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Allocates (with malloc) an array of strings obtained by splitting 's'
**   using the character 'c' as a delimiter.
** - The array must be ended by a NULL pointer.
** - Returns the array of new strings, or NULL if the allocation fails.
*/

size_t	ft_strnum(char *s, char c)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			num++;
		}
		else
			i++;
	}
	return (num);
}

void	str_malloc_copy(char *s, char c, size_t num, char **res)
{
	size_t	x;
	size_t	i;
	size_t	len;

	i = 0;
	x = 0;
	while (s[i] && x < num)
	{
		len = 0;
		if (s[i] != c)
		{
			while (s[i + len] != c && s[i + len])
				len++;
			res[x] = ft_calloc(sizeof(char), len + 1);
			if (res[x] == 0)
				return ;
			ft_strlcpy(res[x], s + i, len + 1);
			x++;
		}
		i += 1 + len;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	num;
	char	**res;

	if (s == 0)
		return (0);
	num = ft_strnum((char *)s, c);
	res = ft_calloc(sizeof(char *), num + 1);
	if (res == 0)
		return (0);
	res[num] = 0;
	str_malloc_copy((char *)s, c, num, res);
	return (res);
}
