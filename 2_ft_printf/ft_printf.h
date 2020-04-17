/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:19:33 by mihykim           #+#    #+#             */
/*   Updated: 2020/04/17 18:41:26 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>
# include "libft/libft.h"

# define FLAG "-+ 0#"
# define DIGIT "0123456789"

# define CONVERSION "cspdiuxXn%"
# define STRING "s"
# define CHAR "cs%"
# define POINTER "p"
# define NUM_GROUP "diuxX"
# define DECIMAL "diu"
# define HEXA "xX"
# define N "n"

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# define LEN_MODIFIER "hl"
# define HH 44
# define LL 22
# define H 4
# define L 2

# define TRUE 1
# define FALSE 0

# define SKIP 0

typedef struct	s_printf
{
	va_list		ap;
	char		*args;
	char		argc;
	long		argi;
	wint_t		argw;
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
	int			len_mod;
	int			negative;
	char		conversion;
	char		filler;
	char		sign;
}				t_tag;

/*
*****************************   MAIN FUNCTION   *******************************
*/

int				ft_printf(const char *format, ...);

/*
*****************************   0. INITIALIZE   *******************************
*/

void			set_new_hub(t_printf *hub);
void			set_new_tag(t_tag *tag);

/*
*****************************   1. PARSE SYMBOLS   ****************************
*/

void			parse_flag(char **chunk, t_tag *tag);
void			parse_width(char **chunk, t_printf *hub, t_tag *tag);
void			parse_precision(char **chunk, t_printf *hub, t_tag *tag);
void			parse_len_modifier(char **chunk, t_tag *tag);

/*
*****************************   2. WRITE ON CONDITION   ***********************
*/

void			write_char(t_printf *hub, t_tag tag);
void			write_string(t_printf *hub, t_tag tag);
void			write_pointer(t_printf *hub, t_tag tag);
void			write_decimal(t_printf *hub, t_tag tag);
void			write_hexa(t_printf *hub, t_tag tag);

/*
*****************************   3. ASSIST   ***********************************
*/

void			store_num_printed(t_printf *hub);
void			apply_len_modifier(t_printf *hub, t_tag tag);
void			pre_fill_width(t_printf *hub, t_tag tag);
void			post_fill_width(t_printf *hub, t_tag tag);

#endif
