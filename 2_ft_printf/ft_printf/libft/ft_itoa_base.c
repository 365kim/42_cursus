/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 23:15:07 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 22:00:08 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int n, const char *base)
{
	unsigned int	div;
	unsigned int	len;
	unsigned int	base_len;
	char			*res;

	div = n;
	len = (n == 0) ? 1 : 0;
	base_len = (unsigned int)ft_strlen((char *)base);
	while (div != 0)
	{
		div = div / base_len;
		len++;
	}
	if (!(res = calloc((len + 1), sizeof(char))))
		return (NULL);
	res[0] = '0';
	while (n != 0)
	{
		len--;
		res[len] = base[(n % base_len)];
		n = n / base_len;
	}
	return (res);
}
