/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:07:21 by mihykim           #+#    #+#             */
/*   Updated: 2020/10/31 14:42:23 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, size_t size)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		return (0);
	ft_strcpy(dup, s1, size);
	dup[size] = 0;
	return (dup);
}
