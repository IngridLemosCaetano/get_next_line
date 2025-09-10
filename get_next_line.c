/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:08:24 by ingrid            #+#    #+#             */
/*   Updated: 2025/09/10 12:51:02 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char *rest)
{
	char	*first_part;
	size_t	len;
	size_t	i;

	if (!rest)
		return (NULL);
	len = 0;
	while (rest[len] && rest[len] != '\n')
		len++;
	if (rest[len] == '\n')
		i = 1;
	else
		i = 0;
	first_part = ft_substr(rest, 0, len + i);
	return (first_part);
}

static char	*ft_new_rest(char *rest)
{
	char	*new_rest;
	size_t	len;

	if (!rest)
		return (NULL);
	len = 0;
	while (rest[len] && rest[len] != '\n')
		len++;
	if (!rest[len])
	{
		free(rest);
		return (NULL);
	}
	new_rest = ft_strdup(rest + len + 1);
	free(rest);
	return (new_rest);
}

static char	*ft_read_file(int fd, char *rest)
{
	char	*buf;
	ssize_t	nbytes;
	char	*temp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nbytes = 1;
	while (!ft_strchr(rest, '\n') && nbytes > 0)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(rest);
			return (free(buf), NULL);
		}
		buf[nbytes] = '\0';
		temp = rest;
		rest = ft_strjoin (rest, buf);
		free(temp);
		if (!rest)
			return (free(buf), NULL);
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
	{
		rest = ft_strdup("");
		if (!rest)
			return (NULL);
	}
	rest = ft_read_file(fd, rest);
	if (!rest)
		return (NULL);
	if (rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = ft_line(rest);
	rest = ft_new_rest(rest);
	return (line);
}
