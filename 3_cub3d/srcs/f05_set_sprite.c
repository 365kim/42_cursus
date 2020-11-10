/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f05_set_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:14:56 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/09 14:43:26 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite(t_all *s)
{
	int x;
	int y;
	int i;

	i = 0;
	if (!(s->sprite = malloc(sizeof(t_spr) * s->num_sprite)))
		ft_strexit("ERROR: Malloc Fail!");
	y = 0;
	while (y < s->map_height)
	{
		x = 0;
		while (x < s->map_width)
		{
			if (s->map[y][x] == '2')
			{
				set_pos_sprite(s, i, x, y);
				i++;
			}
			x++;
		}
		y++;
	}
}

void	set_pos_sprite(t_all *s, int i, int x, int y)
{
	s->sprite[i].x = 0.5f + x;
	s->sprite[i].y = 0.5f + y;
}

void	sort_sprite(t_all *s, t_player *player)
{
	int i;

	i = 0;
	while (i < s->num_sprite)
	{
		s->sprite[i].distance =
			((player->x - s->sprite[i].x) * (player->x - s->sprite[i].x)
			+ (player->y - s->sprite[i].y) * (player->y - s->sprite[i].y));
		i++;
	}
	sort(s);
}

void	sort(t_all *s)
{
	int		i;
	int		j;
	int		max;
	t_spr	temp;

	i = 0;
	max = 0;
	while (i < s->num_sprite - 1)
	{
		max = i;
		j = i + 1;
		while (j < s->num_sprite)
		{
			if (s->sprite[j].distance > s->sprite[i].distance)
				max = j;
			j++;
		}
		if (i != max)
		{
			temp = s->sprite[i];
			s->sprite[i] = s->sprite[max];
			s->sprite[max] = temp;
		}
		i++;
	}
}

void	set_sprite_color(t_all *s, t_spr_ray *s_ray, int stripe)
{
	int y;
	int draw;
	int color;

	s_ray->tex_x =
		(int)((256 * (stripe - (-s_ray->width / 2 + s_ray->screen_x)) *
			TEX_WIDTH / s_ray->width) / 256);
	if (s_ray->transform_y > 0 && stripe > 0 &&
		stripe < s->width && s_ray->transform_y < s->z_buffer[stripe])
	{
		y = s_ray->draw_start_y;
		while (y < s_ray->draw_end_y)
		{
			draw = (y - s_ray->v_move_screen) * 256 -
					s->height * 128 + s_ray->height * 128;
			s_ray->tex_y = ((draw * TEX_HEIGHT) / s_ray->height) / 256;
			color = s->tex.tile[SPR][TEX_WIDTH * s_ray->tex_y + s_ray->tex_x];
			if ((color & 0x00FFFFFF) != 0)
				s->buf[y][stripe] = color;
			y++;
		}
	}
}
