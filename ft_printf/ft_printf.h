/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:19:33 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/13 00:25:45 by mihykim          ###   ########.fr       */
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

# define CONVERSION "cspdiuxX"
# define CHAR "cs"
# define PTR "p"
# define NUM "diu"
# define HEXA "xX"

# define FLAG "-+ #0"

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

typedef struct	s_data
{
	va_list		ap;
	int			printed;
}				t_data;

typedef struct	s_symbol
{
	char		letter;
	int			flag;
	int			min_width;
	int			precision;
	int			len_modifier;
	int			conversion;
}				t_symbol;


/* **************************          MAIN          ************************ */

int			ft_printf(const char *format, ...);



/* **************************          PRINT         ************************ */

int		ft_putchar(char c);
int		ft_putstr(char *s);
void		ft_putnbr_base(int n, char *base);



/* **************************          HELPER         ************************ */
int		is_oneofthem(char c, char *set);
int		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strstrhr(const char *s, char *set);
char		*ft_strndup(const char *s1, int size);


#endif
