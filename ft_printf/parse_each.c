/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 23:37:18 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	parse_flag(char **chunk, t_pocket *C3)
{
	while (is_set(**chunk, FLAG))
	{
		**chunk == '-' ? C3->left = TRUE : 0;
		**chunk == '+' ? C3->plus = TRUE : 0;
		**chunk == ' ' ? C3->space = TRUE : 0;
		**chunk == '0' ? C3->zero = TRUE : 0;
		**chunk == '#' ? C3->hexa = TRUE : 0;
		(*chunk)++;
	}
}

void	parse_width(char **chunk, t_pocket *C3)
{
	if (is_set(**chunk, DIGIT))
		C3->width_parsed = ft_atoi(chunk);
}

void	parse_precision(char **chunk, t_pocket *C3, t_printf *data)
{
	if (**chunk == '.')
	{
		C3->precision = TRUE;
		(*chunk)++;
		if (**chunk == '*')
		{
			if (is_set(*(*chunk + 1), DIGIT))
			{
				data->args = va_arg(data->ap, char *);
				C3->precision = ft_atoi(&data->args);
			}
			else if (**chunk == '-')
			{
				*chunk = ft_strstrhr(*chunk, DIGIT) + 1;
				C3->precision = 0;
			}
			else
				C3->precision = 0;
		}
		else
			C3->precision = ft_atoi(chunk);
	}
}

void	parse_len_modifier(char **chunk, t_pocket *C3)
{
	int i;

	i = 0;
	while (is_set(**chunk, LEN_MODIFIER) && i < 2)
	{
		C3->len_modifier = TRUE;
		C3->len_mod[i] = **chunk;
		C3->len_mod[i + 1] = '\0';
		i++;
		(*chunk)++;
	}
	C3->conversion = **chunk;
}

void	set_new_pocket(t_pocket *C3)
{
	C3->left = FALSE;
	C3->plus = FALSE;
	C3->space = FALSE;
	C3->zero = FALSE;
	C3->hexa = FALSE;
	C3->width_parsed = 0;
	C3->width_arg = 0;
	C3->width_filler = 0;
	C3->filler = '\0';
	C3->precision = FALSE;
	C3->precision_parsed = 0;
	C3->len_modifier = FALSE;
	C3->len_mod[0] = '\0';
	C3->conversion = '\0';
	C3->negative = 0;
	C3->sign = '\0';
}
