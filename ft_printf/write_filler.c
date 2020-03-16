/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:58:34 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/17 01:02:34 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_filler(int t, t_printf *data, t_pocket P)
{
	if (P.sign == '-' || P.plus || P.space)
		P.width_parsed--;
	if (t == 1 && (P.sign == '-' || P.plus) && (P.left || P.zero))
		data->printed += ft_putchar(P.sign);
	else if (t == 1 && (P.sign == '+' && P.space))
		data->printed += ft_putchar(' ');
	if ((t == 1 && !P.left) || (t == 2 && P.left))
	{
		P.zero ? (P.filler ='0') : (P.filler = ' ');
		P.prcs ? (P.filler = ' ') : SKIP;
		if (P.prcs && !P.prcs_filler)
			P.width_arg = MAX(P.width_arg, P.prcs_parsed);
		P.width_filler = MAX(0, P.width_parsed - P.width_arg - P.prcs_filler);
		data->printed += ft_putchar_n(P.filler, P.width_filler);
	}
	if (t == 1 && (P.sign == '-' || P.plus) && !(P.left || P.zero))
		data->printed += ft_putchar(P.sign);
}
