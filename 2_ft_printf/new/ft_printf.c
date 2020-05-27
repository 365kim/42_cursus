/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:45 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/28 00:54:30 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** - Parse symbols in the argument 'form' into 'tag'.
** - Return the number of characters printed (excluding '\0' used to end output)
*/

static int	write_on_condition(char *form, va_list ap, t_tag *tag)
{
	if (*form == 'c')
		return (pre_process_char(ap, tag));
	else if (*form == 's')
		return (pre_process_string(ap, tag));
	else if (*form == 'd' || *form == 'i')
		return (pre_process_int(ap, tag));
	else if (*form == 'u')
		return (pre_process_unsigned_int(ap, tag));
	else if (*form == 'x')
		return (pre_process_hexa(ap, tag, HEX_LOW, 'x'));
	else if (*form == 'X')
		return (pre_process_hexa(ap, tag, HEX_UP, 'X'));
	else if (*form == 'p')
		return (print_pointer(ap, tag));
	else if (*form == '%')
		return (print_percent(tag));
	else if (*form == 'n')
		return (store_nbyte(ap, tag));
	else
		return (ERROR);
}

static void	prepare_new_tag(t_tag *tag)
{
	tag->left_aligned = DISABLED;
	tag->width = DISABLED;
	tag->prcs = DISABLED;
	tag->zero_fill = DISABLED;
	tag->plus = DISABLED;
	tag->space = DISABLED;
	tag->hexa = H_DISABLED;
	tag->len_mod = DISABLED;
	tag->sign = '\0';
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
