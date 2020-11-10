/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:51:32 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/09 14:43:43 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_all	s;
	int		save;

	check_save_option(argc, argv[2], &save);
	init_all(&s);
	open_cub(argv[1], &s);
	read_info(&s);
	validate_info(&s);
	read_map(&s, s.line);
	validate_map(&s);
	rearrange_all(&s);
	if (save == OFF)
		run_program(&s);
	else
		take_screenshot(&s);
	return (0);
}

void	check_save_option(int argc, char *option, int *save)
{
	if (argc > 3)
		ft_strexit("ERROR: Too Many Arguments Given!");
	if (argc < 2)
		ft_strexit("ERROR: Too Few Arguments Given!");
	if (argc == 2)
		*save = OFF;
	else if (ft_strcmp(option, "--save") == 0)
		*save = ON;
	else
		ft_strexit("ERROR: Invalid Argument Given!");
}

void	init_all(t_all *s)
{
	s->width = 0;
	s->height = 0;
	ft_memset(s->tex.path, 0, 6);
	s->tex.floor = -1;
	s->tex.ceiling = -1;
	s->map = NULL;
	s->map_width = 0;
	s->map_height = 0;
	s->player.dir = '\0';
	s->sprite = NULL;
	s->num_sprite = 0;
	s->buf = NULL;
	s->z_buffer = NULL;
}

void	open_cub(char *file_name, t_all *s)
{
	if (!ft_isformat(file_name, ".cub"))
		ft_strexit("ERROR: CUB File Needed!");
	s->fd = open(file_name, O_RDONLY);
	if (s->fd == -1)
		ft_strexit("ERROR: No Such CUB File Available!");
}
