/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f07_execute_raycasting_loop.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:13:52 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/06 21:51:06 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		execute_raycasting_loop(t_all *s)
{
	raycast_background(s);
	raycast_sprite(s, &s->player);
	render(s);
	return (0);
}

void	raycast_background(t_all *s)
{
	int x;

	x = 0;
	set_floor_ceiling_color(s);
	while (x < s->width)
	{
		init_raycasting(s, &s->player, &s->ray, x);
		calculate_step_direction(&s->player, &s->ray);
		perform_dda(s, &s->ray);
		calculate_wall_distance(&s->player, &s->ray);
		calculate_wall_height(s, &s->ray);
		set_wall_texture(&s->player, &s->ray);
		set_wall_color(s, &s->ray, x);
		s->z_buffer[x] = s->ray.perp_wall_dist;
		x++;
	}
}

void	raycast_sprite(t_all *s, t_player *player)
{
	int i;
	int stripe;

	i = 0;
	sort_sprite(s, player);
	while (i < s->num_sprite)
	{
		translate_sprite(s, player, &s->s_ray, i);
		calculate_sprite_height(s, &s->s_ray);
		calculate_sprite_width(s, &s->s_ray);
		stripe = s->s_ray.draw_start_x;
		while (stripe < s->s_ray.draw_end_x)
		{
			set_sprite_color(s, &s->s_ray, stripe);
			stripe++;
		}
		i++;
	}
}

void	render(t_all *s)
{
	int x;
	int y;

	y = 0;
	while (y < s->height)
	{
		x = 0;
		while (x < s->width)
		{
			s->img.data[s->width * y + x] = s->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
}
