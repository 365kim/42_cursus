/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 02:06:16 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/15 15:09:08 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_n(char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
		i += ft_putchar(c);
	return (n);
}

int		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

void	print_nbase(long my_nbr, long size, char *base)
{
	int		i;
	char	converted[50];

	i = 0;
	while (my_nbr != 0)
	{
		converted[i] = base[my_nbr % size];
		my_nbr = my_nbr / size;
		i++;
	}
	while (i > 0)
	{
		write(1, &converted[i - 1], 1);
		i--;
	}
}

void	ft_putnbr_base(long nbr, char *base)
{
	long	size;
	long	my_nbr;

	size = ft_strlen(base);
	if (!size)
		return ;
	my_nbr = (long)nbr;
	if (my_nbr == 0)
	{
		write(1, &base[0], 1);
	}
	else if (my_nbr < 0)
	{
		my_nbr = (long)UINT_MAX + 1 + my_nbr;
		print_nbase(my_nbr, size, base);
	}
	else
		print_nbase(my_nbr, size, base);
}
