/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:03:22 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/17 01:00:06 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


void	write_string(t_printf *data, t_pocket P)
{
	char *str;
	char *tmp;

	str = va_arg(data->ap, char *);
	P.width_arg = ft_strlen(str);
	if (P.prcs && P.prcs_parsed < P.width_arg)
	{
		tmp = ft_strndup(str, P.prcs_parsed);
		data->args = tmp;
		free(tmp);
		P.width_arg = P.prcs_parsed;
	}
	else
		data->args = str;
	write_filler(1, data, P);
	data->printed += ft_putstr(data->args);
	write_filler(2, data, P);
}

void	write_char(t_printf *data, t_pocket P)
{
	P.width_arg = 1;
	write_filler(1, data, P);
	if (P.conversion == 'c')
		data->printed += ft_putchar((char)va_arg(data->ap, int));
	else
		data->printed += ft_putchar('%');
	write_filler(2, data, P);
}

void	write_pointer(t_printf *data, t_pocket P)
{
	P.width_arg = 11;
	write_filler(1, data, P);
	data->printed += ft_putstr("0x");
	ft_putnbr_base(va_arg(data->ap, unsigned long), HEX_LOW);
	write_filler(2, data, P);
	data->printed += 9;
}


void	write_hexa(t_printf *data, t_pocket P)
{
	data->argi = va_arg(data->ap, int);
	P.width_arg = get_itoa_base_width(data->argi, 16);
	if (P.prcs)
		P.prcs_filler = MAX(0, P.prcs_parsed - P.width_arg);
	P.width_arg += P.hexa;
	P.hexa && (P.zero && !P.prcs) ? ft_putstr("0x") : SKIP;
	write_filler(1, data, P);
	P.hexa && !(P.zero && !P.prcs) ? ft_putstr("0x") : SKIP;
	data->printed += ft_putchar_n('0', P.prcs_filler);
	P.conversion == 'x' ? ft_putnbr_base(data->argi, HEX_LOW)
			: ft_putnbr_base(data->argi, HEX_UP);
	write_filler(2, data, P);
	data->printed += P.width_arg;
}

void	write_number(t_printf *data, t_pocket P)
{
	data->argi = va_arg(data->ap, int);
	P.width_arg = get_itoa_width(data->argi);
	if (data->argi < 0)
	{
		P.width_arg--;
		P.sign = '-';
		P.plus = FALSE;
		data->argi = -data->argi;
	}
	else
		P.sign = '+';
	if (P.prcs)
		P.prcs_filler = MAX(0, P.prcs_parsed - P.width_arg);
	write_filler(1, data, P);
	data->printed += ft_putchar_n('0', P.prcs_filler);
	ft_putnbr_base(data->argi, DIGIT);
	data->printed += P.width_arg;
	write_filler(2, data, P);
}
