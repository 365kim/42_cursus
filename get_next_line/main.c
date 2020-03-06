#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line = 0;
	int		ret;
	int		fd;
	int		i;

	i = 1;
	fd = open("test", O_RDONLY);
//	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("get_next_line[%d] : %s\n", i++, line);
		printf("return value : %d\n", ret);
		free(line);
	}
	printf("get_next_line[%d] : %s\n", i, line);
	printf("return value : %d\n", ret);
	free(line);
	return (0);
}
