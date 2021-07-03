#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
void	*ft_malloc(int size);
size_t	ft_strlen(const char *s);
char	*strjoin(const char *s1, const char *s2);
int		read_and_join(int fd, char **remainder, char *buff);
char	*ft_strchr(const char *s, int c);

#endif