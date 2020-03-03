#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# define BUFFER_SIZE 10

# define NL 1
# define EoF 0
# define ERROR -1

int		get_next_line(int fd, char **line);

#endif
