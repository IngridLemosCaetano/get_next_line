/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:59:39 by ingrid            #+#    #+#             */
/*   Updated: 2025/09/11 15:55:39 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line_bonus(char *rest)
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

static char	*ft_new_rest_bonus(char *rest)
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

static char	*ft_read_file_bonus(int fd, char *rest)
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
	static char	*rest[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest[fd])
	{
		rest[fd] = ft_strdup("");
		if (!rest[fd])
			return (NULL);
	}
	rest[fd] = ft_read_file_bonus(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	if (rest[fd][0] == '\0')
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (NULL);
	}
	line = ft_line_bonus(rest[fd]);
	rest[fd] = ft_new_rest_bonus(rest[fd]);
	return (line);
}
