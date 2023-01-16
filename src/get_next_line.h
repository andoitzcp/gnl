/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:30:52 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/15 14:22:53 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

//#define BUFFER_SIZE 42

typedef struct	s_bufr
{
	char	*str;
	size_t	indx;
	ssize_t	szrd;
}				t_bufr;

ssize_t	ft_nextnlpos(const void *start);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
