/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:50:48 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/07 03:11:32 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

/*
** - Reads the text available on a file descriptor, one line without newline.
** - Do not read whole file and then process each line.
** - File reading must be done only once.
** - Should try to read as little as possible each time get_next_line is called.
*/

static int		newline_is_here(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		handle_line(char **line, char **note)
{
	int		i;
	char	*tmp;

	i = newline_is_here(*note);
	if (i >= 0)
	{
		*line = ft_substr(*note, 0, i);
		tmp = ft_strdup(&((*note)[i + 1]));
		free(*note);
		*note = tmp;
		return (NL);
	}
	else
	{
		*line = ft_strdup(*note);
		free(*note);
		return (_EOF);
	}
}

static int		get_return_value(int fd, char **line, int read_byte, char **note)
{
	if (read_byte < 0)
		return (ERROR);
	return (handle_line(line, &note[fd]));
}

int		get_next_line(int fd, char **line)
{
	static char	*note[FD_MAX];
	static char	buff[BUFFER + 1];
	int			read_byte;
	char		*tmp_join;

	if (fd < 0 || line == NULL || BUFFER <= 0)
		return (ERROR);
	while ((read_byte = read(fd, buff, BUFFER)) > 0)
	{
		buff[read_byte] = 0;
		tmp_join = ft_strjoin(note[fd] == NULL ? "" : note[fd], buff);
		free(note[fd]);
		note[fd] = tmp_join;
		if (newline_is_here(note[fd]) >= 0)
			break;
	}
	return (get_return_value(fd, line, read_byte, note));
}
