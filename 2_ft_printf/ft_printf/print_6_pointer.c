/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_6_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/26 17:13:35 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_tag *tag, char *box, char *s)
{
	int s_len;

	if (s == NULL && tag->prcs != 0)
		s = "0";
	s_len = ft_strlen(s) + ft_strlen("0x");
	box = malloc(sizeof(char) * (s_len + 1));
	if (box == NULL)
		return (NULL);
	ft_strcpy(box, "0x");
	ft_strcpy(&box[2], s);
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
		ft_strncpy(&box[tag->width - s_len], s, s_len);
	return (box);
}

int			print_pointer(va_list ap, t_tag *tag)
{
	char	*res;
	t_box	*box;

	res = ft_lltoa_base(va_arg(ap, long long), HEX_LOW);
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
