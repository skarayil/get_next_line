/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 22:35:46 by skarayil          #+#    #+#             */
/*   Updated: 2025/07/11 05:29:56 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_string_length(const char *s);
char	*ft_string_char(const char *s, int c);
void	*ft_memory_move(void *dest, const void *src, size_t n);
void	*ft_memory_copy(void *dest, const void *src, size_t n);
int		ft_append_memory(char **s1, const char *s2, size_t size2);

#endif
