/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 01:22:15 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** - Parse symbols in the user argument 'format' into the pocket 'C3'.
** - Returns the number of characters printed (excluding '\0' used to end output)
*/

int		ft_printf(const char *format, ...)
{
	t_printf	input;
	t_pocket	C3;
	char		*chunk;
	int			len;

	va_start(input.ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			input.printed += write(1, &(*(format++)), 1);
		if (*format == '%')
		{
			set_new_pocket(&C3);
			if ((len = ft_strstrhr(format + 1, CONVERSION) - format) == 0)
				return (-1);
			chunk = ft_strndup(++format, len);
			parse_symbols(chunk, &input, &C3);
			apply_and_write(&input, C3); 
			format += len;
		}
	}
	va_end(input.ap);
	return (input.printed);
}

void	parse_symbols(char *chunk, t_printf *input, t_pocket *C3)
{
//	printf("test 1\n");
	parse_flag(&chunk, C3);
//	printf("test 2\n");
	parse_width(&chunk, C3);
//	printf("test 3\n");
	parse_precision(&chunk, C3, input);
//	printf("test 4\n");
	parse_conversion(&chunk, C3);
//	printf("test 5\n");
//	organize_pocket(C3);
}

void	apply_and_write(t_printf *input, t_pocket C3)
{
	if (is_set(C3.conversion, CHAR))
		write_char(input, C3);
	else if (is_set(C3.conversion, HEXA))
		write_hexa(input, C3);
	else if (is_set(C3.conversion, POINTER))
		write_pointer(input,C3);
	else if (is_set(C3.conversion, NUMBER))
		write_number(input,C3);
	else
		return ;
}

void	set_new_pocket(t_pocket *C3)
{
	C3->left = FALSE;
	C3->plus = FALSE;
	C3->space = FALSE;
	C3->zero = FALSE;
	C3->hexa = FALSE;
	C3->width = FALSE;
	C3->width_user = 0;
	C3->precision = FALSE;
	C3->precision_user = 0;
	C3->len_modifier = FALSE;
	C3->len_mod[0] = '\0';
	C3->conversion = '\0';
	C3->filler = '\0';
	C3->negative = FALSE;
	C3->width_arg = 0;
	C3->width_fill = 0;
}
