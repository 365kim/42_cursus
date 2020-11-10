/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f04_rearrange_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:17:30 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/06 21:50:48 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rearrange_all(t_all *s)
{
	apply_player_orientation(s);
	s->mlx = mlx_init();
	allocate_buffer(s);
	load_texture(s);
	set_sprite(s);
	s->img.ptr = mlx_new_image(s->mlx, s->width, s->height);
	s->img.data = (int *)mlx_get_data_addr(s->img.ptr,
			&s->img.bpp, &s->img.size_l, &s->img.endian);
	return (1);
}

void	apply_player_orientation(t_all *s)
{
	int degree;

	degree = 0;
	if (s->player.dir == 'N')
		degree = 90;
	else if (s->player.dir == 'S')
		degree = 270;
	else if (s->player.dir == 'E')
		degree = 0;
	else if (s->player.dir == 'W')
		degree = 180;
	rotate_player(&s->player, degree * (PI / 180));
}

void	allocate_buffer(t_all *s)
{
	int i;

	if (!(s->buf = ft_calloc(s->height, sizeof(int **))))
		ft_strexit("ERROR: Malloc Fail!");
	i = 0;
	while (i < s->height)
	{
		if (!(s->buf[i] = ft_calloc(s->width, sizeof(int *))))
			ft_strexit("ERROR: Malloc Fail!");
		i++;
	}
	if (!(s->z_buffer = ft_calloc(s->width, sizeof(double *))))
		ft_strexit("ERROR: Malloc Fail!");
}

void	load_texture(t_all *s)
{
	t_img	img;

	load_image(s, s->tex.tile[WEST], s->tex.path[WEST], &img);
	free(s->tex.path[WEST]);
	load_image(s, s->tex.tile[EAST], s->tex.path[EAST], &img);
	free(s->tex.path[EAST]);
	load_image(s, s->tex.tile[SOUTH], s->tex.path[SOUTH], &img);
	free(s->tex.path[SOUTH]);
	load_image(s, s->tex.tile[NORTH], s->tex.path[NORTH], &img);
	free(s->tex.path[NORTH]);
	load_image(s, s->tex.tile[SPR], s->tex.path[SPR], &img);
	free(s->tex.path[SPR]);
}

void	load_image(t_all *s, int *texture, char *path, t_img *img)
{
	int		x;
	int		y;

	img->ptr = mlx_xpm_file_to_image(s->mlx, path, &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(
						img->ptr, &img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			texture[img->width * y + x] =
							img->data[img->width * y + (img->width - x - 1)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(s->mlx, img->ptr);
}
