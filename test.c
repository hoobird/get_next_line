/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:03:11 by hoobird           #+#    #+#             */
/*   Updated: 2024/04/22 19:43:30 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*memline;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memline = readnextline(fd, memline);
	if (memline)
	{
		nextline = splitline(memline);
		memline = shiftline(memline);
		return (nextline);
	}
	return (NULL);
}

char	*readnextline(int fd, char *memline)
{
	char	*buf;
	int		readsize;

	readsize = 1;
	while (newlinefound(memline) == 0 && readsize)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize < 0)
			return (myfree(&buf), myfree(&memline), NULL);
		buf[readsize] = '\0';
		memline = ft_strjoin(memline, buf);
	}
	return (memline);
}

char	*splitline(char *memline)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(memline) + 1));
	if (!temp || !memline[0])
		return (myfree(&temp), NULL);
	while (memline[i] != '\0')
	{
		temp[i] = memline[i];
		i++;
		if (memline[i] == '\n')
		{
			temp[i] = memline[i];
			i++;
			break ;
		}
	}
	temp[i] = '\0';
	return (temp);
}

char	*shiftline(char *memline)
{
	int		newlen;
	char	*newline;
	char	*temp;

	newline = ft_strchr(memline, '\n');
	temp = NULL;
	if (newline)
	{
		newlen = ft_strlen(newline + 1);
		temp = malloc(sizeof(char) * (newlen + 1));
		if (!temp)
			return (myfree(&temp), NULL);
		ft_strlcpy(temp, newline + 1, newlen + 1);
	}
	myfree(&memline);
	return (temp);
}

void	myfree(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

size_t	ft_strlen(const char *s)
{
	char	*temp;
	int		count;

	if (s == NULL)
		return (0);
	temp = (char *) s;
	count = 0;
	while (*temp)
	{
		count++;
		temp++;
	}
	return (count);
}

int	newlinefound(char *memline)
{
	if (memline == NULL)
		return (0);
	while (*memline)
	{
		if (*memline == '\n')
			return (1);
		memline++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		totallen;
	char	*temp;

	i = 0;
	j = 0;
	totallen = ft_strlen(s1) + ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (totallen + 1));
	if (temp == NULL)
		return (NULL);
	if (s1)
		while (s1[j])
			temp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	myfree(&s1);
	myfree(&s2);
	return (temp);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(s);
	while (count <= len)
	{
		if (s[count] == (unsigned char) c)
		{
			return ((char *)&s[count]);
		}
		count++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[count] != 0 && count < (size -1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = 0;
	return (ft_strlen(src));
}
