/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_5_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 21:35:06 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_tag *tag, char *box, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (s[0] == '0' && s[1] == '\0' && tag->prcs == 0)
		s = "";
	if (tag->prcs <= s_len)
		return (s);
	if (tag->hexa == ENABLED)
		tag->prcs += 2;
	box = fill_box(tag->prcs, '0');
	if (box == NULL)
		return (NULL);
	if (tag->hexa == ENABLED)
	{
		ft_strcpy(box, "0x");
		ft_strcpy(&box[tag->prcs - s_len], s);
	}
	else
		ft_strcpy(&box[tag->prcs - s_len], s);
	return (box);
}

static char	*process_width(t_tag *tag, char *box, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (tag->width <= s_len)
		return (s);
	if (tag->zero_fill == ENABLED && tag->prcs == DISABLED)
		tag->padding = '0';
	box = fill_box(tag->width, tag->padding);
	if (box == NULL)
		return (NULL);
	if (tag->left_aligned == ENABLED)
		ft_strncpy(box, s, s_len);
	else
	{
		box += tag->width - s_len;
		ft_strncpy(box, s, s_len);
		box -= tag->width - s_len;
	}
	return (box);
}

int			write_hexa(va_list ap, t_tag *tag, char conversion)
{
	char	*res;
	t_box	*box;

	res = (conversion == 'X') ? 
		(char *)ft_itoa_base(va_arg(ap, int), HEX_UP) : 
		(char *)ft_itoa_base(va_arg(ap, int), HEX_LOW);
	box = prepare_box();
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
