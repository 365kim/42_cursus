/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_2_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 01:11:02 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_tag *tag, char *box, char *s)
{
	if (tag->prcs == DISABLED || tag->prcs >= ft_strlen(s))
		return (s);
	box = malloc(sizeof(char) * (tag->prcs + 1));
	if (box == NULL)
		return (NULL);
	ft_strncpy(box, s, tag->prcs);
	return (box);
}

static char	*process_width(t_tag *tag, char *box, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (tag->width <= s_len)
		return (s);
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

static void	put_result(t_tag *tag, char *res)
{
	tag->nbyte += ft_putstr_n(res, ft_strlen(res));
}

int			write_string(va_list ap, t_tag *tag)
{
	char	*res;
	t_box	*box;

	res = (char *)va_arg(ap, char *);
	if (res == NULL)
		res = ft_strndup("(null)", 6);
	box = prepare_box();
	if ((res = process_precision(tag, box->prcs, res)) == NULL
		|| (res = process_width(tag, box->width, res)) == NULL)
	{
		free_box(box);
		return (ERROR);
	}
	put_result(tag, res);
	free_box(box);
	return (0);
}
