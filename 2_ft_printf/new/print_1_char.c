/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/28 17:43:11 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_tag *tag, char *box)
{
	tag->width--;
	if (tag->width < 1)
		return ("");
	box = fill_box(tag->width, tag->padding);
	if (box == NULL)
		return (NULL);
	return (box);
}

int			print_char(t_tag *tag, char c)
{
	char	*res;
	t_box	*box;

	if (tag->prcs > 0)
		return (UNDEFINED_BEHAVIOR);
	box = prepare_box();
	if ((res = process_width(tag, box->width)) == NULL)
	{
		free_box(box);
		return (ERROR);
	}
	if (tag->left_aligned == ENABLED)
		tag->nbyte += ft_putchar(c) + ft_putstr(res);
	else
		tag->nbyte += ft_putstr(res) + ft_putchar(c);
	free_box(box);
	return (0);
}
