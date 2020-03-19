/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:19:33 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/19 20:04:01 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_tagRINTF_H
# define FT_tagRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

# define FLAG "-+ 0#"
# define DIGIT "0123456789"

# define LEN_MODIFIER "hl"

# define CONVERSION "cspdiuxX%"
# define STRING "s"
# define CHAR "cs%"
# define POINTER "p"
# define NUM_GROUP "diuxX"
# define NUMBER "diu"
# define HEXA "xX"

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# define TRUE 1
# define FALSE 0

# define SKIP 0
# define MAX(a, b)	(((a) > (b)) ? (a) : (b))
# define MIN(a, b)	(((a) < (b)) ? (a) : (b))

typedef struct	s_printf
{
	va_list		ap;
	char		*args;
	char		argc;
	long		argi;
	int			printed;
}				t_printf;

typedef struct	s_tag
{
	int			left;
	int			plus;
	int			space;
	int			zero;
	int			hexa;
	int			width_parsed;
	int			width_fill;
	int			width_arg;
	int			prcs;
	int			prcs_parsed;
	int			prcs_fill;
	int			len_modifier;
	int			negative;
	char		len_mod[3];
	char		conversion;
	char		filler;
	char		sign;
}				t_tag;


/* ************************************************************************** */
/*                                 MAIN FUNCTION                              */
/* ************************************************************************** */

int		ft_printf(const char *format, ...);

void	parse_symbols(char *chunk, t_printf *data, t_tag *tag);
void	apply_and_write(t_printf *data, t_tag tag);



/* ************************************************************************** */
/*                                 PARSE SYMBOLS                              */
/* ************************************************************************** */

void	parse_flag(char **chunk, t_tag *tag);
void	parse_precision(char **chunk, t_tag *tag, t_printf *data);
void	parse_len_modifier(char **chunk, t_tag *tag);

void	set_new_tag(t_tag *tag);



/* ************************************************************************** */
/*                                 WRITE EACH                                 */
/* ************************************************************************** */

void	write_string(t_printf *data, t_tag tag);
void	write_char(t_printf *data, t_tag tag);
void	write_hexa(t_printf *data, t_tag tag);
void	write_pointer(t_printf *data, t_tag tag);
void	write_number(t_printf *data, t_tag tag);

void	pre_fill_width(t_printf *data, t_tag tag);
void	post_fill_width(t_printf *data, t_tag tag);



#endif
