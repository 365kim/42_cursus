/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/20 17:06:53 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	parse_flag(char **chunk, t_tag *tag)
{
	**chunk == '-' ? tag->left = TRUE : SKIP;
	**chunk == '+' ? tag->plus = TRUE : SKIP;
	**chunk == ' ' ? tag->space = TRUE : SKIP;
	**chunk == '0' ? tag->zero = TRUE : SKIP;
	**chunk == '#' ? tag->hexa = 2 : SKIP;
	(*chunk)++;
}

void	parse_precision(char **chunk, t_tag *tag, t_printf *hub)
{
	tag->prcs = TRUE;
	(*chunk)++;
	if (**chunk == '*')
	{
		hub->argi = va_arg(hub->ap, int);
		if (hub->argi < 0)
			tag->prcs = FALSE;
		else
			tag->prcs_parsed = hub->argi;
		(*chunk)++;
	}
	else
		tag->prcs_parsed = ft_atoi(chunk);
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
