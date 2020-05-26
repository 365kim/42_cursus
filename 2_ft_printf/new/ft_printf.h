/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:19:33 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/26 17:55:51 by mihykim          ###   ########.fr       */
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
# define LEN_MODIFIER "hl"
# define CONVERSION "cspdiuxXn%"

# define DIGIT "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

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
	int		len_mod;
	char	padding;
	char	sign;
}				t_tag;

typedef struct	s_box
{
	char *prcs;
	char *width;
}				t_box;

typedef struct s_ptr
{
	long long *llptr;
	long *lptr;
	signed char *cptr;
	short int *sptr;
	int			*iptr;
}				t_ptr;

/*
*****************************   MAIN FUNCTION   *******************************
*/

int		ft_printf(const char *format, ...);
int		parse_symbols(char **form, va_list ap, t_tag *tag);

/*
*****************************   WRITE ON CONDITION   ***********************
*/

int	pre_process_char(va_list ap, t_tag *tag);
int pre_process_string(va_list ap, t_tag *tag);
int pre_process_int(va_list ap, t_tag *tag);
int pre_process_unsigned_int(va_list ap, t_tag *tag);
int pre_process_hexa(va_list ap, t_tag *tag, char *base);

int	print_char(t_tag *tag, char c);
int	print_string(t_tag *tag, char *res);
int	print_int(t_tag *tag, char *res);
int	print_unsigned_int(t_tag *tag, char *res);
int	print_hexa(t_tag *tag, char *res);
int	print_pointer(va_list ap, t_tag *tag);
int	print_percent(t_tag *tag);
int	store_nbyte(va_list ap, t_tag *tag);

/*
*****************************   MANAGE BOX   ***********************************
*/

t_box	*prepare_box(void);
char	*fill_box(int size, char tag_padding);
void	free_box(t_box *box);

/*
*****************************   MANAGE SIGN   ***********************************
*/
char 	*prepare_sign(t_tag *tag, char *s);
char	*process_sign(t_tag *tag, char *box, int s_len);


#endif
