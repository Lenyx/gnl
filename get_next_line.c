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
	// while (!has_newline(save) && bytes_read != 0)
	// {
	// 	bytes_read = read(fd, buff, BUFFER_SIZE);
	// 	if (bytes_read == -1)
	// 	{
	// 		free(buff);
	// 		return (-1);
	// 	}
	// 	buff[bytes_read] = '\0';
	// 	save = strjoin(save, buff);
	// }
	bytes_read = read_and_join(fd, &save, buff);
	free(buff);
	if (bytes_read == -1)
		return (-1);
	//printf("1%s\n", save);
	*line = get_line(save);
	//printf("2%s", *line);
	save = get_save(save);
	//printf("3%s\n", save);
	//getchar();
	if (bytes_read == 0)
		return (0);
	return (1);
}

// int	main(void)
// {
// 	char 	*line;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	get_next_line(fd, &line);
// 	printf("%s", line);
// 	free(line);
// 	get_next_line(fd, &line);
// 	printf("%s", line);
// 	free(line);
// 	get_next_line(fd, &line);
// 	printf("%s", line);
// 	free(line);

// 	return (0);
// }