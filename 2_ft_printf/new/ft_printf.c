/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 01:17:14 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** - Parse symbols in the argument 'form' into 'tag'.
** - Return the number of characters printed (excluding '\0' used to end output)
*/

static int	write_on_condition(char *form, va_list ap, t_tag *tag)
{
	if (*form == 'c')
		return (write_char(ap, tag));
	else if (*form == 's')
		return (write_string(ap, tag));
	else if (*form == 'd' || *form == 'i')
		return (write_int(ap, tag));
	else if (*form == 'u')
		return (write_unsigned_int(ap, tag));
	else if (*form == 'x' || *form == 'X')
		return (write_hexa(ap, tag, *form));
	else if (*form == 'p')
		return (write_pointer(ap, tag));
	else if (*form == '%')
		return (write_percent(tag));
	//else if (*form == 'n')
	//	return (write_nbyte(tag));
	else
		return (ERROR);
}

static void	prepare_new_tag(t_tag *tag)
{
	tag->left_aligned = DISABLED;
	tag->width = DISABLED;
	tag->prcs = DISABLED;
	tag->zero_fill = DISABLED;
	tag->padding = ' ';
}

static int	process_format(char *form, va_list ap)
{
	t_tag	tag;

	tag.nbyte = 0;
	if (form == 0)
		return (ERROR);
	while (*form)
	{
		while (*form != '%' && *form)
		{
			tag.nbyte += ft_putchar(*form);
			form++;
		}
		if (*form == '%')
		{
			form++;
			prepare_new_tag(&tag);
			if (parse_symbols(&form, ap, &tag) == ERROR)
				return (ERROR);
			if (write_on_condition(form, ap, &tag) == ERROR)
				return (ERROR);
			form++;
		}
	}
	return (tag.nbyte);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nbyte;

	va_start(ap, format);
	if ((nbyte = process_format((char *)format, ap)) == ERROR)
		return (ERROR);
	va_end(ap);
	return (nbyte);
}
