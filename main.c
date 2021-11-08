#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int     ret;
	char    *line;
	int fd = open("test", O_RDONLY);

	ret = 1;
	// while (ret > 0)
	// {
		ret = get_next_line(fd, &line);
		printf("line: %s$\n", line);
		free(line);
		ret = get_next_line(fd, &line);
		printf("line: %s$\n", line);
		free(line);
		ret = get_next_line(fd, &line);
		printf("line: %s$\n", line);
		free(line);
    // }
	system("leaks a.out");
}