/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 22:36:06 by skarayil          #+#    #+#             */
/*   Updated: 2025/07/11 04:44:19 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_string_char(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_string_length(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memory_copy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest || !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if ((d > s && d < s + n) || (s > d && s < d + n))
		return (ft_memory_move(dest, src, n));
	index = 0;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (dest);
}

void	*ft_memory_move(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (!dest || !src)
		return (NULL);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}

int	ft_append_memory(char **dest, const char *src, size_t src_len)
{
	size_t	dest_len;
	char	*temp;

	if (!dest || !src)
		return (0);
	if (*dest)
		dest_len = ft_string_length(*dest);
	else
		dest_len = 0;
	temp = malloc(dest_len + src_len + 1);
	if (!temp)
		return (0);
	if (*dest)
		ft_memory_copy(temp, *dest, dest_len);
	ft_memory_copy(temp + dest_len, src, src_len);
	temp[dest_len + src_len] = '\0';
	free(*dest);
	*dest = temp;
	return (1);
}
