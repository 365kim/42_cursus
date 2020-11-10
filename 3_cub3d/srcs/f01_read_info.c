/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f01_read_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:21:44 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/09 14:44:03 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_info(t_all *s)
{
	char	*line;
	int		flag;
	char	**info;

	while (get_next_line(s->fd, &line) > 0)
	{
		if (line[0] == EMPTY_LINE)
			continue;
		info = ft_split(line, ' ');
		if (!info)
			ft_strexit("ERROR: Split Fail!");
		flag = decide_what_to_store(s, info);
		ft_free_2d(info);
		if (flag == MAP_START)
			break ;
		free(line);
	}
	s->line = line;
}

int		decide_what_to_store(t_all *s, char **info)
{
	if (ft_strcmp(info[0], "R") == 0)
		store_resolution(s, info[1], info[2]);
	else if (ft_strcmp(info[0], "NO") == 0)
		store_texture(s, info[1], NORTH);
	else if (ft_strcmp(info[0], "SO") == 0)
		store_texture(s, info[1], SOUTH);
	else if (ft_strcmp(info[0], "WE") == 0)
		store_texture(s, info[1], WEST);
	else if (ft_strcmp(info[0], "EA") == 0)
		store_texture(s, info[1], EAST);
	else if (ft_strcmp(info[0], "S") == 0)
		store_texture(s, info[1], SPR);
	else if (ft_strcmp(info[0], "F") == 0)
		store_color(s, info[1], FLOOR);
	else if (ft_strcmp(info[0], "C") == 0)
		store_color(s, info[1], CEILING);
	else
		return (MAP_START);
	return (0);
}

void	store_resolution(t_all *s, char *width, char *height)
{
	if (!width || !height)
		ft_strexit("ERROR: Missing Resolution Info");
	if (!ft_only_digit(width) || !ft_only_digit(height))
		ft_strexit("ERROR: Not A Number Given As Resolution Info");
	s->width = ft_atoi(width);
	s->height = ft_atoi(height);
	s->width = s->width > 1920 ? 1920 : s->width;
	s->width = s->width < 848 ? 848 : s->width;
	s->height = s->height > 1080 ? 1080 : s->height;
	s->height = s->height < 480 ? 480 : s->height;
}

void	store_texture(t_all *s, char *xpm_path, int flag)
{
	int		fd;

	if (!xpm_path || !ft_isformat(xpm_path, ".xpm"))
		ft_strexit("ERROR: Path To XPM Needed!");
	fd = open(xpm_path, O_RDONLY);
	if (fd == -1)
		ft_strexit("ERROR: No Such XPM Available!");
	close(fd);
	s->tex.path[flag] = ft_strdup(xpm_path);
}

void	store_color(t_all *s, char *rgb_with_comma, int flag)
{
	char	**rgb;
	int		hex;
	int		temp;
	int		i;

	if (!(rgb = ft_split(rgb_with_comma, ',')))
		ft_strexit("ERROR: Split Fail!");
	i = 0;
	hex = 0;
	while (i < 3)
	{
		if (!rgb[i] || !ft_only_digit(rgb[i]))
			ft_strexit("ERROR: RGB Info Incomplete!");
		temp = ft_atoi(rgb[i]);
		if (temp > 255 || temp < 0)
			ft_strexit("ERROR: RGB Range Invalid!");
		hex = hex * 256 + temp;
		i++;
	}
	if (flag == FLOOR)
		s->tex.floor = hex;
	else if (flag == CEILING)
		s->tex.ceiling = hex;
	ft_free_2d(rgb);
}
