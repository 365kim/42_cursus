/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/17 13:15:32 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** - Parse symbols in the argument 'chunk' into the pocket 'P'.
** - Return the number of characters printed (excluding '\0' used to end output)
*/

void	parse_symbols(char *chunk, t_printf *data, t_pocket *P)
{
	while (is_set(*chunk, FLAG))
		parse_flag(&chunk, P);
	if (is_set(*chunk, DIGIT))
		P->width_parsed = ft_atoi(&chunk);
	if (*chunk == '.')
		parse_precision(&chunk, P, data);
	if (is_set(*chunk, LEN_MODIFIER))
		parse_len_modifier(&chunk, P);
	if (is_set(*chunk, CONVERSION))
		P->conversion = *chunk;
}

void	apply_and_write(t_printf *data, t_pocket P)
{
	if (is_set(P.conversion, STRING))
		write_string(data, P);
	else if (is_set(P.conversion, CHAR))
		write_char(data, P);
	else if (is_set(P.conversion, HEXA))
		write_hexa(data, P);
	else if (is_set(P.conversion, POINTER))
		write_pointer(data,P);
	else if (is_set(P.conversion, NUMBER))
		write_number(data,P);
}

int		ft_printf(const char *format, ...)
{
	t_printf	data;
	t_pocket	P;
	char		*chunk;
	int			len;

	va_start(data.ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			data.printed += write(1, &(*(format++)), 1);
		if (*format == '%')
		{
			set_new_pocket(&P);
			if ((len = ft_strstrhr(format + 1, CONVERSION) - format) == 0)
				return (-1);
			chunk = ft_strndup(++format, len);
			parse_symbols(chunk, &data, &P);
			apply_and_write(&data, P); 
			format += len;
			free(chunk);
		}
	}
	va_end(data.ap);
	return (data.printed);
}
