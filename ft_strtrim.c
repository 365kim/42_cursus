/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 07:55:09 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/28 10:23:06 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Allocates (with malloc) a copy of 's1'
**   with the characters specified in 'set' removed from beginning and end of string.
** - Returns 's1', the trimmed string, or NULL if the allocation fails.
*/

int		is_set(char c, char *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	size_t	front;
	size_t	end;
	size_t	len;

	if (s1 == 0 || set == 0)
		return ((char *)s1);
	end = ft_strlen(s1);
	front = 0;
	while (front < end && is_set(s1[front], (char *)set))
		front++;
	while (0 < end && is_set(s1[end - 1], (char *)set))
		end--;
	len = end - front >= 0 ? end - front : 0;
	if (len == 0)
		return (0);
	s_trim = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(s_trim, s1 + front, len);
	s_trim[len] = 0;
	return (s_trim);
}
