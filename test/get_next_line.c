/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:37:32 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/12 23:35:44 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static void		*bufr[3] = {NULL, NULL, NULL};
	static ssize_t	szrd;
	char			*nl;
	char			*tmp;

	nl = "";
	if (!bufr[0])
	{
		bufr[0] = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		szrd = read(fd, bufr[0], BUFFER_SIZE);
		bufr[1] = bufr[0];
	}
	if (!bufr[0])
		return (NULL);
	if (bufr[1] <= bufr[0] + szrd)
	{
		bufr[2] = ft_nextnlpos(bufr[1], bufr[0] + szrd);
		nl = ft_substr(bufr[1], bufr[2]);
		bufr[1] = bufr[2] + 1;
	}
	if(szrd < BUFFER_SIZE)
		return(NULL);
	while (bufr[1] > bufr[0] + szrd && szrd == BUFFER_SIZE)
	{
		bufr[1] = bufr[0];
		szrd = read(fd, bufr[0], BUFFER_SIZE);
		bufr[2] = ft_nextnlpos(bufr[1], bufr[0] + szrd);
		tmp = ft_substr(bufr[1], bufr[2]);
		bufr[1] = bufr[2] + 1;
		nl = ft_strjoin(nl, tmp); 
	}
	return(nl);
}
