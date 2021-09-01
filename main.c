#include <fcntl.h>
#include <stdio.h>
#include "get_line_from_file.h"

int		main()
{
	int	fd;
	char	*line;
	int	i;

	/*fd = open("one_long_string.txt", O_RDONLY);*/
	fd = open("64bit_paragraph.txt", O_RDONLY);
	while ((i = get_line_from_file(fd, &line)) > 0)
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
	free(line);
	return (0);
}
