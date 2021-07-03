#include "get_next_line.h"

char	*get_save(char *save)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	res = ft_malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!res)
		return (0);
	i++;
	while (save[i])
		res[j++] = save[i++];
	res[j] = '\0';
	free(save);
	return (res);
}

char	*get_line(char *line)
{
	int		i;
	char	*res;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	res = ft_malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	read_and_join(int fd, char **remainder, char *buff)
{
	int	bytes_read;

	bytes_read = 1;
	while (0 == ft_strchr(*remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		buff[bytes_read] = '\0';
		*remainder = strjoin(*remainder, buff);
	}
	return (bytes_read);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				bytes_read;

	bytes_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = ft_malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	bytes_read = read_and_join(fd, &save, buff);
	free(buff);
	if (bytes_read == -1)
		return (-1);
	*line = get_line(save);
	save = get_save(save);
	if (bytes_read == 0)
		return (0);
	return (1);
}
