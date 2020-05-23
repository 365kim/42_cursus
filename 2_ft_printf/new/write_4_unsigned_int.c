/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_4_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:54:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 00:32:45 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_unsigned_int(va_list ap, t_tag *tag)
{
	char *res;
	t_box *box;

	res = ft_itoa_base((unsigned int)va_arg(ap, int), DIGIT);
	if (res == NULL)
		return (ERROR);
	box = prepare_box();
	if (tag->prcs > ft_strlen(res) && res[0] == '-')
		// && (res = process_precision(tag, box->prcs, res)) == NULL)
	{
		free_box(box);
		return (ERROR);
	}
	free_box(box);
	return (0);
}
