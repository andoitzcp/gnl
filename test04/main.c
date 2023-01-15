/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:21:27 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/15 15:10:33 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*nl;

	printf("main_1\n");
	fd = open("/home/andoitzcp/42_cursus/gnl/test04/empty.txt", 'r');
	printf("main_2\n");
	nl = get_next_line(fd);
	printf("main_3: %s", nl);
	nl = get_next_line(fd);
	printf("main_4: %s", nl);
	nl = get_next_line(fd);
	printf("main_5: %s", nl);
	nl = get_next_line(fd);
	printf("main_6: %s", nl);
	nl = get_next_line(fd);
	printf("main_7: %s", nl);
	nl = get_next_line(fd);
	printf("main_8: %s", nl);
	close(fd);
}
