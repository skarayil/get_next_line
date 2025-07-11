/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 05:33:27 by skarayil          #+#    #+#             */
/*   Updated: 2025/07/11 05:53:58 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_check(int fd, char *buff, char **line)
{
	ssize_t	r;

	r = read(fd, buff, BUFFER_SIZE);
	if (r == -1)
	{
		buff[0] = '\0';
		free(*line);
		*line = NULL;
		return (-1);
	}
	buff[r] = '\0';
	return (r);
}

static int	ft_process_buffer(char **line, char *buff)
{
	char	*newline;
	size_t	len;

	newline = ft_string_char(buff, '\n');
	if (newline)
	{
		len = newline - buff + 1;
		if (!ft_append_memory(line, buff, len))
			return (-1);
		ft_memory_move(buff, buff + len, ft_string_length(buff + len) + 1);
		return (1);
	}
	if (*buff)
	{
		if (!ft_append_memory(line, buff, ft_string_length(buff)))
			return (-1);
		buff[0] = '\0';
	}
	return (0);
}

static int	ft_process_check(char **line, char *buff)
{
	int	process;

	process = ft_process_buffer(line, buff);
	if (process == 1)
		return (1);
	if (process == -1)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		buff[0] = '\0';
		return (-1);
	}
	return (0);
}

static char	*ft_end_of_file(char **line)
{
	if (*line && **line != '\0')
		return (*line);
	free(*line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			process;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (42)
	{
		process = ft_process_check(&line, buff[fd]);
		if (process == 1)
			return (line);
		if (process == -1)
			return (NULL);
		r = ft_read_check(fd, buff[fd], &line);
		if (r == -1)
			return (NULL);
		if (r == 0)
			return (ft_end_of_file(&line));
	}
}
