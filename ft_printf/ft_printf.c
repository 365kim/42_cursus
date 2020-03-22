/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/22 00:20:19 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** - Parse symbols in the argument 'chunk' into 'tag'.
** - Return the number of characters printed (excluding '\0' used to end output)
*/

static void	parse_symbols(char *chunk, t_printf *hub, t_tag *tag)
{
	while (is_set(*chunk, FLAG))
		parse_flag(&chunk, tag);
	if (is_set(*chunk, DIGIT))
		tag->width_parsed = ft_atoi(&chunk);
	if (*chunk == '.')
		parse_precision(&chunk, tag, hub);
	if (is_set(*chunk, LEN_MODIFIER))
		parse_len_modifier(&chunk, tag);
	if (is_set(*chunk, CONVERSION))
		tag->conversion = *chunk;
}

static void	write_on_condition(t_printf *hub, t_tag tag)
{
	if (is_set(tag.conversion, NUM_GROUP))
		apply_len_modifier(hub, tag);
	if (is_set(tag.conversion, STRING))
		write_string(hub, tag);
	else if (is_set(tag.conversion, CHAR))
		write_char(hub, tag);
	else if (is_set(tag.conversion, POINTER))
		write_pointer(hub,tag);
	else if (is_set(tag.conversion, DECIMAL))
		write_decimal(hub,tag);
	else if (is_set(tag.conversion, HEXA))
		write_hexa(hub, tag);
	else if (is_set(tag.conversion, N))
		store_num_printed(hub);
}

int		ft_printf(const char *format, ...)
{
	t_printf	hub;
	t_tag	tag;
	char		*chunk;
	int			len;

	va_start(hub.ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			hub.printed += write(1, &(*(format++)), 1);
		if (*format == '%')
		{
			set_new_tag(&tag);
			if ((len = ft_strstrhr(format + 1, CONVERSION) - format) == 0)
				return (-1);
			chunk = ft_strndup(++format, len);
			parse_symbols(chunk, &hub, &tag);
			write_on_condition(&hub, tag); 
			format += len;
			free(chunk);
		}
	}
	va_end(hub.ap);
	return (hub.printed);
}


