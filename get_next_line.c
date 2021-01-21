/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 10:30:58 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/01/19 12:11:41 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		free_string(int ret, char *s)
{
	free(s);
	return (ret);
}

int		write_to_line(char **line, char *buf, char **str, char *newline)
{
	char *temp;

	if (!*line)
		return (free_string(-1, *str));
	*newline = '\0';
	temp = *line;
	*line = ft_strjoin(*line, buf);
	free(temp);
	if (!*line)
		return (free_string(-1, *str));
	temp = *str;
	if (ft_strlen(newline + 1) == 0)
		*str = ft_strdup("");
	else
		*str = ft_strdup(newline + 1);
	free(temp);
	if (!*str)
		return (-1);
	return (1);
}

int		read_fd(char **line, int fd, char **str)
{
	int		read_bytes;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(*str);
			*str = NULL;
			return (read_bytes);
		}
		buf[read_bytes] = '\0';
		if (find_nl(buf) != NULL)
			return (write_to_line(line, buf, str, find_nl(buf)));
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
		if (!*line)
			return (free_string(-1, *str));
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char *str = NULL;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	if (!str)
		return (-1);
	if (find_nl(str) != NULL)
	{
		*line = ft_strdup("");
		ret = write_to_line(line, str, &str, find_nl(str));
	}
	else
	{
		*line = ft_strdup(str);
		if (!*line)
			free_string(-1, str);
		ret = read_fd(line, fd, &str);
	}
	return (ret);
}