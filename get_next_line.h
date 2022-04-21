#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//# define BUFFERSIZE 42
//main function
char	*get_next_line(int fd);

//sub functions
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif