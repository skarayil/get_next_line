/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:02:47 by skarayil          #+#    #+#             */
/*   Updated: 2025/07/03 13:16:49 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_string_length(const char *s)
{
	size_t	len;
	if (s == NULL)
	{
		return (0);
	}
	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len); 
}

char	*ft_find_character(const char *s, int c)
{
	while (*s && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_save_free(char *buffer, char *temp)
{
	if (buffer)
		free(buffer);
	if (temp)
		free(temp);
	return (NULL);
}

char	*ft_join_strings(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	res = malloc(sizeof(char) * (ft_string_length(s1) + ft_string_length(s2) + 1));
	if (res == NULL)
		return (ft_save_free((char *)s1, NULL));
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	ft_save_free((char *)s1, NULL);
	return (res);
}
