/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f11_take_screenshot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:14:10 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/09 12:48:06 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	take_screenshot(t_all *s)
{
	int	fd;
	int	size;

	raycast_background(s);
	raycast_sprite(s, &s->player);
	size = 54 + 3 * s->width * s->height;
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 00755);
	if (fd < 0)
		ft_strexit("ERROR: Capture Failure!");
	write_bmp_header(s, fd, size);
	write_data(s, fd);
	ft_strexit("SAVE: Screenshot Saved Successfully!");
}

void	write_bmp_header(t_all *s, int fd, int size)
{
	unsigned char	header[54];

	ft_memset(header, 0, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	convert_int_to_char(header + 2, size);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	convert_int_to_char(header + 18, s->width);
	convert_int_to_char(header + 22, s->height);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

void	convert_int_to_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

void	write_data(t_all *s, int fd)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					pad;

	i = s->height;
	pad = (4 - (s->width * 3) % 4) % 4;
	while (i >= 0)
	{
		j = 0;
		while (j < s->width)
		{
			write(fd, &(s->buf[i][j]), 3);
			if (pad > 0)
				write(fd, &zero, pad);
			j++;
		}
		i--;
	}
}
