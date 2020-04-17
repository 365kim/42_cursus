/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_itoa_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:37:55 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/17 23:25:49 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_itoa_width(long n)
{
	int		i;

	i = n < 1 ? 1 : 0;
	n = n < 0 ? -n : n;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*
** line 15 : change from 'int' to 'long' to pass test 640 with long numbers
*/
