/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_1_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 01:17:59 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_tag *tag, char *box, char c)
{
	if (tag->width < 2)
		tag->width = 1;
	box = fill_box(tag->width, tag->padding);
	if (box == NULL)
		return (NULL);
	if (tag->left_aligned == ENABLED && c != '\0')
		box[0] = c;
	else
		box[tag->width - 1] = c;
	return (box);
}

static void	put_result(t_tag *tag, char *res, char c)
{
	if (c != '\0')
		tag->nbyte += ft_putstr(res);
	else
		tag->nbyte += ft_putstr(res) + 1;
}

int			write_char(va_list ap, t_tag *tag)
{
	char c;
	char *res;
	t_box *box;
	
	c = (char)va_arg(ap, int);
	if (tag->prcs > 0)
		return (UNDEFINED_BEHAVIOR);
	box = prepare_box();
	if ((res = process_width(tag, box->width, c)) == NULL)
	{
		free_box(box);
		return (ERROR);
	}
	put_result(tag, res, c);
	free_box(box);
	return (0);
}
