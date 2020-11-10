/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f08_set_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:16:20 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/06 21:51:15 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_floor_ceiling_color(t_all *s)
{
	int x;
	int y;

	y = 0;
	while (y < s->height)
	{
		x = 0;
		while (x < s->width)
		{
			if (y > s->height / 2)
				s->buf[y][x] = s->tex.floor;
			else
				s->buf[y][x] = s->tex.ceiling;
			x++;
		}
		y++;
	}
}

void	set_wall_texture(t_player *player, t_ray *ray)
{
	if (ray->side == WEST || ray->side == EAST)
		ray->wall_x = player->y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = player->x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == EAST || ray->side == SOUTH)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
}

void	set_wall_color(t_all *s, t_ray *ray, int x)
{
	int	color;
	int	y;

	ray->step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - s->height / 2
					+ ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		color =
			s->tex.tile[ray->side][TEX_HEIGHT * ray->tex_y + ray->tex_x];
		s->buf[y][x] = color;
		y++;
	}
}
