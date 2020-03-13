/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/13 21:08:55 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_pocket(t_pocket *C3)
{
	C3->left = FALSE;
	C3->plus = FALSE;
	C3->space = FALSE;
	C3->zerofill = FALSE;
	C3->hexa = FALSE;
	C3->width = FALSE;
	C3->width = FALSE;
	C3->precision = FALSE;
	C3->precision = FALSE;
	C3->len_modifier = FALSE;
	C3->len_mod[0] = '\0';
	C3->conversion = '\0';
}

void	parse_flag(char **chunk, t_pocket *C3)
{
		while (is_oneofthem(**chunk, FLAG))
		{
			**chunk == '-' ? C3->left = TRUE : 0;
			**chunk == '+' ? C3->plus = TRUE : 0;
			**chunk == ' ' ? C3->space = TRUE : 0;
			**chunk == '0' ? C3->zerofill = TRUE : 0;
			**chunk == '#' ? C3->hexa = TRUE : 0;
			(*chunk)++;
		}
}

void	parse_width(char **chunk, t_pocket *C3)
{
	if (is_oneofthem(**chunk, DIGIT))
	{
		C3->width = TRUE;
		C3->width_value = ft_atoi(chunk);
		if (C3->left == FALSE)
			while (C3->width_value-- > 0)
				ft_putchar(' ');
	}
}

void	parse_precision(char **chunk, t_pocket *C3, t_printf *input)
{
	if (**chunk == '.')
	{
		C3->precision = TRUE;
		(*chunk)++;
		if (**chunk == '*')
		{
			if (is_oneofthem(*(*chunk + 1), DIGIT))
			{
				input->args = va_arg(input->ap, char *);
				C3->precision = ft_atoi(&input->args);
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

void	parse_conversion(char **chunk, t_pocket *C3)
{
	int i;

	i = 0;
	while (is_oneofthem(**chunk, LEN_MODIFIER) && i < 2)
	{
		C3->len_modifier = TRUE;
		C3->len_mod[i] = **chunk;
		C3->len_mod[i + 1] = '\0';
		i++;
		(*chunk)++;
	}
	C3->conversion = **chunk;
}
