#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	static char	*rest;
	ssize_t		nbytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nbytes = read(fd, buf, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buf[nbytes] = '\0';
		rest = ft_strjoin(rest, buf);
	}
	if (nbytes == 0)
	{
		free(buf);
		return (NULL);
	}
	if (nbytes < 0)
		return (NULL);
	buf[nbytes] = '\0';
	return (buf);
}

int	main(void)
{
	int		fd;
	char	*line;
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erro ao encontrar o arquivo.");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
