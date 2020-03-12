/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 23:04:02 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/13 00:24:48 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
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

long	ft_error_handling(char *base)
{
	long	i;
	long	j;
	long	size;

	size = 0;
	while (base[size] != '\0')
	{
		if (base[size] == '+' || base[size] == '-')
			return (0);
		size++;
	}
	if (base[0] == '\0' || size == 1)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (size);
}

/*
** line 74-77 : added condition when "nbr" is NULL
*/

void	ft_putnbr_base(int nbr, char *base)
{
	long	size;
	long	my_nbr;

	size = ft_error_handling(base);
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

/*
** line 80 : Return ffffffff(UINT_MAX), when nbr is -1
** line 80 : cast to (long) to avoid printing shortened result(0x0f)
*/
