/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:28:12 by ugarret           #+#    #+#             */
/*   Updated: 2020/12/17 16:06:11 by ugarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*comb;
	int		len1;
	int		len2;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!(comb = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		comb[i] = str1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		comb[i] = str2[i - len1];
		i++;
	}
	comb[i] = '\0';
	free(str1);
	return (comb);
}

char	*ft_memory_for_new_string(int i)
{
	char	*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	new_str[i] = '\0';
	i--;
	while (i >= 0)
	{
		new_str[i] = 0;
		i--;
	}
	return (new_str);
}

int		ft_search_index_newline(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substring(const char *str, int start, int len)
{
	char	*substr;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !substr)
		return (NULL);
	substr[len] = '\0';
	while (len > 0)
	{
		len--;
		substr[len] = str[start + len];
	}
	return (substr);
}
