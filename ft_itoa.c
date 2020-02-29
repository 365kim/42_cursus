/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:17:47 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/27 17:33:35 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Allocates (with malloc) a string representing 'n'
** - Negative numbers must be handled.
** - Returns the string, or NULL if the allocation fails.
*/

void	put_zero_or_minus(long n, char *res)
{
	if (n == 0)
		res[0] = 0;
	else if (n < 0)
		res[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*res;
	long	sign;
	long	long_n;
	long	i;

	i = n < 1 ? 1 : 0;
	sign = n < 0 ? -1 : 1;
	long_n = n < 0 ? (long)-n : (long)n;
	while (long_n != 0)
	{
		long_n = long_n / 10;
		i++;
	}
	res = (char *)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	long_n = n < 0 ? (long)-n : (long)n;
	while (i >= 0)
	{
		res[i - 1] = long_n % 10;
		long_n = long_n / 10;
		i--;
	}
	put_zero_or_minus(n, res);
	return (res);
}
