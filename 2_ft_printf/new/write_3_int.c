/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_3_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 22:06:25 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

static char *prepare_sign(t_tag *tag, char *s)
{
	if (s[0] == '-')
	{
		tag->sign = '-';
		s++;
	}
	else if (tag->plus == ENABLED)
		tag->sign = '+';
	else if (tag->space == ENABLED)
		tag->sign = ' ';
	return (s);
}

static char	*process_precision(t_tag *tag, char *box, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (s[0] == '0' && tag->prcs == 0)
		s = "";
	if (tag->prcs <= s_len)
		return (s);
	box = fill_box(tag->prcs, '0');
	if (box == NULL)
		return (NULL);
	ft_strcpy(&box[tag->prcs - s_len], s);
	return (box);
}

static char	*process_sign(t_tag *tag, char *box, int s_len)
{
	if (tag->sign == '\0')
		return (box);
	if ((tag->zero_fill == ENABLED && tag->prcs == DISABLED)
			|| tag->left_aligned == ENABLED)
		box[0] = tag->sign;
	else
		box[tag->width - s_len - 1] = tag->sign;
	return (box);
}

static char	*process_width(t_tag *tag, char *box, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (tag->sign == '\0' && tag->width < s_len)
		return (s);
	if (tag->zero_fill == ENABLED &&
			tag->prcs == DISABLED && tag->left_aligned == DISABLED)
		tag->padding = '0';
	if (tag->width < s_len)
		tag->width = s_len;
	if (tag->sign && tag->width == s_len)
		tag->width++;
	box = fill_box(tag->width, tag->padding);
	if (box == NULL)
		return (NULL);
	if (tag->left_aligned == ENABLED && tag->sign)
		ft_strncpy(box + 1, s, s_len);
	else if (tag->left_aligned == ENABLED)
		ft_strncpy(box, s, s_len);
	else
		ft_strncpy(&box[tag->width - s_len], s, s_len);
	return (process_sign(tag, box, s_len));
}

int	write_int(va_list ap, t_tag *tag)
{
	char *res;
	t_box *box;

	res = ft_itoa((int)va_arg(ap, int));
	if (res == NULL)
		return (ERROR);
	box = prepare_box();
	res = prepare_sign(tag, res);
	if ((res = process_precision(tag, box->prcs, res)) == NULL
		|| (res = process_width(tag, box->width, res)) == NULL)
	{
		free_box(box);
		return (ERROR);
	}
	tag->nbyte += ft_putstr_n(res, ft_strlen(res));
	free_box(box);
	return (0);
}
