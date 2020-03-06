#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

# define BUFFER BUFFER_SIZE

# define FD_MAX 4096

# define NL 1
# define EoF 0
# define ERROR -1

int		get_next_line(int fd, char **line);

size_t	ft_strlen(char *c);
void	*ft_memcpy(void	*dst, void *stc, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
