/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:00:55 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/26 16:01:48 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *prepare_sign(t_tag *tag, char *s)
{
	if (s[0] == '-')
	{
		tag->sign = '-';
		s++;
	}
	else if (tag->plus == ENABLED)
		tag->sign = '+';
	else if (tag->space == ENABLED)
		tag->sign = ' ';
	return (s);
}

char	*process_sign(t_tag *tag, char *box, int s_len)
{
	if (tag->sign == '\0')
		return (box);
	if ((tag->zero_fill == ENABLED && tag->prcs == DISABLED)
			|| tag->left_aligned == ENABLED)
		box[0] = tag->sign;
	else
		box[tag->width - s_len - 1] = tag->sign;
	return (box);
}
