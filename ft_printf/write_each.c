/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:03:22 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 15:25:19 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	write_filler(t_printf *input, t_pocket *C3)
{
	C3->width_fill = C3->width_parsed - C3->width_arg;
	if (C3->negative && C3->zero)
	{
		input->printed += ft_putchar('-');
		C3->width_fill--;
	}
	if (C3->width_fill < 0)
		C3->width_fill = 0;
	C3->filler = C3->zero ? '0' : ' ';
	input->printed += ft_putchar_n(C3->filler, C3->width_fill);
}

void	write_char(t_printf *input, t_pocket C3)
{
	char *str;

	if (C3.conversion == 'c' || C3.conversion == '%')
	{
		C3.width_arg = 1;
		C3.left ? "LATER" : write_filler(input, &C3);
		if (C3.conversion == 'c')
			input->printed += ft_putchar((char)va_arg(input->ap, int));
		else
			input->printed += ft_putchar('%');
		C3.left ? write_filler(input, &C3) : "DONE";
	}
	else if (C3.conversion == 's')
	{
		str = va_arg(input->ap, char *);
		C3.width_arg = ft_strlen(str);
		C3.left ? "LATER" : write_filler(input, &C3);
		input->printed += ft_putstr(str);
		C3.left ? write_filler(input, &C3) : "DONE";
	}
}

void	write_hexa(t_printf *input, t_pocket C3)
{
	C3.width_arg = C3.hexa ? 10 : 8;
	C3.left ? "LATER" : write_filler(input, &C3);
	C3.hexa ? input->printed += ft_putstr("0x") : FALSE;
	C3.conversion == 'x' ? ft_putnbr_base(va_arg(input->ap, int), HEX_LOW)
				: ft_putnbr_base(va_arg(input->ap, int), HEX_UP);
	C3.left ? write_filler(input, &C3) : "DONE";
	input->printed += 8;
}

void	write_pointer(t_printf *input, t_pocket C3)
{
	C3.width_arg = 11;
	C3.left ? "LATER" : write_filler(input, &C3);
	input->printed += ft_putstr("0x");
	ft_putnbr_base(va_arg(input->ap, unsigned long), HEX_LOW);
	C3.left ? write_filler(input, &C3) : "DONE";
	input->printed += 9;
}

void	write_number(t_printf *input, t_pocket C3)
{
	long	num;

	num = va_arg(input->ap, int);
	if (num < 0 && C3.zero)
	{
		C3.negative = TRUE;
		num = -num;
	}
	C3.width_arg = get_itoa_width(num);
	C3.left ? "LATER" : write_filler(input, &C3);
	input->printed += ft_putstr(ft_itoa(num));
	C3.left ? write_filler(input, &C3) : "DONE";
}
