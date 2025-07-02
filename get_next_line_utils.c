/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:02:47 by skarayil          #+#    #+#             */
/*   Updated: 2025/07/02 21:11:55 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_string_length(const char *str)
{
	const char	*len = str;

	while (*str)
		str++;
	return (str - len);
}

char	*ft_find_character(const char *str, int c)
{
    while (*str)
    {
        if (*str == (char)c)
            return ((char *)str);
        str++;
    }
    return (NULL);
}

char	*ft_join_strings(char *s1, char *s2)
{
	size_t	len;
	char	*ptr;
	char	*total;

    if (!s1 && !s2)
        return (ft_duplicate_string(""));
    if (!s1)
        return (ft_duplicate_string(s2));
    if (!s2)
        return (ft_duplicate_string(s1));
	len = ft_string_length(s1) + ft_string_length(s2);
	total = malloc(len + 1);
	if (!total)
		return (NULL);
	ptr = total;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (total);
}

char	*ft_duplicate_string(const char *str)
{
	size_t	i;
	size_t	len;
	char	*copy;

	len = ft_string_length(str) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

char	*ft_create_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;
	size_t	str_len;
	size_t	new_len;

	if (!str)
		return (NULL);
	str_len = ft_string_length(str);
	if (start > str_len)
		return (ft_duplicate_string(""));
	new_len = len;
	if ((start + len) > str_len)
		new_len = str_len - start;
	sub = (char *)malloc(new_len + 1);
	if (!sub)
		return (NULL);
	index = 0;
	while (index < new_len)
	{
		sub[index] = str[start + index];
		index++;
	}
	sub[new_len] = '\0';
	return (sub);
}
