/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:17:08 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/15 14:22:10 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	size_t	index;

	if (!dst && !src)
		return (dst);
	cdst = (char *)dst;
	csrc = (char *)src;
	index = 0;
	while (index < len)
	{
		cdst[index] = csrc[index];
		index++;
	}
	return (dst);
}

ssize_t	ft_nextnlpos(const void *start)
{
	unsigned char	*cs;
	ssize_t			indx;

	cs = (unsigned char *) start;
	indx = 0;
	while (cs[indx] != '\0')
	{
		if (cs[indx] == '\n')
			return (indx);
		indx++;
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s, len);
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len[2];

	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	str = (char *)malloc(len[0] + len[1] + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, len[0]);
	str += len[0];
	str = ft_memcpy(str, s2, len[1] + 1);
	str -= len[0];
	return (str);
}
