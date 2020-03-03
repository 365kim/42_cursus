/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:50:48 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/03 09:30:58 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "'get_next_line.h"

/*
** - Reads the text available on a file descriptor, one line without newline.
** - Do not read whole file and then process each line
** - File reading must be done only once
** - Should try to read as little as possible each time get_next_line is called
** - Returns '1' when a line has been read,
**   '0' when EOF has been reached,
**   '-1' when an error happened
*/

void	split(char buff, char **line)
{
	int		check[2];
	has_NL_or_EOF(buff, check);
	if (check[1] == NL)
	{
		if (check[0] < BUFFERSIZE)
		{
			*line = malloc(i + 1);
			ft_strlcpy(*line, buff, i + 1);
			(*line)++;

				ft_strlcpy(*line, buff + i, BUFFERSZIE - i + 1);
				free(buff);
			}
			else
				*line = buff;
			line++;
}

int		get_next_line(int fd, char **line)
{
	char	*buff[BUFF_SIZE + 1];
	int		n_read;

	if (fd < 0 || line == 0 || BUFFERSIZE == 0)
		return (ERROR);

	while (1)
	{

		n_read = read(fd, buff, BUFFER_SIZE);
		buff[n_read] = 0;
		if
		split(buff);
			return (NL);
		}
		else if (check[1] == EoF)
		{
			return (EoF);
		}
	}
	return (ERROR);
}
