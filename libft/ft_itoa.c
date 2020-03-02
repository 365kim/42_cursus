/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:17:47 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/29 23:40:36 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Allocates (with malloc) a string representing 'n'
** - Negative numbers must be handled.
** - Returns the string, or NULL if the allocation fails.
*/

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
