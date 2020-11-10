/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:11:06 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/07 13:20:04 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Allocates sufficient memory for a copy of the string
** - Does the copy
** - Returns a pointer to it
**   If insufficient memory is available, NULL is returned
*/

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s1);
	dup = ft_calloc(size + 1, 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, size);
	dup[size] = 0;
	return (dup);
}

/*
** line 29-30 : Added protection
*/
