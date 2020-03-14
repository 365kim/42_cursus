/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:03:22 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 03:38:27 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	write_char(t_printf *input, t_pocket C3)
{
	if (C3.conversion == '%')
		input->printed += ft_putchar('%');
	else if (C3.conversion == 'c')
		input->printed += ft_putchar((char)va_arg(input->ap, int));
	else if (C3.conversion == 's')
		input->printed += ft_putstr(va_arg(input->ap, char *));
	else
		write(1, "error", 6);
}

void	write_hexa(t_printf *input, t_pocket C3)
{
	C3.hexa ? input->printed += ft_putstr("0x") : FALSE;
	C3.conversion == 'x' ? ft_putnbr_base(va_arg(input->ap, int), HEX_LOW)
				: ft_putnbr_base(va_arg(input->ap, int), HEX_UP);
	input->printed += 8;
}

void	write_pointer(t_printf *input, t_pocket C3)
{
	input->printed += ft_putstr("0x");
	organize_pocket(input, &C3);
	write_filler(input, C3);
	ft_putnbr_base(va_arg(input->ap, unsigned long), HEX_LOW);
	input->printed += 9;
}

void	write_filler(t_printf *input, t_pocket C3)
{
	int		i;

	i = 0;
	while (i < C3.width_fill)
	{
		input->printed += ft_putchar(C3.filler);
		i++;
	}
}

void	write_number(t_printf *input, t_pocket C3)
{
	long		num;

	num = va_arg(input->ap, int);
	if (num < 0 && C3.zero)
	{
		C3.negative = TRUE;
		num = -num;
	}
	C3.width_arg = get_itoa_width(num);
	organize_pocket(input, &C3);
	if (C3.left)
		input->printed += ft_putstr(ft_itoa(num));
	write_filler(input, C3);
	if(!C3.left)
		input->printed += ft_putstr(ft_itoa(num));
}

void	organize_pocket(t_printf *input, t_pocket *C3)
{
	if (C3->negative && C3->zero)
	{
		input->printed += ft_putchar('-');
		C3->width_arg--;
	}
	C3->width_fill = C3->width_user - C3->width_arg;
	if (C3->width_fill < 0)
		C3->width_fill = 0;
	C3->filler = C3->zero ? '0' : ' ';
}

