/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/19 16:40:46 by mihykim          ###   ########.fr       */
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

void	parse_precision(char **chunk, t_tag *tag, t_printf *data)
{
	tag->prcs = TRUE;
	(*chunk)++;
	if (**chunk == '*')
	{
		data->argi = va_arg(data->ap, int);
		if (data->argi < 0)
			tag->prcs = FALSE;
		else
			tag->prcs_parsed = data->argi;
		(*chunk)++;
	}
	else
		tag->prcs_parsed = ft_atoi(chunk);
}

void	parse_len_modifier(char **chunk, t_tag *tag)
{
	int i;

	i = 0;
	while (is_set(**chunk, LEN_MODIFIER) && i < 2)
	{
		tag->len_modifier = TRUE;
		tag->len_mod[i] = **chunk;
		tag->len_mod[i + 1] = '\0';
		i++;
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
	tag->len_modifier = FALSE;
	tag->len_mod[0] = '\0';
	tag->conversion = '\0';
	tag->negative = 0;
	tag->sign = '\0';
}
