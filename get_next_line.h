/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:02:51 by skarayil          #+#    #+#             */
/*   Updated: 2025/07/02 01:40:54 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_string_length(const char *str);
char	*get_next_line(int fd);
char	*ft_find_character(const char *str, int c);
char	*ft_join_strings(char *s1, char *s2);
char	*ft_duplicate_string(const char *str);
char	*ft_create_substr(const char *str, unsigned int start, size_t len);
#endif
