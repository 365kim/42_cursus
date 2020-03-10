/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:50:48 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/11 06:05:08 by mihykim          ###   ########.fr       */
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

static int		handle_line(char **line, char **note, char *nl_here)
{
	char	*tmp;

	if (nl_here != NULL)
	{
		*line = ft_strndup(*note, nl_here - *note);
		tmp = ft_strndup(nl_here + 1, ft_strlen(nl_here + 1));
		free(*note);
		*note = tmp;
		return (NL);
	}
	if (*note != 0)
	{
		*line = *note;
		*note = 0;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

int		get_next_line(int fd, char **line)
{
	static char	*note[OPEN_MAX];
	static char	buff[BUFFER + 1];
	int			byte;
	char		*tmp;
	char		*nl_here;;

	if (fd < 0 || line == NULL || BUFFER <= 0)
		return (ERROR);
	nl_here = NULL;
	while ((byte = read(fd, buff, BUFFER)) > 0)
	{
		buff[byte] = 0;
		tmp = note[fd] == 0 ? ft_strndup(buff, byte) : ft_strjoin(note[fd], buff);
		if(note[fd] != 0)
			free(note[fd]);
		note[fd] = tmp;
		if ((nl_here = ft_strchr(note[fd], '\n')) != 0)
			break;
	}
	if (byte < 0)
		return (ERROR);
	return (handle_line(line, &note[fd], nl_here));
}
