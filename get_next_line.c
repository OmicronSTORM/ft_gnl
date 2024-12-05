/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:06 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/05 17:08:22 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	readbuff(int fd, char *line)
{
	int		caract;
	char	*temp;

	caract = 0;
	temp = NULL;
	while (!ft_strchr(line, '\n'))
	{
		temp = ft_strjoin(temp, line);
		read(fd, line, BUFFER_SIZE);
		temp = line;
	}
	printf("%s", temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	tmp_buff[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbuff(fd, line);
	return (0);
}
int main()
{
	int fd;
	
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
