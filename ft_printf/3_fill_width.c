/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:58:34 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/19 20:05:05 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pre_fill_width(t_printf *data, t_tag tag)
{
	if (tag.sign == '-' || tag.plus || tag.space)
		tag.width_parsed--;
	if ((tag.sign == '-' || tag.plus) && ((tag.left || tag.zero) && !tag.prcs))
		data->printed += ft_putchar(tag.sign);
	else if ((tag.sign == '+' && tag.space) && !tag.plus)
		data->printed += ft_putchar(' ');
	if (!tag.left)
	{
		tag.zero ? (tag.filler ='0') : (tag.filler = ' ');
		tag.prcs ? (tag.filler = ' ') : SKIP;
		if (tag.prcs && !tag.prcs_fill && tag.conversion != 's')
			tag.width_arg = MAX(tag.width_arg, tag.prcs_parsed);
		tag.width_fill =
			MAX(0, tag.width_parsed - tag.width_arg - tag.prcs_fill);
		data->printed += ft_putchar_n(tag.filler, tag.width_fill);
	}
	if ((tag.sign == '-' || tag.plus) && !((tag.left || tag.zero) && !tag.prcs))
		data->printed += ft_putchar(tag.sign);
	if (is_set(tag.conversion, NUM_GROUP))
			data->printed += ft_putchar_n('0', tag.prcs_fill);
}

void	post_fill_width(t_printf *data, t_tag tag)
{
	if (tag.sign == '-' || tag.plus || tag.space)
		tag.width_parsed--;
	if (tag.left)
	{
		tag.zero ? (tag.filler ='0') : (tag.filler = ' ');
		tag.prcs ? (tag.filler = ' ') : SKIP;
		if (tag.prcs && !tag.prcs_fill && tag.conversion != 's')
			tag.width_arg = MAX(tag.width_arg, tag.prcs_parsed);
		tag.width_fill =
			MAX(0, tag.width_parsed - tag.width_arg - tag.prcs_fill);
		data->printed += ft_putchar_n(tag.filler, tag.width_fill);
	}
}
