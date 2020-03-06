/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:50:48 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/05 16:20:13 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** - Reads the text available on a file descriptor, one line without newline.
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
	if (i > 0)
	{
		*line = ft_substr(*note, 0, i); //ㄱㅐ행까지 라인에다가 복사
		tmp_join = ft_strdup(&((*note)[i + 1])); //개행 다음부터 통째로 복사
		*note = tmp_join;
		free(tmp_join);
	}
	else
	{
		*line = ft_strdup(*note);
		free(*note);
	}
}

int		get_return_value(int fd, char **line, int read_byte, char **note)
{
	if (read_byte < 0)
		return (ERROR);
	else if (read_byte == 0)
	{
		*line = ft_strdup(*note);
		free(*note);
		return (EoF);
	}
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
		if (note[fd] == 0) // fd = 3에서 처음 쓰는 거라면
			note[fd] = ft_strdup(buff);
		else /// 이미 fd = 3에서 읽어서 note[fd]에 저장한 내용이 있으면
		{
			tmp_join = ft_strjoin(note[fd], buff);
			free(note[fd]);
			note[fd] = tmp_join;
		}
		if (newline_is_here(note[fd]) >= 0)
			break;
	}
	return (get_return_value(fd, line, read_byte, note));
}
