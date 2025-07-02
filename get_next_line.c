/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:01:54 by skarayil          #+#    #+#             */
/*   Updated: 2025/07/02 21:19:07 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_save_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = (NULL);
	}
	return (NULL);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*temp_buffer;
	char	*read_buffer;
	int		bytes_read;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (ft_save_free(&buffer));
	bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(read_buffer);
		if (bytes_read == 0)
			return (buffer);
		return (ft_save_free(&buffer));
	}
	read_buffer[bytes_read] = '\0';
	temp_buffer = ft_join_strings(buffer, read_buffer);
	ft_save_free(&buffer);
	free(read_buffer);
	return (temp_buffer);
}

static char	*ft_extract_line(char **buffer)
{
	char	*line;
	char	*data;
	char	*pos;

	pos = ft_find_character(*buffer, '\n');
	if (pos)
	{
		line = ft_create_substr(*buffer, 0, pos - *buffer + 1);
		data = ft_duplicate_string(pos + 1);
		ft_save_free(buffer);
		*buffer = data;
	}
	else
	{
		line = ft_duplicate_string(*buffer);
		ft_save_free(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_duplicate_string("");
	if (!stash)
		return (NULL);
	while (!ft_find_character(stash, '\n'))
	{
		stash = ft_read_file(fd, stash);
		if (!stash)
			return (NULL);
		if (!*stash)
			break ;
	}
	if (!*stash)
	{
		ft_save_free(&stash);
		return (NULL);
	}
	line = ft_extract_line(&stash);
	return (line);
}
