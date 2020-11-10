/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f10_raycast_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:15:10 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/06 21:51:40 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	translate_sprite(t_all *s, t_player *player, t_spr_ray *s_ray, int i)
{
	double v_mode;

	v_mode = 0.0;
	s_ray->x = s->sprite[i].x - player->x;
	s_ray->y = s->sprite[i].y - player->y;
	s_ray->inversion_detection = 1.0 /
		(player->plane_x * player->dir_y - player->dir_x * player->plane_y);
	s_ray->transform_x = s_ray->inversion_detection *
		(player->dir_y * s_ray->x - player->dir_x * s_ray->y);
	s_ray->transform_y = s_ray->inversion_detection *
		(-player->plane_y * s_ray->x + player->plane_x * s_ray->y);
	s_ray->screen_x = (int)((s->width / 2) *
						(1 - s_ray->transform_x / s_ray->transform_y));
	s_ray->v_move_screen = (int)(v_mode / s_ray->transform_y);
}

void	calculate_sprite_height(t_all *s, t_spr_ray *s_ray)
{
	int v_div;

	v_div = 1;
	s_ray->height = (int)fabs((s->height / s_ray->transform_y) / v_div);
	s_ray->draw_start_y =
		-s_ray->height / 2 + s->height / 2 + s_ray->v_move_screen;
	if (s_ray->draw_start_y < 0)
		s_ray->draw_start_y = 0;
	s_ray->draw_end_y =
		s_ray->height / 2 + s->height / 2 + s_ray->v_move_screen;
	if (s_ray->draw_end_y >= s->height)
		s_ray->draw_end_y = s->height - 1;
}

void	calculate_sprite_width(t_all *s, t_spr_ray *s_ray)
{
	int u_div;

	u_div = 1;
	s_ray->width = (int)fabs((s->height / s_ray->transform_y) / u_div);
	s_ray->draw_start_x = -s_ray->width / 2 + s_ray->screen_x;
	if (s_ray->draw_start_x < 0)
		s_ray->draw_start_x = 0;
	s_ray->draw_end_x = s_ray->width / 2 + s_ray->screen_x;
	if (s_ray->draw_end_x >= s->width)
		s_ray->draw_end_x = s->width - 1;
}
