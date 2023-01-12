/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:21:27 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/12 09:30:25 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*bufr;

	printf("main_1\n");
	fd = open("/home/andoitzcp/42_cursus/gnl/test/test0", 'r');
	bufr = (char *)malloc(BUFFER_SIZE + 1);
	read(fd, bufr, BUFFER_SIZE);
	printf("main_2: readstr=%s\n", bufr);
	close(fd);
}
