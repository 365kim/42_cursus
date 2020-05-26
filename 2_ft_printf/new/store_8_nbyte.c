/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_8_nbyte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:06:08 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/26 17:57:11 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	store_nbyte(va_list ap, t_tag *tag)
{
	t_ptr ptr;

	if (tag->len_mod == DISABLED)
	{
		ptr.iptr = (int *)va_arg(ap, int *);
		*ptr.iptr = tag->nbyte;
	}
	else if (tag->len_mod == 'h' + 'h')
	{
		ptr.cptr = (signed char *)va_arg(ap, int *);
		*ptr.cptr = tag->nbyte;
	}
	else if (tag->len_mod == 'h')
	{
		ptr.sptr = (short int *)va_arg(ap, int *);
		*ptr.sptr = tag->nbyte;
	}
	else if (tag->len_mod == 'l' + 'l')
	{
		ptr.lptr = (long *)va_arg(ap, long *);
		*ptr.lptr = tag->nbyte;
	}
	else if (tag->len_mod == 'l')
	{
		ptr.llptr = (long long *)va_arg(ap, long long *);
		*ptr.llptr = tag->nbyte;
	}
	else
		return (ERROR);
	return (0);
}
