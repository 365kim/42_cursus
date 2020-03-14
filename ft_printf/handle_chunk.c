/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 23:20:17 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/14 23:20:29 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_set(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	if (s == 0)
		return (0);
	i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strstrhr(const char *s, char *set)
{
	int i;
	int j;

	if (s == 0)
		return (0);
	i = 0;
	if (set == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strndup(const char *s1, int size)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[size] = 0;
	return (dup);
}
