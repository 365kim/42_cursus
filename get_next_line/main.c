#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line = 0;
	int		ret;
	int		fd;
	fd = open("test", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	printf("return value : %d", ret);
	return (0);
}
