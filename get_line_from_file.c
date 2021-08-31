/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:28:12 by ugarret           #+#    #+#             */
/*   Updated: 2020/12/17 16:06:11 by ugarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line_from_file.h"

static int write_in_remainder_and_line(char **rem_line, char **line)
{
	char	*temp;
	int	i;

	if ((i = search_index_newline(*rem_line)) != -1)
	{
		*line = my_substr(*rem_line, 0, i);
		temp = my_substr(*rem_line, i + 1, my_strlen(*rem_line + i + 1));
		free(*rem_line);
		if (!(*line) || !temp)
			return (-1);
		*rem_line = temp;
		return (1);
	}
	else
	{
		if (!(*line = my_substr(*rem_line, 0, my_strlen(*rem_line))))
			return (-1);
		free(*rem_line);
		*rem_line = NULL;
		return (0);
	}
}

int get_line_from_file(int fd, char **line)
{
	static char	*rem_line;
	int		bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	if (!line || fd < 0 || read(fd, buffer, 0) == -1)
		return (-1);
	if (!(rem_line) && !(rem_line = memory_for_new_string(1)))
		return (-1);
	if (search_index_newline(rem_line) == -1)
	{
		while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[bytes_read] = '\0';
			if (!(rem_line = join_two_string(rem_line, buffer)))
				return (-1);
			if (search_index_newline(rem_line) != -1)
				break ;
		}
	}

	return (write_in_remainder_and_line(&rem_line, line));
}
