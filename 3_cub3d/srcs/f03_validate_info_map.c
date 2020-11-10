/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f03_validate_map_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:18:47 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/10 15:41:22 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_info(t_all *s)
{
	if (!s->width || !s->height)
		ft_strexit("ERROR: Resolution Info Missing");
	if (!s->tex.path[NORTH] || !s->tex.path[SOUTH]
		|| !s->tex.path[WEST] || !s->tex.path[EAST]
		|| !s->tex.path[SPR]
		|| s->tex.floor == -1 || s->tex.ceiling == -1)
		ft_strexit("ERROR: Texture Info Missing");
}

void	validate_map(t_all *s)
{
	if (!s->map_width || !s->map_height)
		ft_strexit("ERROR: Invalid Map Parsing");
	if (s->player.dir == '\0')
		ft_strexit("ERROR: No Player Position Given!");
	validate_map_horizontal(s->map, s->map_width, s->map_height);
	validate_map_vertical(s->map, s->map_width, s->map_height);
}

void	validate_map_horizontal(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != ' ' && map[y][0] != WALL)
			ft_strexit("ERROR: Map Not Surronded By Walls! (Left Side)");
		x = 1;
		while (x < width)
		{
			while (x < width && map[y][x] == ' ')
				x++;
			if (x == width)
				break ;
			if (map[y][x - 1] == ' ' && map[y][x] != WALL)
				ft_strexit("ERROR: Map Not Surronded By Walls! (Left Side)");
			while (x < width && map[y][x] != ' ')
				x++;
			if (map[y][x - 1] != WALL)
				ft_strexit("ERROR: Map Not Surronded By Walls! (Right Side)");
		}
		y++;
	}
}

void	validate_map_vertical(char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != ' ' && map[0][x] != WALL)
			ft_strexit("ERROR: Map Not Surronded By Walls! (Upper Side)");
		y = 1;
		while (y < height)
		{
			while (y < height && map[y][x] == ' ')
				y++;
			if (y == height)
				break ;
			if (map[y - 1][x] == ' ' && map[y][x] != WALL)
				ft_strexit("ERROR: Map Not Surronded By Walls! (Upper Side)");
			while (y < height && map[y][x] != ' ')
				y++;
			if (map[y - 1][x] != WALL)
				ft_strexit("ERROR: Map Not Surronded By Walls! (Bottom Side)");
		}
		x++;
	}
}
