/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:03:22 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/16 00:41:15 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	write_char(t_printf *data, t_pocket C3)
{
	if (C3.conversion == 'c' || C3.conversion == '%')
	{
		C3.width_arg = 1;
		write_filler(1, data, C3);
		if (C3.conversion == 'c')
			data->printed += ft_putchar((char)va_arg(data->ap, int));
		else
			data->printed += ft_putchar('%');
		write_filler(2, data, C3);
	}
	else if (C3.conversion == 's')
	{
		data->args = va_arg(data->ap, char *);
	//	apply_precision(data, C3);
		C3.width_arg = ft_strlen(data->args);
		write_filler(1, data, C3);
		data->printed += ft_putstr(data->args);
		write_filler(2, data, C3);
	}
}

void	write_hexa(t_printf *data, t_pocket C3)
{
	C3.width_arg = C3.hexa ? 10 : 8;
//	apply_precision
	write_filler(1, data, C3);
	C3.hexa ? data->printed += ft_putstr("0x") : FALSE;
//	data->printed += ft_putchar_n('0', C3_precision_value);
	C3.conversion == 'x' ? ft_putnbr_base(va_arg(data->ap, int), HEX_LOW)
				: ft_putnbr_base(va_arg(data->ap, int), HEX_UP);
	write_filler(2, data, C3);
	data->printed += 8;
}

void	write_pointer(t_printf *data, t_pocket C3)
{
	C3.width_arg = 11;
	write_filler(1, data, C3);
	data->printed += ft_putstr("0x");
	ft_putnbr_base(va_arg(data->ap, unsigned long), HEX_LOW);
	write_filler(2, data, C3);
	data->printed += 9;
}

void	write_number(t_printf *data, t_pocket C3)
{

	data->argi = va_arg(data->ap, int);
	if (data->argi < 0)
	{
		C3.sign = '-';
		C3.plus = FALSE;
		data->argi = -data->argi;
	}
	else
		C3.sign = '+';
	C3.width_arg = get_itoa_width(data->argi);
//	apply_precision(data, C3);
	write_filler(1, data, C3);
	ft_putnbr_base(data->argi, DIGIT);
	data->printed += C3.width_arg;
	write_filler(2, data, C3);
}
/*
void	apply_precision(t_printf *data, t_pocket *C3)
{
	if (!C3->precision)
		return ;
	if (C3->conversion == 's')
		data->args[precision_value] = '\0';
	if (C3->conversion == 'x' || C3->conversion == 'X')
	{
		if (precision_value -= 8 < 0)
			precision_value = 0;
	}
	if (C3->conversion == 'd')
	{
		
	}
}
*/





void	write_filler(int t, t_printf *data, t_pocket C3)
{
	if (C3.sign == '-' || C3.plus || C3.space)
		C3.width_parsed--;
	if (t == 1 && (C3.sign == '-' || C3.plus) && (C3.left || C3.zero))
		data->printed += ft_putchar(C3.sign);
	else if (t == 1 && (C3.sign == '+' && C3.space))
		data->printed += ft_putchar(' ');
	if ((t == 1 && !C3.left) || (t == 2 && C3.left))
	{
		C3.width_filler = C3.width_parsed - C3.width_arg;
		C3.width_filler < 0 ? C3.width_filler = 0 : 0;
		C3.filler = C3.zero ? '0' : ' ';
		data->printed += ft_putchar_n(C3.filler, C3.width_filler);
	}
	if (t == 1 && (C3.sign == '-' || C3.plus) && !(C3.left || C3.zero))
		data->printed += ft_putchar(C3.sign);
}
