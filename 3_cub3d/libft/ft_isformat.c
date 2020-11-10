/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:25:21 by mihykim           #+#    #+#             */
/*   Updated: 2020/10/31 14:41:55 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isformat(char *str, char *format)
{
	int		len_str;
	int		len_fmt;
	char	*fmt_of_str;

	len_str = ft_strlen(str);
	len_fmt = ft_strlen(format);
	if (len_str <= len_fmt)
		return (0);
	fmt_of_str = str + len_str - len_fmt;
	if (ft_strcmp(fmt_of_str, format) == 0)
		return (1);
	return (0);
}
