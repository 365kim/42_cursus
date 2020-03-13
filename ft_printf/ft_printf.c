/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/13 22:03:41 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** - Parse symbols in the given argument 'format' into the pocket 'C3'.
** - Returns the number of characters printed (excluding '\0' used to end output)
*/

int		ft_printf(const char *format, ...)
{
	t_printf	input;
	t_pocket	C3;
	char		*chunk;
	int			len;

	initialize(&input, &C3);
	va_start(input.ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			input.printed += write(1, &(*(format++)), 1);
		if (*format == '%')
		{
			len = ft_strstrhr(format, CONVERSION) - format;
			if (len == 0)
				return (0);
			chunk = ft_strndup(++format, len);
			execute_parsing(chunk, &input, &C3);
			execute_writing(&input, C3); 
			format += len;
		}
	}
	va_end(input.ap);
	return (input.printed);
}

void	execute_parsing(char *chunk, t_printf *input, t_pocket *C3)
{
	parse_flag(&chunk, C3);
	parse_width(&chunk, C3);
	parse_precision(&chunk, C3, input);
	parse_conversion(&chunk, C3);
}

void	execute_writing(t_printf *input, t_pocket C3)
{
	if (is_oneofthem(C3.conversion, CHAR))
		write_char(input, C3);
	else if (is_oneofthem(C3.conversion, HEXA))
		write_hexa(input, C3);
	else if (is_oneofthem(C3.conversion, POINTER))
		write_pointer(input,C3);
	else if (is_oneofthem(C3.conversion, NUMBER))
		write_number(input,C3);
	else
		return ;
}

void	initialize(t_printf *input, t_pocket *C3)
{
	input->printed = 0;
	C3->left = FALSE;
	C3->plus = FALSE;
	C3->space = FALSE;
	C3->zerofill = FALSE;
	C3->hexa = FALSE;
	C3->width = FALSE;
	C3->width = FALSE;
	C3->precision = FALSE;
	C3->precision = FALSE;
	C3->len_modifier = FALSE;
	C3->len_mod[0] = '\0';
	C3->conversion = '\0';
}
