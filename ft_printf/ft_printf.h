/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:19:33 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/13 22:01:50 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

//#include "libft.h"

# define ALL "cspdiuxX%#-+.*0123456789"

# define LEN_MODIFIER "hl"

# define CONVERSION "cspdiuxX%"
# define CHAR "cs%"
# define POINTER "p"
# define NUMBER "diu"
# define HEXA "xX"

# define FLAG "-+ 0#"
# define DIGIT "0123456789"

# define DECIMAL "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# define TRUE 1
# define FALSE 0

typedef struct	s_printf
{
	va_list		ap;
	char		*args;
	char		argc;
	int			argi;
	int			printed;
}				t_printf;

typedef struct	s_pocket
{
	int			left;
	int			plus;
	int			space;
	int			zerofill;
	int			hexa;
	int			width;
	int			width_value;
	int			precision;
	int			precision_value;
	int			len_modifier;
	char		len_mod[3];
	char		conversion;
}				t_pocket;


/* **************************          MAIN          ************************ */

int		ft_printf(const char *format, ...);

void	initialize(t_printf *input, t_pocket *C3);
void	execute_parsing(char *chunk, t_printf *input, t_pocket *C3);
void	execute_writing(t_printf *input, t_pocket C3);



/* **************************          PARSE          ************************ */

void	parse_flag(char **chunk, t_pocket *C3);
void	parse_width(char **chunk, t_pocket *C3);
void	parse_precision(char **chunk, t_pocket *C3, t_printf *input);
void	parse_conversion(char **chunk, t_pocket *C3);



/* **************************          PRINT         ************************ */

int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr_base(int n, char *base);



/* **************************       HANDLE ASCII      ************************ */

int		ft_atoi(char **);
//itoa



/* **************************       HANDLE STR        ************************ */

int		is_oneofthem(char c, char *set);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strstrhr(const char *s, char *set);
char	*ft_strndup(const char *s1, int size);



#endif
