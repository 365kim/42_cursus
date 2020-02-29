/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 08:43:40 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/28 10:29:12 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Allocates (with malloc) an array of strings obtained by splitting 's' 
**   using the character 'c' as a delimiter. 
** - The array must be ended by a NULL pointer.
** - Returns the array of new strings, or NULL if the allocation fails.
*/

size_t	ft_strnum(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

void	ft_strcpy(char **res, char const *s, char c, size_t _s)
{
	size_t	len;
	size_t	i;
	char	*init;
	char	*end;

	i = 0;
	init = (char *)s;
	while(s[i])
	{
		end = (char *)ft_memchr(s, c, _s - i);
		if (end == 0)
			end = (char *)ft_memchr(s, '\0', _s - i);
		len = end - init;
		if (len && s[len - 1] != c)
		{
			res[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (res[i] == 0)
				return ;
			ft_memcpy(res[i], end, len);
			res[i][len] = 0;
		}
		i += len + 1;
	}
	res[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	_s;

	if (s == 0)
		return (0);
	res = (char **)malloc(sizeof(char *) * (ft_strnum(s, c) + 1));
	if (res == 0)
		return (0);
	_s = ft_strlen(s);
	ft_strcpy(res, s, c, _s);
	return (res);
}
