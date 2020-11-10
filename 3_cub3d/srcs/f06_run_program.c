/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f06_run_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:16:57 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/09 13:04:04 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_program(t_all *s)
{
	s->win = mlx_new_window(s->mlx, s->width, s->height, TITLE);
	mlx_hook(s->win, X_EVENT_KEY_PRESS, 0, detect_keypress, s);
	mlx_loop_hook(s->mlx, execute_raycasting_loop, s);
	mlx_loop(s->mlx);
}

int		detect_keypress(int key, t_all *s)
{
	if (key == KEY_W || key == KEY_UP)
		move_back_forth(s, &s->player, s->player.move_speed);
	if (key == KEY_S || key == KEY_DOWN)
		move_back_forth(s, &s->player, -s->player.move_speed);
	if (key == KEY_A)
		move_left_right(s, &s->player, s->player.move_speed);
	if (key == KEY_D)
		move_left_right(s, &s->player, -s->player.move_speed);
	if (key == KEY_LEFT)
		rotate_player(&s->player, -s->player.rot_speed);
	if (key == KEY_RIGHT)
		rotate_player(&s->player, s->player.rot_speed);
	if (key == KEY_ESC)
		ft_strexit("KEY_ESC_PRESSED: Exit Successfully!");
	return (0);
}

void	move_back_forth(t_all *s, t_player *player, double move_speed)
{
	char x;
	char y;

	x = s->map[(int)player->y][(int)(player->x + player->dir_x * move_speed)];
	y = s->map[(int)(player->y + player->dir_y * move_speed)][(int)player->x];
	if (x != WALL && ((sqrt(pow(s->s_ray.x, 2) + pow(s->s_ray.y, 2)) >= 0.2)))
		player->x += player->dir_x * move_speed;
	if (y != WALL)
		player->y += player->dir_y * move_speed;
}

void	move_left_right(t_all *s, t_player *player, double move_speed)
{
	char x;
	char y;

	x = s->map[(int)player->y][(int)(player->x + player->dir_y * move_speed)];
	y = s->map[(int)(player->y + -player->dir_x * move_speed)][(int)player->x];
	if (x != WALL)
		player->x += player->dir_y * move_speed;
	if (y != WALL)
		player->y += -player->dir_x * move_speed;
}

void	rotate_player(t_player *player, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)
					- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed)
					+ player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
					- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)
					+ player->plane_y * cos(rot_speed);
}
