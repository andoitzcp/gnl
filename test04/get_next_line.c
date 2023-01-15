/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:37:32 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/15 19:34:21 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

static char	*ft_readfd(int fd, char *bufr)
{
	size_t	indx;

	bufr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); 
	if (!bufr)
		return (NULL);
	indx = 0;
	while (indx < BUFFER_SIZE + 1)
	{
		bufr[indx] = '\0';
		indx++;
	}
	read(fd, bufr, BUFFER_SIZE);
	return(bufr);
}

static char	*ft_nlgen(char *s1, char *s2)
{
	char	*nl;
	size_t	indx;

	nl = ft_strjoin(s1, s2);
	free(s1);
	indx = 0;
	while (nl[indx] && nl[indx] != '\n')
		indx++;
	if (nl[indx] == '\n')
		indx++;
	while (nl[indx])
	{
		nl[indx] = '\0';
		indx++;
	}
	return(nl);
}

char	*get_next_line(int fd)
{
	static char	*bufr = NULL;
	char		*aux;
	char		*tmp;
	char		*nl;
	ssize_t		nl_indx;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 )
		return (NULL);
	//printf("flag1\tptr: %p, str: %s\n", bufr, bufr);
	if (!bufr)
		bufr = ft_readfd(fd, bufr);
	//printf("flag2\tptr: %p, str: %s\n", bufr, bufr);
	if (!*bufr)
	{
		free(bufr);
		bufr = NULL;
		return (NULL);
	}
	aux = ft_strdup("");
	nl_indx = ft_nextnlpos(bufr);
	while (nl_indx == -1 && *bufr)
	{
		tmp =ft_nlgen(aux, bufr);
		free(bufr);
		aux = tmp;
		bufr = ft_readfd(fd, bufr);
		nl_indx = ft_nextnlpos(bufr);
	}
	nl = ft_nlgen(aux, bufr);
	tmp = bufr + nl_indx + 1;
	tmp = ft_strdup(tmp);
	free(bufr);
	if (*tmp)
		bufr = tmp;
	else
	{
		bufr = NULL;
		free(tmp);
	}
	return(nl);
}
