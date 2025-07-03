/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:01:54 by skarayil          #+#    #+#             */
/*   Updated: 2025/07/03 13:08:40 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_buffer(char *buf)
{
	char	*new;
	size_t	len[2] = {0, 0};

	if (!buf)
		return (NULL);
	while (buf[len[0]] && buf[len[0]] != '\n')
		len[0]++;
	len[0] += (buf[len[0]] == '\n');
	if (!buf[len[0]])
		return (free(buf), NULL);
	while (buf[len[0] + len[1]])
		len[1]++;
	new = malloc(len[1] + 1);
	if (!new)
		return (free(buf), NULL);
	len[1] = 0;
	while (buf[len[0] + len[1]])
	{
		new[len[1]] = buf[len[0] + len[1]];
		len[1]++;
	}
	new[len[1]] = '\0';
	free(buf);
	return (new);
}

static char	*ft_extract_line(char *buf)
{
	char	*line;
	size_t	line_end;
	size_t	i;

	if (!buf || !*buf)
		return (NULL);
	line_end = 0;
	while (buf[line_end] && buf[line_end] != '\n')
		line_end++;
	line_end += (buf[line_end] == '\n');
	line = (char *)malloc(line_end + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_end)
	{
		line[i] = buf[i];
		i++;
	}
	line[line_end] = '\0';
	return (line);
}

static char	*ft_read_line(int fd, char *buffer)
{
	char			*temp;
	ssize_t			bytes;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	*temp = '\0';
	if (!temp)
		return (ft_save_free(buffer, NULL));
	bytes = 1;
	while (bytes != 0 && (!ft_find_character(temp, '\n')))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_save_free(buffer, temp));
		temp[bytes] = '\0';
		buffer = ft_join_strings(buffer, temp);
		if (!buffer)
			return (ft_save_free(NULL, temp));
	}
	buffer[ft_string_length(buffer)] = '\0';
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*buffbuff;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	buffbuff = buffer;
	next_line = ft_extract_line(buffbuff);
	if (!next_line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_extract_buffer(buffer);
	return (next_line);
}
