/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:06:58 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/07 00:33:22 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t i;

	if (dst == 0 && src == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s1)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s1);
	dup = malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		return (0);
	ft_memcpy(dup, s1, size);
	dup[size] = 0;
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	len1;
	size_t	len2;

	if (s1 == 0 && s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_s == 0)
		return (0);
	ft_memcpy(new_s, s1, len1);
	ft_memcpy(new_s + len1, s2, len2);
	new_s[len1 + len2] = 0;
	return (new_s);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size_s;
	char	*sub_s;

	if (s == 0)
		return (0);
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_s == 0)
		return (0);
	size_s = ft_strlen(s);
	i = 0;
	while (i < len && i + start < size_s)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = 0;
	return (sub_s);
}
