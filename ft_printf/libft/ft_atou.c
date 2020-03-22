/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 14:01:56 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/22 17:17:05 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_atou(wchar_t w)
{
	int		n;
	int		i;
	char	*utf;
	int		utf_frame;

	utf = malloc((n = get_atou_width(w)) + 1);
	printf("n:%d", n);
	utf[n] = '\0';
	n == 1 ? utf[0] = w : 0;
	if (n == 1)
		return (utf);
	i = 0;
	utf_frame = 0b10000000;
	while (i + 1 <= n)
	{
		utf[n - 1 - i] = ((w >> (6 * i)) & 0b00111111) | utf_frame;
		i++;
	}
	while (n-- > 1)
	{
		utf_frame = utf_frame >> 1 | 0b10000000;
		utf[0] = utf[0] | utf_frame;
	}
	return (utf);
}
