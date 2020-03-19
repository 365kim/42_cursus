/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:03:22 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/19 20:45:28 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** ("%s", NULL)                     :	"(null)"
** ("%7.5s", NULL)                  :	"  (null"
** (%3.7s%7.7s, "hello", "world")   :	"hello  world"
*/

void	write_string(t_printf *data, t_tag tag)
{
	char *str;
	char *tmp;

	str = va_arg(data->ap, char *);
	if (str == NULL)
	{
		tmp = ft_strndup("(null)", 6);
		str = tmp;
		free(tmp);
	}
	tag.width_arg = ft_strlen(str);
	if (tag.prcs && tag.prcs_parsed < tag.width_arg)
	{
		tmp = ft_strndup(str, tag.prcs_parsed);
		data->args = tmp;
		free(tmp);
		tag.width_arg = tag.prcs_parsed;
	}
	else
		data->args = str;
	pre_fill_width(data, tag);
	data->printed += ft_putstr(data->args);
	post_fill_width(data, tag);
}

/*
** ("%-5%")     :	"%    "
** ("% 05%")    :	"0000%"
** ("%-05%")    :	"    %"
*/

void	write_char(t_printf *data, t_tag tag)
{
	tag.width_arg = 1;
	tag.left ? tag.zero = FALSE : SKIP;
	tag.space = FALSE;
	pre_fill_width(data, tag);
	if (tag.conversion == 'c')
		data->printed += ft_putchar((char)va_arg(data->ap, int));
	else
		data->printed += ft_putchar('%');
	post_fill_width(data, tag);
}

/*
** ("%5p", 0)    :	"  0x0"
*/

void	write_pointer(t_printf *data, t_tag tag)
{
	data->argi = va_arg(data->ap, unsigned long);
	tag.width_arg = data->argi == 0 ? 3 : 11;
	pre_fill_width(data, tag);
	data->printed += ft_putstr("0x");
	ft_putnbr_base(data->argi, HEX_LOW);
	post_fill_width(data, tag);
	data->printed += tag.width_arg - 2;
}

/*
** ("%x", 0)        :	"0"
** ("%.x", 0)       :	""
** ("%#.05", 0)     :	"00000"
** ("%#5.0x", 0)    :	"     "
** ("%#05x", 0)     :	"00000"
*/

void	write_hexa(t_printf *data, t_tag tag)
{
	data->argi = va_arg(data->ap, int);
	tag.width_arg = get_itoa_base_width(data->argi, 16);
	if (tag.prcs)
		tag.prcs_fill = MAX(0, tag.prcs_parsed - tag.width_arg);
	if (data->argi == 0 && tag.prcs)
	{
		tag.width_arg = 0;
		tag.prcs_fill = tag.prcs_parsed;
		pre_fill_width(data, tag);
		post_fill_width(data, tag);
	}
	else
	{
		tag.width_arg += tag.hexa;
		tag.hexa && (tag.zero && !tag.prcs) ? ft_putstr("0x") : SKIP;
		pre_fill_width(data, tag);
		tag.hexa && !(tag.zero && !tag.prcs) ? ft_putstr("0x") : SKIP;
		tag.width_arg && tag.conversion == 'x' ?
			ft_putnbr_base(data->argi, HEX_LOW) :
			ft_putnbr_base(data->argi, HEX_UP);
		post_fill_width(data, tag);
		data->printed += tag.width_arg;
	}
}

/*
** ("%04.2d", 0)    :	"  01""
** ("%.0d", 0)      :	""
** ("%+.d", 0)      :	"+"
** ("%+5.d", 0)     :	"    +"
** ("% +5d", 0)     :	"   +0"
** ("%+05d", -7)    :	"-0007"
*/

void	write_number(t_printf *data, t_tag tag)
{
	data->argi = va_arg(data->ap, int);
	tag.width_arg = get_itoa_width(data->argi);
	if (data->argi < 0)
	{
		tag.width_arg--;
		tag.sign = '-';
		tag.plus = FALSE;
		data->argi = -data->argi;
	}
	else
		tag.sign = '+';
	if (data->argi == 0 && tag.prcs)
		tag.width_arg = 0;
	if (tag.prcs)
		tag.prcs_fill = MAX(0, tag.prcs_parsed - tag.width_arg);
	pre_fill_width(data, tag);
	if (!(data->argi == 0 && tag.prcs))
		ft_putnbr_base(data->argi, DIGIT);
	data->printed += tag.width_arg;
	post_fill_width(data, tag);
}
