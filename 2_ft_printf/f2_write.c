/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_write.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:03:22 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/12 01:25:02 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ("%-5%")     :	"%    "
** ("% 05%")    :	"0000%"
** ("%-05%")    :	"    %"
*/

void	write_char(t_printf *hub, t_tag tag)
{
	if (tag.len_mod == L)
	{
		hub->argw = (wchar_t)va_arg(hub->ap, wint_t);
		hub->argw == 0 ? tag.len_mod = 0 : SKIP;
		hub->argw == 0 ? hub->argc = 0 : SKIP;
	}
	else if (tag.conversion == 'c')
		hub->argc = (char)va_arg(hub->ap, int);
	tag.width_arg = tag.len_mod == L ? get_atouni_width(hub->argw) : 1;
	tag.left ? tag.zero = FALSE : SKIP;
	tag.space = FALSE;
	pre_fill_width(hub, tag);
	if (tag.len_mod == L)
	{
		hub->args = ft_atouni(hub->argw);
		hub->printed += ft_putstr(hub->args);
		free(hub->args);
	}
	else if (tag.conversion == 'c')
		hub->printed += ft_putchar(hub->argc);
	else
		hub->printed += ft_putchar('%');
	post_fill_width(hub, tag);
}

/*
** ("%s", NULL)                     :	"(null)"
** ("%7.5s", NULL)                  :	"  (null"
** (%3.7s%7.7s, "hello", "world")   :	"hello  world"
*/

void	write_string(t_printf *hub, t_tag tag)
{
	char *str;
	char *tmp;

	str = va_arg(hub->ap, char *);
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
		hub->args = tmp;
		free(tmp);
		tag.width_arg = tag.prcs_parsed;
	}
	else
		hub->args = str;
	pre_fill_width(hub, tag);
	hub->printed += ft_putstr(hub->args);
	post_fill_width(hub, tag);
}

/*
** ("%5p", 0)    :	"  0x0"
*/

void	write_pointer(t_printf *hub, t_tag tag)
{
	hub->argi = va_arg(hub->ap, unsigned long);
	tag.width_arg = hub->argi == 0 ? 3 : 11;
	pre_fill_width(hub, tag);
	hub->printed += ft_putstr("0x");
	ft_putnbr_base(hub->argi, HEX_LOW);
	post_fill_width(hub, tag);
	hub->printed += tag.width_arg - 2;
}

/*
** ("%04.2d", 0)    :	"  01""
** ("%.0d", 0)      :	""
** ("%+.d", 0)      :	"+"
** ("%+5.d", 0)     :	"    +"
** ("% +5d", 0)     :	"   +0"
** ("%+05d", -7)    :	"-0007"
*/

void	write_decimal(t_printf *hub, t_tag tag)
{
	if (tag.conversion == 'u')
		hub->argi = (unsigned int)hub->argi;
	tag.width_arg = get_itoa_width(hub->argi);
	if (hub->argi < 0)
	{
		tag.width_arg--;
		tag.sign = '-';
		tag.plus = FALSE;
		hub->argi = -hub->argi;
	}
	else
		tag.sign = '+';
	if (hub->argi == 0 && tag.prcs)
		tag.width_arg = 0;
	if (tag.prcs)
		tag.prcs_fill = max(0, tag.prcs_parsed - tag.width_arg);
	pre_fill_width(hub, tag);
	if (!(hub->argi == 0 && tag.prcs))
		ft_putnbr_base(hub->argi, DIGIT);
	hub->printed += tag.width_arg;
	post_fill_width(hub, tag);
}

/*
** ("%x", 0)          :	"0"
** ("%.x", 0)         :	""
** ("%#.05", 0)       :	"00000"
** ("%#5.0x", 0)      :	"     "
** ("%#05x", 0)       :	"00000"
** ("%x", 4294967295u):	"ffffffff" (return value : 8)
*/

void	write_hexa(t_printf *hub, t_tag tag)
{
	tag.width_arg = get_itoa_base_width(hub->argi, 16);
	if (tag.prcs)
		tag.prcs_fill = max(0, tag.prcs_parsed - tag.width_arg);
	if (hub->argi == 0 && tag.prcs)
	{
		tag.width_arg = 0;
		tag.prcs_fill = tag.prcs_parsed;
		pre_fill_width(hub, tag);
		post_fill_width(hub, tag);
		return ;
	}
	tag.width_arg += tag.hexa;
	tag.hexa && (tag.zero && !tag.prcs) ? ft_putstr("0x") : SKIP;
	pre_fill_width(hub, tag);
	tag.hexa && !(tag.zero && !tag.prcs) ? ft_putstr("0x") : SKIP;
	tag.width_arg && tag.conversion == 'x' ?
		ft_putnbr_base(hub->argi, HEX_LOW) :
		ft_putnbr_base(hub->argi, HEX_UP);
	post_fill_width(hub, tag);
	hub->printed += tag.width_arg;
}
