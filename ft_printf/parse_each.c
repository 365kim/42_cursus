/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/16 22:04:02 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	parse_flag(char **chunk, t_pocket *P)
{
	**chunk == '-' ? P->left = TRUE : SKIP;
	**chunk == '+' ? P->plus = TRUE : SKIP;
	**chunk == ' ' ? P->space = TRUE : SKIP;
	**chunk == '0' ? P->zero = TRUE : SKIP;
	**chunk == '#' ? P->hexa = 2 : SKIP;
	(*chunk)++;
}

void	parse_precision(char **chunk, t_pocket *P, t_printf *data)
{
	P->prcs = TRUE;
	(*chunk)++;
	if (**chunk == '*')
	{
		data->argi = va_arg(data->ap, int);
		if (data->argi < 0)
			P->prcs = FALSE;
		else
			P->prcs_parsed = data->argi;
		(*chunk)++;
	}
	else
		P->prcs_parsed = ft_atoi(chunk);
}

void	parse_len_modifier(char **chunk, t_pocket *P)
{
	int i;

	i = 0;
	while (is_set(**chunk, LEN_MODIFIER) && i < 2)
	{
		P->len_modifier = TRUE;
		P->len_mod[i] = **chunk;
		P->len_mod[i + 1] = '\0';
		i++;
		(*chunk)++;
	}
}

void	set_new_pocket(t_pocket *P)
{
	P->left = FALSE;
	P->plus = FALSE;
	P->space = FALSE;
	P->zero = FALSE;
	P->hexa = FALSE;
	P->width_parsed = 0;
	P->width_filler = 0;
	P->width_arg = 0;
	P->filler = '\0';
	P->prcs = FALSE;
	P->prcs_parsed = 0;
	P->prcs_filler = 0;
	P->len_modifier = FALSE;
	P->len_mod[0] = '\0';
	P->conversion = '\0';
	P->negative = 0;
	P->sign = '\0';
}
