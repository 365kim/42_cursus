/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:06:08 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/28 17:42:21 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pre_process_char(va_list ap, t_tag *tag)
{
	wint_t	w;
	char	*res;
	char	c;

	if (tag->len_mod == DISABLED)
	{
		c = (char)va_arg(ap, int);
		return (print_char(tag, c));
	}
	else if (tag->len_mod == 'l')
	{
		w = (wchar_t)va_arg(ap, wint_t);
		res = ft_atouni(w);
		return (print_string(tag, res));
	}
	return (ERROR);
}

int	pre_process_string(va_list ap, t_tag *tag)
{
	wchar_t	*ws;
	char	*res;
	char	*join;
	int		i;

	if (tag->len_mod == DISABLED)
	{
		res = va_arg(ap, char *);
		return (print_string(tag, res));
	}
	else if (tag->len_mod == 'l')
	{
		ws = va_arg(ap, wchar_t *);
		res = ft_atouni(ws[0]);
		i = 1;
		while (ws[i] != L'\0')
		{
			join = ft_strjoin(res, ft_atouni(ws[i++]));
			res = join;
			free(join);
		}
		return (print_string(tag, res));
	}
	return (ERROR);
}

int	pre_process_int(va_list ap, t_tag *tag)
{
	char		*res;

	if (tag->len_mod == DISABLED)
		res = ft_itoa((int)va_arg(ap, int));
	else if (tag->len_mod == 'h' + 'h')
		res = ft_itoa((char)va_arg(ap, int));
	else if (tag->len_mod == 'h')
		res = ft_itoa((short)va_arg(ap, int));
	else if (tag->len_mod == 'l')
		res = ft_lltoa((long)va_arg(ap, long));
	else if (tag->len_mod == 'l' + 'l')
		res = ft_lltoa((long long)va_arg(ap, long long));
	else
		return (ERROR);
	if (res == NULL)
		return (ERROR);
	return (print_int(tag, res));
}

int	pre_process_unsigned_int(va_list ap, t_tag *tag)
{
	char	*res;

	if (tag->len_mod == DISABLED)
		res = ft_uitoa((unsigned int)va_arg(ap, int));
	else if (tag->len_mod == 'h' + 'h')
		res = ft_uitoa((unsigned char)va_arg(ap, int));
	else if (tag->len_mod == 'h')
		res = ft_uitoa((unsigned short)va_arg(ap, int));
	else if (tag->len_mod == 'l')
		res = ft_ulltoa((unsigned long)va_arg(ap, long));
	else if (tag->len_mod == 'l' + 'l')
		res = ft_ulltoa((unsigned long long)va_arg(ap, long long));
	else
		return (ERROR);
	if (res == NULL)
		return (ERROR);
	return (print_unsigned_int(tag, res));
}

int	pre_process_hexa(va_list ap, t_tag *tag, char *base, char conv)
{
	char	*res;

	if (tag->len_mod == DISABLED)
		res = ft_itoa_base((int)va_arg(ap, int), base);
	else if (tag->len_mod == 'h' + 'h')
		res = ft_itoa_base((unsigned char)va_arg(ap, int), base);
	else if (tag->len_mod == 'h')
		res = ft_itoa_base((unsigned short)va_arg(ap, int), base);
	else if (tag->len_mod == 'l')
		res = ft_lltoa_base((long)va_arg(ap, long), base);
	else if (tag->len_mod == 'l' + 'l')
		res = ft_lltoa_base((long long)va_arg(ap, long long), base);
	else
		return (ERROR);
	if (res == NULL)
		return (ERROR);
	return (print_hexa(tag, res, conv));
}
