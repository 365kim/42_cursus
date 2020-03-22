/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_assist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:58:34 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/22 16:43:16 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_num_printed(t_printf *hub)
{
	int *medium;

	medium = va_arg(hub->ap, int *);
	*medium = hub->printed;
}

void	apply_len_modifier(t_printf *hub, t_tag tag)
{
	if (tag.len_mod == HH)
		hub->argi = (char)va_arg(hub->ap, int);
	else if (tag.len_mod == H)
		hub->argi = (short)va_arg(hub->ap, int);
	else if (tag.len_mod == LL)
		hub->argi = (long)va_arg(hub->ap, long);
	else if (tag.len_mod == L)
		hub->argi = (long long)va_arg(hub->ap, long long);
	else if (tag.len_mod == FALSE)
		hub->argi = va_arg(hub->ap, int);
}

void	pre_fill_width(t_printf *hub, t_tag tag)
{
	if (tag.sign == '-' || tag.plus || tag.space)
		tag.width_parsed--;
	if ((tag.sign == '-' || tag.plus) && ((tag.left || tag.zero) && !tag.prcs))
		hub->printed += ft_putchar(tag.sign);
	else if ((tag.sign == '+' && tag.space) && !tag.plus)
		hub->printed += ft_putchar(' ');
	if (!tag.left)
	{
		tag.zero ? (tag.filler ='0') : (tag.filler = ' ');
		tag.prcs ? (tag.filler = ' ') : SKIP;
		if (tag.prcs && !tag.prcs_fill && tag.conversion != 's')
			tag.width_arg = MAX(tag.width_arg, tag.prcs_parsed);
		tag.width_fill =
			MAX(0, tag.width_parsed - tag.width_arg - tag.prcs_fill);
		hub->printed += ft_putchar_n(tag.filler, tag.width_fill);
	}
	if ((tag.sign == '-' || tag.plus) && !((tag.left || tag.zero) && !tag.prcs))
		hub->printed += ft_putchar(tag.sign);
	if (is_set(tag.conversion, NUM_GROUP))
			hub->printed += ft_putchar_n('0', tag.prcs_fill);
}

void	post_fill_width(t_printf *hub, t_tag tag)
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
		hub->printed += ft_putchar_n(tag.filler, tag.width_fill);
	}
}
