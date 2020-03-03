/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:06:58 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/03 08:50:16 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_slen(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	has_NL_or_EOF(char *s, int	*check)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '')
		{
			check[0] = i;
			check[1] = (s[i] == '\n') ? NL : EoF;
		}
		i++;
	}
	check[1] = -1;
}
