/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:44:15 by maroard           #+#    #+#             */
/*   Updated: 2026/02/03 12:15:18 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static char	*extract_line(char **stock)
{
	char	*line;
	char	*temp;
	int		line_len;

	if (!ft_strchr(*stock, '\n'))
	{
		line = ft_strdup(*stock);
		if (!line)
			return (NULL);
		return (free(*stock), *stock = NULL, line);
	}
	line_len = ft_strlen(*stock) - ft_strlen(ft_strchr(*stock, '\n') + 1);
	line = malloc(line_len * sizeof(char) + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *stock, line_len);
	temp = *stock;
	*stock = ft_strdup(ft_strchr(temp, '\n') + 1);
	free(temp);
	if (!**stock)
		return (free(*stock), *stock = NULL, line);
	return (line);
}

static int	dup_or_join(char **stock, char **buffer)
{
	char	*temp;

	if (!*stock)
	{
		*stock = ft_strdup(*buffer);
		if (!*stock)
			return (free(*buffer), 0);
		if (ft_strchr(*stock, '\n'))
			return (free(*buffer), 1);
	}
	else
	{
		temp = *stock;
		*stock = ft_strjoin(temp, *buffer);
		free(temp);
		if (!*stock)
			return (free(*buffer), 0);
	}
	free(*buffer);
	return (1);
}

static int	read_and_store(int fd, char **stock, char **buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while ((!*stock || !ft_strchr(*stock, '\n')) && bytes_read > 0)
	{
		*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!*buffer)
			return (0);
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (!bytes_read)
			return (free(*buffer), *buffer = NULL, 1);
		if (bytes_read < 0)
			return (free(*buffer), *buffer = NULL, 0);
		(*buffer)[bytes_read] = '\0';
		if (!dup_or_join(stock, buffer))
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stock[FD_SETSIZE];
	char		*buffer;

	if (fd < 0 || fd > FD_SETSIZE || !read_and_store(fd, &stock[fd], &buffer))
		return (NULL);
	if (!stock[fd])
		return (NULL);
	return (extract_line(&stock[fd]));
}
