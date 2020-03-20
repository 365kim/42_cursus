/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:21:33 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/20 22:12:09 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define DIGIT "0123456789"

# define TRUE 1
# define FALSE 0

# define MAX(a, b)	(((a) > (b)) ? (a) : (b))
# define MIN(a, b)	(((a) < (b)) ? (a) : (b))


/* ************************************************************************** */
/*                                 HANDLE ASCII                               */
/* ************************************************************************** */

int		ft_atoi(char **);
int		get_itoa_width(long n);
int		get_itoa_base_width(int n, long size);



/* ************************************************************************** */
/*                                 HANDLE STR                                 */
/* ************************************************************************** */

int		is_set(char c, char *set);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strstrhr(const char *s, char *set);
char	*ft_strndup(const char *s1, int size);



/* ************************************************************************** */
/*                                 HELP WRITING                               */
/* ************************************************************************** */

int		ft_putchar(char c);
int		ft_putchar_n(char c, int n);
int		ft_putstr(char *s);
void	ft_putnbr_base(long n, char *base);


#endif
