/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:15:28 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 00:28:40 by mihykim          ###   ########.fr       */
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

void	put_zero_or_minus(int n, char *res)
{
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
		res[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*res;
	long	long_n;
	long	i;

	i = n < 1 ? 1 : 0;
	long_n = n < 0 ? -(long)n : (long)n;
	while (long_n != 0)
	{
		long_n = long_n / 10;
		i++;
	}
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == 0)
		return (0);
	res[i] = '\0';
	long_n = n < 0 ? -(long)n : (long)n;
	while (i >= 0)
	{
		res[i - 1] = long_n % 10 + '0';
		long_n = long_n / 10;
		i--;
	}
	put_zero_or_minus(n, res);
	return (res);
}
/*
** line 24 : change value of res[0] from 0 to '0'
** line 49 : add + '0' to convert from int to char
*/
