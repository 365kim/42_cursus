/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 22:41:34 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** - Parse symbols in the parsed argument 'format' into the pocket 'C3'.
** - Return the number of characters printed (excluding '\0' used to end output)
*/

void	parse_symbols(char *chunk, t_printf *data, t_pocket *C3)
{
	parse_flag(&chunk, C3);
	parse_width(&chunk, C3);
	parse_precision(&chunk, C3, data);
	parse_len_modifier(&chunk, C3);
}

void	apply_and_write(t_printf *data, t_pocket C3)
{
	if (is_set(C3.conversion, CHAR))
		write_char(data, C3);
	else if (is_set(C3.conversion, HEXA))
		write_hexa(data, C3);
	else if (is_set(C3.conversion, POINTER))
		write_pointer(data,C3);
	else if (is_set(C3.conversion, NUMBER))
		write_number(data,C3);
	else
		return ;
}

int		ft_printf(const char *format, ...)
{
	t_printf	data;
	t_pocket	C3;
	char		*chunk;
	int			len;

	va_start(data.ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			data.printed += write(1, &(*(format++)), 1);
		if (*format == '%')
		{
			set_new_pocket(&C3);
			if ((len = ft_strstrhr(format + 1, CONVERSION) - format) == 0)
				return (-1);
			chunk = ft_strndup(++format, len);
			parse_symbols(chunk, &data, &C3);
			apply_and_write(&data, C3); 
			format += len;
			free(chunk);
		}
	}
	va_end(data.ap);
	return (data.printed);
}
