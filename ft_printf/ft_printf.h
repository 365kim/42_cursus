/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:19:33 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/17 01:01:59 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

typedef struct	s_pocket
{
	int			left;
	int			plus;
	int			space;
	int			zero;
	int			hexa;
	int			width_parsed;
	int			width_filler;
	int			width_arg;
	int			prcs;
	int			prcs_parsed;
	int			prcs_filler;
	int			len_modifier;
	int			negative;
	char		len_mod[3];
	char		conversion;
	char		filler;
	char		sign;
}				t_pocket;


/* ************************************************************************** */
/*                                 MAIN FUNCTION                              */
/* ************************************************************************** */

int		ft_printf(const char *format, ...);

void	parse_symbols(char *chunk, t_printf *data, t_pocket *P);
void	apply_and_write(t_printf *data, t_pocket P);



/* ************************************************************************** */
/*                                 PARSE SYMBOLS                              */
/* ************************************************************************** */

void	parse_flag(char **chunk, t_pocket *P);
void	parse_precision(char **chunk, t_pocket *P, t_printf *data);
void	parse_len_modifier(char **chunk, t_pocket *P);

void	set_new_pocket(t_pocket *P);



/* ************************************************************************** */
/*                                 WRITE EACH                                 */
/* ************************************************************************** */

void	write_string(t_printf *data, t_pocket P);
void	write_char(t_printf *data, t_pocket P);
void	write_hexa(t_printf *data, t_pocket P);
void	write_pointer(t_printf *data, t_pocket P);
void	write_number(t_printf *data, t_pocket P);

void	write_filler(int order, t_printf *data, t_pocket P);



#endif
