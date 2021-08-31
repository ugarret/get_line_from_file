#include "get_line_from_file.h"

int my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *join_two_string(char *str1, char *str2)
{
	char	*comb;
	int	len1;
	int	len2;
	int	i;

	if (!str1)
		return (str2);
	else if (!str2)
		return (str1);
	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	if (!(comb = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = -1;
	while (++i < len1)
		comb[i] = str1[i];
	while (i < len1 + len2)
	{
		comb[i] = str2[i - len1];
		i++;
	}
	comb[i] = '\0';
	free(str1);
	return (comb);
}

char *memory_for_new_string(int i)
{
	char	*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	new_str[i] = '\0';
	while (--i >= 0)
		new_str[i] = 0;
	return (new_str);
}

int search_index_newline(const char *str)
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

char *my_substr(const char *str, int start, int len)
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
