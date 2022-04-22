/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:06:17 by welim             #+#    #+#             */
/*   Updated: 2022/04/22 16:06:18 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//calculate the length of the string
//returns the length of the string
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//allocates a new memory
//joins s1 and s2 to res
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

//finds the first occurrence of c in the string
//return the string after the c if c is found in the string
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s) && s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		s++;
	}
	return (0);
}

//allocates memmory and creates a substring
//starting length and end length.
char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < len)
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}
