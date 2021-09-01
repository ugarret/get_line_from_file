#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int	get_line_from_file(int fd, char **line);
int	my_strlen(const char *str);
char	*my_substr(const char *str, int start, int len);
char	*join_two_string(char *str1, char *str2);
int	search_index_newline(const char *str);
char	*memory_for_new_string(int i);

#endif
