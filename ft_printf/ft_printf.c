/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/13 00:26:54 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	parse_format(char *chunk, t_data *data)
{
	char	flag;

	flag = '\0';
	while (*chunk)
	{
		if (is_oneofthem(*chunk, FLAG))
		{
			flag = *chunk;
			chunk++;
		}
		if (*chunk == 'c')
			data->printed += ft_putchar((char)va_arg(data->ap, int));
		else if (*chunk == 's')
			data->printed += ft_putstr(va_arg(data->ap, char *));
		else if (*chunk == 'x' || *chunk == 'X')
		{
			flag == '#' ? ft_putstr("0x") : flag ;
			flag == '#' ? data->printed += 2 : flag ;
			*chunk == 'x' ? ft_putnbr_base(va_arg(data->ap, int), HEX_LOW)
						: ft_putnbr_base(va_arg(data->ap, int), HEX_UP);
			data->printed += 8;
		}
		else if (*chunk == '%')
			data->printed += ft_putchar('%');
		else
			return ;
		chunk++;
	}
}

/*
** - Returns the number of characters printed (excluding '\0' used to end output)
*/

int		ft_printf(const char *format, ...)
{
	t_data	data;
	char	*chunk;
	int		len;

	data.printed = 0;
	va_start(data.ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
		{
			data.printed += write(1, &(*format), 1);
			format++;
		}
		if (*format == '%')
		{
			len = ft_strstrhr(format, CONVERSION) - format;
			if (len == 0)
				return (0);
			chunk = ft_strndup(++format, len);
			parse_format(chunk, &data);
			format += len;
		}
	}
	va_end(data.ap);
	return (data.printed);
}
