/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/19 22:15:15 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** - Parse symbols in the argument 'chunk' into 'tag'.
** - Return the number of characters printed (excluding '\0' used to end output)
*/

int		ft_printf(const char *format, ...)
{
	t_printf	data;
	t_tag	tag;
	char		*chunk;
	int			len;

	va_start(data.ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			data.printed += write(1, &(*(format++)), 1);
		if (*format == '%')
		{
			set_new_tag(&tag);
			if ((len = ft_strstrhr(format + 1, CONVERSION) - format) == 0)
				return (-1);
			chunk = ft_strndup(++format, len);
			parse_symbols(chunk, &data, &tag);
			write_on_condition(&data, tag); 
			format += len;
			free(chunk);
		}
	}
	va_end(data.ap);
	return (data.printed);
}

void	parse_symbols(char *chunk, t_printf *data, t_tag *tag)
{
	while (is_set(*chunk, FLAG))
		parse_flag(&chunk, tag);
	if (is_set(*chunk, DIGIT))
		tag->width_parsed = ft_atoi(&chunk);
	if (*chunk == '.')
		parse_precision(&chunk, tag, data);
	if (is_set(*chunk, LEN_MODIFIER))
		parse_len_modifier(&chunk, tag);
	if (is_set(*chunk, CONVERSION))
		tag->conversion = *chunk;
}

void	write_on_condition(t_printf *data, t_tag tag)
{
	if (is_set(tag.conversion, NUM_GROUP))
		get_arg_for_number(data, tag);
	if (is_set(tag.conversion, STRING))
		write_string(data, tag);
	else if (is_set(tag.conversion, CHAR))
		write_char(data, tag);
	else if (is_set(tag.conversion, POINTER))
		write_pointer(data,tag);
	else if (is_set(tag.conversion, DECIMAL))
		write_decimal(data,tag);
	else if (is_set(tag.conversion, HEXA))
		write_hexa(data, tag);
}

void	get_arg_for_number(t_printf *data, t_tag tag)
{
	if (tag.len_mod == HH)
		data->argi = (char)va_arg(data->ap, int);
	else if (tag.len_mod == H)
		data->argi = (short)va_arg(data->ap, int);
	else if (tag.len_mod == LL)
		data->argi = (long)va_arg(data->ap, long);
	else if (tag.len_mod == L)
		data->argi = (long long)va_arg(data->ap, long long);
	else if (tag.len_mod == FALSE)
		data->argi = va_arg(data->ap, int);
}
