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

#include "get_next_line.h"

int		write_in_remainder_and_line(char **rem_line, char **line)
{
	char		*temp;
	int			i;

	if ((i = ft_search_index_newline(*rem_line)) != -1)
	{
		*line = ft_substring(*rem_line, 0, i);
		temp = ft_substring(*rem_line, i + 1, ft_strlen(*rem_line + i + 1));
		free(*rem_line);
		if (!(*line) || !temp)
			return (-1);
		*rem_line = temp;
		return (1);
	}
	else
	{
		if (!(*line = ft_substring(*rem_line, 0, ft_strlen(*rem_line))))
			return (-1);
		free(*rem_line);
		*rem_line = NULL;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char *rem_line;
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	if (!line || fd < 0 || read(fd, buffer, 0) == -1)
		return (-1);
	if (!(rem_line) && !(rem_line = ft_memory_for_new_string(1)))
		return (-1);
	if (ft_search_index_newline(rem_line) == -1)
	{
		while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[bytes_read] = '\0';
			if (!(rem_line = ft_strjoin(rem_line, buffer)))
				return (-1);
			if (ft_search_index_newline(rem_line) != -1)
				break ;
		}
	}

	return (write_in_remainder_and_line(&rem_line, line));
}
