/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:49:36 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/20 18:50:22 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	buffer[10];
	ssize_t	rb;

	fd = open("/home/andoitzcp/42_cursus/gnl/test", O_RDONLY);
	if (fd == -1)
		return (1);
	rb = read(fd, buffer, 5);
	if (!rb)
		write (1, "empty file\n", 11);
	else
		printf("rb: %d\n", (int)rb);
		printf("rb: %s\n", buffer);
	rb = read(fd, buffer, 5);
	close(fd);
	if (!rb)
		write (1, "empty file\n", 11);
	else
		printf("rb: %d\n", (int)rb);
		printf("rb: %s\n", buffer);
	return (0);
}
