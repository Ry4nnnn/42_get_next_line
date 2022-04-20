#include "get_next_line.h"

//this function allocates memory and duplicate a string
static char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	slen;
	char	*dst;

	slen = ft_strlen(s);
	dst = (char *)malloc(slen + 1);
	if (!dst)
		return (0);
	i = 0;
	while (i < slen)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

//this function is to free a pointer and null terminating it.
static void	ft_free(char *str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

//this function read from a fd
//set number of bytes readed from the fd and returns it
static int	ft_read(int fd, void **buff, int *bytes)
{
	int res;

	res = read(fd, buff, BUFFER_SIZE);
	*bytes = res;
	return (res);
}

// main function of get next line
// check if buffer size is more then 0
// use ft_read function to read from a fd
// 
char *get_next_line(int fd)
{
	char *buff;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (ft_read(fd, buff, size) > 0)
	{
		buff 
	}
}


int	main()
{
    int fd = open("test.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	// printf("\n second run ------------------------- \n");
	// printf("%s\n",get_next_line(fd));
	// printf("\n third run ------------------------- \n");
	// printf("%s\n",get_next_line(fd));
}