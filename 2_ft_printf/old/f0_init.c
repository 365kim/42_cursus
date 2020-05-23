/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f0_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:58:34 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/12 02:03:22 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_new_hub(t_printf *hub)
{
	hub->printed = 0;
	hub->args = 0;
	hub->argc = 0;
	hub->argi = 0;
	hub->argw = 0;
}

void	set_new_tag(t_tag *tag)
{
	tag->left = FALSE;
	tag->plus = FALSE;
	tag->space = FALSE;
	tag->zero = FALSE;
	tag->hexa = FALSE;
	tag->width_parsed = 0;
	tag->width_fill = 0;
	tag->width_arg = 0;
	tag->filler = '\0';
	tag->prcs = FALSE;
	tag->prcs_parsed = 0;
	tag->prcs_fill = 0;
	tag->len_mod = FALSE;
	tag->conversion = '\0';
	tag->negative = 0;
	tag->sign = '\0';
}
