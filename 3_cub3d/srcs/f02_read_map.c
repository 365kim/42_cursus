/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f02_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:51:27 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/09 13:01:15 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(t_all *s, char *line)
{
	s->lst = ft_lstnew(ft_strdup(line));
	free(line);
	while (get_next_line(s->fd, &line) > 0)
	{
		if (line[0] == EMPTY_LINE)
			break ;
		ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	free(line);
	allocate_map(s, s->lst);
	store_map_as_array(s, s->lst);
	ft_lstclear(&(s->lst), free);
}

void	allocate_map(t_all *s, t_list *curr)
{
	int		i;
	int		j;

	s->map_height = ft_lstsize(curr);
	s->map_width = ft_longest_node_len(curr);
	if (!(s->map = malloc(sizeof(char *) * (s->map_height + 1))))
		ft_strexit("ERROR: Malloc Fail!");
	s->map[s->map_height] = NULL;
	i = 0;
	while (curr)
	{
		if (!(s->map[i] = malloc(sizeof(char) * (s->map_width + 1))))
			ft_strexit("ERROR: Malloc Fail!");
		j = 0;
		while (j < s->map_width)
		{
			s->map[i][j] = ' ';
			j++;
		}
		s->map[i][s->map_width] = '\0';
		i++;
		curr = curr->next;
	}
}

void	store_map_as_array(t_all *s, t_list *curr)
{
	int		i;
	int		j;
	char	*content;

	i = 0;
	while (i < s->map_height)
	{
		j = 0;
		content = (char *)curr->content;
		while (j < ft_strlen(content))
		{
			if (!ft_isset(content[j], "NSWE012 \n") && content[j] != '\0')
				ft_strexit("ERROR: Invalid Map Element Contained!");
			s->map[i][j] = content[j];
			if (ft_isset(content[j], "NSWE"))
				create_player(s, i, j);
			else if (content[j] == SPRITE)
				s->num_sprite++;
			j++;
		}
		curr = curr->next;
		i++;
	}
}

void	create_player(t_all *s, int i, int j)
{
	if (s->player.dir)
		ft_strexit("ERROR: Multiple Player Postions Given!");
	s->player.dir = s->map[i][j];
	s->player.x = 2;
	s->player.y = 5;
	s->player.dir_x = -1.0;
	s->player.dir_y = 0.0;
	s->player.plane_x = 0.0;
	s->player.plane_y = 0.66;
	s->player.move_speed = 0.07;
	s->player.rot_speed = 0.08;
	s->player.x = 0.5f + j;
	s->player.y = 0.5f + i;
}
