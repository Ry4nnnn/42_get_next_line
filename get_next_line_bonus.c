/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:06:21 by welim             #+#    #+#             */
/*   Updated: 2022/04/22 16:06:23 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//this function allocates memory and duplicate a string
static char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	slen;
	char	*dst;

	slen = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * slen + 1);
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

//this function read from a fd
//set number of bytes readed from the fd and returns it
static int	ft_read(int fd, char **buff, int *bytes)
{
	int	res;

	res = read(fd, *buff, BUFFER_SIZE);
	*bytes = res;
	return (res);
}

//this function is to free a pointer and null terminating it.
static void	ft_free(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

//this function is to extract a string containing newline
//when buffer contains a newline this func will be called
//loops through the buffer to find a newline
//when newline is found, trims the string from the start to the newline
//remainder will be duplicated into temp, str will be free
//temp will be assigned to str, str now contains
//the remainder of the string will get stored in str for next call
static char	*get_newline(char **str)
{
	size_t	i;
	char	*temp;
	char	*res;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i])
	{
		res = ft_substr(*str, 0, i + 1);
		temp = ft_strdup(*str + i + 1);
		ft_free(str);
		if (temp[0] != '\0')
			*str = temp;
		else
			ft_free(&temp);
	}
	else
	{
		res = ft_strdup(*str);
		ft_free(str);
	}
	return (res);
}

// main function of get next line
// check if buffer size is more then 0
// use ft_read function to read from a fd
char	*get_next_line(int fd)
{
	int			bytes;
	char		*buff;
	char		*temp;
	static char	*res[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (ft_read(fd, &buff, &bytes) > 0)
	{
		buff[bytes] = 0;
		if (!res[fd])
			res[fd] = ft_strdup("");
		temp = ft_strjoin(res[fd], buff);
		ft_free(&res[fd]);
		res[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	ft_free(&buff);
	if (bytes < 0 || (bytes == 0 && !res[fd]))
		return (0);
	return (get_newline(&res[fd]));
}
