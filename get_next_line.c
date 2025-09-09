/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:08:24 by ingrid            #+#    #+#             */
/*   Updated: 2025/09/08 22:40:42 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_newline(char *rest, char *newline)
{
	char	*line;

	*newline = '\0';
	line = ft_strdup(rest);
	ft_strdup(newline + 1);
	free(rest);
	return (line);
}

static char	*ft_line(char *rest)
{
	char	*line;

	line = ft_strdup(rest);
	free(rest);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	size_t		bytes;
	static char	*rest;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (!rest)
			return (NULL);
		newline = ft_strchr(rest, '\n');
		if (newline)
			return (ft_newline(rest, newline));
	}
	if (bytes == 0)
	{
		rest = NULL;
		free(buffer);
		return (ft_line(rest));
	}
	free(buffer);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Uso %s \n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Erro ao abrir o arquivo %s\n", argv[1]);
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
