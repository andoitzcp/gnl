/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:17:08 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/12 22:12:37 by acampo-p         ###   ########.fr       */
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

void	*ft_nextnlpos(const void *start, const void *end)
{
	unsigned char	*cs;
	unsigned char	*ce;

	cs = (unsigned char *) start;
	ce = (unsigned char *) end;
	while (start < end)
	{
		if (*cs == '\n')
			return ((void *) cs);
		cs++;
	}
	return ((void *) ce);
}

char	*ft_substr(char const *start, const void *end)
{
	char	*str;
	size_t	len;

	len = end - (const void *) start + 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, start, len);
	str[len] = '\0';
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
