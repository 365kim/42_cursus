/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_each.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 13:53:47 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	parse_flag(char **chunk, t_pocket *C3)
{
//	printf("test flag\n");
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
//	printf("test width\n");
	if (is_set(**chunk, DIGIT))
	{
		C3->width = TRUE;
		C3->width_parsed = ft_atoi(chunk);
	}
}

void	parse_precision(char **chunk, t_pocket *C3, t_printf *input)
{
//	printf("test prec\n");
	if (**chunk == '.')
	{
		C3->precision = TRUE;
		(*chunk)++;
		if (**chunk == '*')
		{
			if (is_set(*(*chunk + 1), DIGIT))
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
//	printf("test conv\n");
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
