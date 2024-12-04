/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:06 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/04 17:57:38 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	readbuff(int fd, char **line)
{
	int		bytes;
	char	*line;
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp_buff;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbuff(fd, &tmp_buff);
}
