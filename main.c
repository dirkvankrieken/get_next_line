#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
int main()
{
	char *line;
	int ret;
	int fd;
	int fd2;
	int fd3;
	int i;

	fd = open("Shakespeare.txt", O_RDONLY);
	fd2 = open("ivre", O_RDONLY);
	fd3 = open("huge_alphabet", O_RDONLY);
	ret = 1;
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd2, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd3, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd2, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd3, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd2, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd3, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd2, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	i = 0;
	while (ret > 0 && i < 10)
	{
		ret = get_next_line(fd3, &line);
		printf("%d: %s\n", i, line);
		i++;
	}
	close(fd);
	close(fd2);
	close(fd3);

	return (0);
}
