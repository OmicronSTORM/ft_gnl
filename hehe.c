/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hehe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:04 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/23 19:08:42 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc(char *line, char *rest)
{
	int	lenght;
	
	lenght = ft_strlen(rest);
	line = malloc(sizeof(char) * lenght + 1);
	if (!line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = rest;
	line[lenght + 1] = '\0';
	return (line);
}

char	*readbuff(int fd, char *tmp_buff, char *rest)
{
	int		i;
	int		j;
	int		nbytes;
	char	*line;
	char	*swap;

	j = 0;
	nbytes = 1;
	swap = ft_strdup("");
	line = alloc(line, rest);
	if (!line)
		line = ft_strdup("");
	printf("ok\n");
	while (!ft_strchr(tmp_buff, '\n'))
	{
		nbytes = read(fd, tmp_buff, BUFFER_SIZE);
		tmp_buff[BUFFER_SIZE + 1] = '\0';
		line = ft_strjoin(line, tmp_buff);
		if (nbytes == 0)
			break; //break effectue. travaille a faire dans le cas ou nbytes = 0.
	}
	if (nbytes != 0)
	{
		i = ft_strlen(line);
		while (line[i] != '\n')
			i--;
		swap = malloc(sizeof(char) * i + 1);
		while (line[j] != '\n')
		{
			swap[j] = line[j];
			j++;
		}
		if (line[j] == '\n')
			swap[j] = line[j];
		swap[j + 1] = '\0';
	}
	else
	{
		i = ft_strlen(line);
		j = ft_strlen(tmp_buff);
		printf("%d\n", i);
		swap = malloc(sizeof(char) * (i - j));
		i -= j;
		printf("%d\n", i);
	}
	free(line);
	return (swap);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		tmp_buff[BUFFER_SIZE + 1];
	static char	*rest;

	if (!rest)
		rest = ft_strdup("");
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = readbuff(fd, tmp_buff, rest);
	return (line);
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
}