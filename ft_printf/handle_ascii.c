/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:15:28 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/13 15:32:15 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char **str)
{
	int		atoi;

	atoi = 0;
	if (!is_oneofthem(**str, DIGIT))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		atoi = atoi * 10 + (**str - '0');
		(*str)++;
	}
	return (atoi);
}
