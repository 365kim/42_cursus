/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_4_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/28 17:44:20 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			print_unsigned_int(t_tag *tag, char *res)
{
	t_box *box;

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
