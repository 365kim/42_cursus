/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f1_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/17 19:30:22 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flag(char **chunk, t_tag *tag)
{
	**chunk == '-' ? tag->left = TRUE : SKIP;
	**chunk == '+' ? tag->plus = TRUE : SKIP;
	**chunk == ' ' ? tag->space = TRUE : SKIP;
	**chunk == '0' ? tag->zero = TRUE : SKIP;
	**chunk == '#' ? tag->hexa = 2 : SKIP;
	(*chunk)++;
}

void	parse_width(char **chunk, t_printf *hub, t_tag *tag)
{
	if (**chunk == '*')
	{
		(*chunk)++;
		tag->width_parsed = va_arg(hub->ap, int);
	}
	else
		tag->width_parsed = ft_atoi(chunk);
	if (tag->width_parsed < 0)
	{
		tag->left = TRUE;
		tag->width_parsed = -tag->width_parsed;
	}
}

void	parse_precision(char **chunk, t_printf *hub, t_tag *tag)
{
	tag->prcs = TRUE;
	(*chunk)++;
	if (**chunk == '*')
	{
		(*chunk)++;
		hub->argi = va_arg(hub->ap, int);
		if (hub->argi < 0)
			tag->prcs = FALSE;
		else
			tag->prcs_parsed = hub->argi;
	}
	else
	{
		tag->prcs_parsed = ft_atoi(chunk);
		if (tag->prcs_parsed < 0)
			tag->prcs = FALSE;
	}
}

void	parse_len_modifier(char **chunk, t_tag *tag)
{
	if (is_set(**chunk, LEN_MODIFIER))
	{
		tag->len_mod += **chunk == 'h' ? 4 : 2;
		(*chunk)++;
	}
	if (is_set(**chunk, LEN_MODIFIER))
	{
		tag->len_mod += **chunk == 'h' ? 40 : 20;
		(*chunk)++;
	}
}
