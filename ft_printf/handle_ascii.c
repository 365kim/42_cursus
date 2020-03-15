/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:15:28 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 23:44:41 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char **str)
{
	int		atoi;

	atoi = 0;
	if (!is_set(**str, DIGIT))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		atoi = atoi * 10 + (**str - '0');
		(*str)++;
	}
	return (atoi);
}

int		get_itoa_width(int n)
{
	long	long_n;
	long	i;

	i = n < 1 ? 1 : 0;
	long_n = n < 0 ? -(long)n : (long)n;
	while (long_n != 0)
	{
		long_n = long_n / 10;
		i++;
	}
	return ((int)i);
}
