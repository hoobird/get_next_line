/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:22:31 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/26 19:01:06 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*readnextline(int fd, char *memline);
size_t	ft_strlen(const char *s);
void	myfree(char **ptr);
int		newlinefound(char *memline);
char	*splitline(char *memline);
char	*shiftline(char *memline);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
