/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:28:12 by ugarret           #+#    #+#             */
/*   Updated: 2020/12/23 14:10:58 by ugarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int	get_next_line(int fd, char **line);
int	ft_strlen(const char *str);
char	*ft_substring(const char *str, int start, int len);
char	*ft_strjoin(char *str1, char *str2);
int	ft_search_index_newline(const char *str);
char	*ft_memory_for_new_string(int i);
int	write_in_remainder_and_line(char **rem_line, char **line);

#endif
