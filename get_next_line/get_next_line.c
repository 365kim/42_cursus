/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:50:48 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/07 00:33:53 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

/*
** - Reads the text available on a file descriptor, one line without NEWLINE.
** - Do not read whole file and then process each line.
** - File reading must be done only once.
** - Should try to read as little as possible each time get_next_line is called.
*/

int		newline_is_here(char *s)
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

void	handle_line(char **line, char **note)
{
	int		i;
	char	*tmp_join;

	i = newline_is_here(*note);
	if (i >= 0)
	{
		*line = ft_substr(*note, 0, i);
		tmp_join = ft_strdup(&((*note)[i + 1]));
//		free(*note);
		printf("%s\n", *note);
		*note = tmp_join;
//		free(tmp_join);
	}
	else
	{
		printf("handle line 1\n");
		*line = ft_strdup(*note);
		printf("handle line 2\n");
//		free(*note);
		printf("handle line 3\n");
	}
}

int		get_return_value(int fd, char **line, int read_byte, char **note)
{
	if (read_byte < 0)
		return (ERROR);
	else if (read_byte == 0)
		return (EoF);
	else
	{
		handle_line(line, &note[fd]);
		return (NL);
	}
}

int		get_next_line(int fd, char **line)
{
	char	*note[FD_MAX];
	char	buff[BUFFER + 1];
	int		read_byte;
	char	*tmp_join;

	if (fd < 0 || line == 0 || BUFFER <= 0)
		return (ERROR);
	while ((read_byte = read(fd, buff, BUFFER)) > 0)
	{
		buff[read_byte] = 0;
		if (note[fd] == 0)
			note[fd] = ft_strdup(buff);
		else
		{
			tmp_join = ft_strjoin(note[fd], buff);
//			free(note[fd]);
			note[fd] = tmp_join;
		}
		if (newline_is_here(note[fd]) >= 0)
			break;
	}
	return (get_return_value(fd, line, read_byte, note));
}
