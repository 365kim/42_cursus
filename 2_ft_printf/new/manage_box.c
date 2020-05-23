/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 22:38:31 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/23 23:26:12 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_box	*prepare_box(void)
{
	t_box *box;

	box = malloc(sizeof(t_box));
	box->prcs = NULL;
	box->width = NULL;
	return (box);
}

char	*fill_box(int size, char tag_padding)
{
	char *box;

	box = malloc(sizeof(char) * (size + 1));
	if (box == NULL)
		return (NULL);
	ft_memset(box, tag_padding, size);
	box[size] = '\0';
	return (box);
}

void	free_box(t_box *box)
{
	if (box->prcs)
		free(box->prcs);
	if (box->width)
		free(box->width);
	free(box);
}
