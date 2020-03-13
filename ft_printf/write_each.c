/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:03:22 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/13 22:03:58 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	write_char(t_printf *input, t_pocket C3)
{
	if (C3.conversion == 'c')
		input->printed += ft_putchar((char)va_arg(input->ap, int));
	else if (C3.conversion == 's')
		input->printed += ft_putstr(va_arg(input->ap, char *));
	else if (C3.conversion == '%')
		input->printed += ft_putchar('%');
}

void	write_hexa(t_printf *input, t_pocket C3)
{
		ft_putstr("0x");
		input->printed += 2;
		C3.conversion == 'x' ? ft_putnbr_base(va_arg(input->ap, int), HEX_LOW)
					: ft_putnbr_base(va_arg(input->ap, int), HEX_UP);
		input->printed += 8;
}

void	write_pointer(t_printf *input, t_pocket C3)
{
	input->printed += 0;
	C3.conversion = '\0';
}

void	write_number(t_printf *input, t_pocket C3)
{
	input->printed += 0;
	C3.conversion = '\0';
}
