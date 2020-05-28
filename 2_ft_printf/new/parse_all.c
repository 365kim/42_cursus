/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/28 17:41:37 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(char **form, t_tag *tag)
{
	while (is_set(**form, FLAG))
	{
		**form == '-' ? tag->left_aligned = ENABLED : SKIP;
		**form == '0' ? tag->zero_fill = ENABLED : SKIP;
		**form == '+' ? tag->plus = ENABLED : SKIP;
		**form == ' ' ? tag->space = ENABLED : SKIP;
		**form == '#' ? tag->hexa = H_ENABLED : SKIP;
		(*form)++;
	}
}

static void	parse_width(char **form, va_list ap, t_tag *tag)
{
	char *dup;

	if (!(**form == '*' || is_set(**form, DIGIT)))
		return ;
	if (**form == '*')
	{
		tag->width = va_arg(ap, int);
		(*form)++;
	}
	else
	{
		dup = ft_strndup(*form, ft_strlen(*form));
		tag->width = ft_atoi(dup);
		free(dup);
		while (is_set(**form, DIGIT))
			(*form)++;
	}
	if (tag->width < 0)
	{
		tag->left_aligned = ENABLED;
		tag->width = -tag->width;
	}
}

static void	parse_precision(char **form, va_list ap, t_tag *tag)
{
	char *dup;

	if (**form != '.')
		return ;
	(*form)++;
	if (**form == '*')
	{
		tag->prcs = va_arg(ap, int);
		(*form)++;
	}
	else if (is_set(**form, DIGIT))
	{
		dup = ft_strndup(*form, ft_strlen(*form));
		tag->prcs = ft_atoi(dup);
		free(dup);
		while (is_set(**form, DIGIT))
			(*form)++;
	}
	else
		tag->prcs = 0;
	if (tag->prcs < 0)
		tag->prcs = DISABLED;
}

static void	parse_len_modifier(char **form, t_tag *tag)
{
	if (!is_set(**form, LEN_MODIFIER))
		return ;
	tag->len_mod += ENABLED;
	while (is_set(**form, LEN_MODIFIER))
	{
		tag->len_mod += **form;
		(*form)++;
	}
}

int			parse_symbols(char **form, va_list ap, t_tag *tag)
{
	if (**form == '\0')
		return (ERROR);
	parse_flags(form, tag);
	parse_width(form, ap, tag);
	parse_precision(form, ap, tag);
	parse_len_modifier(form, tag);
	if (is_set(**form, CONVERSION) == FALSE)
		return (ERROR);
	return (0);
}
