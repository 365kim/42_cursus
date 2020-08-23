/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_5_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/28 17:44:59 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_tag *tag, char *box, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (tag->prcs >= 0)
		tag->zero_fill = DISABLED;
	if (s[0] == '0')
		tag->hexa = H_DISABLED;
	if (s[0] == '0' && tag->prcs == 0)
		return (s = "");
	if (tag->prcs <= s_len)
		return (s);
	box = fill_box(tag->prcs, '0');
	if (box == NULL)
		return (NULL);
	ft_strcpy(&box[tag->prcs - s_len], s);
	return (box);
}

static void	process_pound(t_tag *tag, char *box, char conv, int s_len)
{
	char hexa[3];

	if (tag->hexa == H_DISABLED)
		return ;
	hexa[0] = '0';
	hexa[1] = conv;
	hexa[2] = '\0';
	if (tag->left_aligned == ENABLED || tag->zero_fill == ENABLED)
		ft_strncpy(box, hexa, 2);
	else
		ft_strncpy(&box[tag->width - s_len - 2], hexa, 2);
}

static char	*process_width(t_tag *tag, char *box, char *s, char conv)
{
	int s_len;

	s_len = ft_strlen(s);
	if (tag->width <= s_len && !tag->hexa)
		return (s);
	else if (tag->width < s_len + tag->hexa)
		tag->width = s_len + tag->hexa;
	if (tag->zero_fill == ENABLED && tag->prcs == DISABLED)
		tag->padding = '0';
	box = fill_box(tag->width, tag->padding);
	if (box == NULL)
		return (NULL);
	process_pound(tag, box, conv, s_len);
	if (tag->left_aligned == ENABLED)
		ft_strncpy(&box[0 + tag->hexa], s, s_len);
	else
		ft_strncpy(&box[tag->width - s_len], s, s_len);
	return (box);
}

int			print_hexa(t_tag *tag, char *res, char conv)
{
	t_box	*box;

	box = prepare_box();
	if ((res = process_precision(tag, box->prcs, res)) == NULL
		|| (res = process_width(tag, box->width, res, conv)) == NULL)
	{
		free_box(box);
		return (ERROR);
	}
	tag->nbyte += ft_putstr_n(res, ft_strlen(res));
	free_box(box);
	return (0);
}
