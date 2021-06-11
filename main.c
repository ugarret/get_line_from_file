/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:28:12 by ugarret           #+#    #+#             */
/*   Updated: 2020/12/12 19:13:16 by ugarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main()
{
	int		fd;
	char	*line;
	int		i;

	fd = open("64bit_paragraph.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
	free(line);
	return (0);
}