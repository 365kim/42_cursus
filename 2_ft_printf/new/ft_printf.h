/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:19:33 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 18:43:28 by mihykim          ###   ########.fr       */
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

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# define LEN_MODIFIER "hl"
# define HH 44
# define LL 22
# define H 4
# define L 2

# define ENABLED 1
# define DISABLED -1
# define ERROR -1
# define UNDEFINED_BEHAVIOR -1
# define EQUAL 0
# define SKIP 0

typedef struct s_tag
{
	int		nbyte;
	int		left_aligned;
	int		width;
	int		prcs;
	int		zero_fill;
	int		plus;
	int		space;
	int		hexa;
	char	padding;
	char	sign;
}				t_tag;

typedef struct	s_box
{
	char *prcs;
	char *width;
}				t_box;

/*
typedef struct	s_tag
{
	int			plus;
	int			space;
	int			zero;
	int			hexa;
	int			len_mod;
	int			negative;
	char		filler;
	char		sign;
}				t_tag;
*/

/*
*****************************   MAIN FUNCTION   *******************************
*/

int		ft_printf(const char *format, ...);
int		parse_symbols(char **form, va_list ap, t_tag *tag);

/*
*****************************   WRITE ON CONDITION   ***********************
*/

int	write_char(va_list ap, t_tag *tag);
int	write_string(va_list ap, t_tag *tag);
int	write_int(va_list ap, t_tag *tag);
int	write_unsigned_int(va_list ap, t_tag *tag);
int	write_hexa(va_list ap, t_tag *tag, char conv);
int	write_pointer(va_list ap, t_tag *tag);
int	write_percent(t_tag *tag);

/*
*****************************   MANAGE BOX   ***********************************
*/

t_box	*prepare_box(void);
char	*fill_box(int size, char tag_padding);
void	free_box(t_box *box);
	
#endif
