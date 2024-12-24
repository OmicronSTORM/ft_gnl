/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hehe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:04 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/24 18:56:49 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc(char *rest)
{
	int		i;
	int		lenght;
	char	*line;
	
	lenght = ft_strlen(rest);
	printf("%d\n", lenght);
	line = malloc(sizeof(char) * lenght);
	if (!line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = rest;
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
	line = alloc(rest);
	if (!line)
		line = ft_strdup("");
	while (!ft_strchr(tmp_buff, '\n'))
	{
		nbytes = read(fd, tmp_buff, BUFFER_SIZE);
		tmp_buff[BUFFER_SIZE + 1] = '\0';
		line = ft_strjoin(line, tmp_buff);
		if (nbytes == 0)
			break;
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
		j = 0;
		while (i > j)
		{
			swap[j] = line[j];
			j++;
		}
	}
	free(line);
	return (swap);
}

char	*stock_rest(char *tmp_buff)
{
	int	i;
	int	j;
	int	len_temp;
	char	*rest;

	i = 0;
	j = 0;
	while (tmp_buff[i] && tmp_buff[i] != '\n')
		i++;
	if (tmp_buff[i] && tmp_buff[i] == '\n')
		i++;
	len_temp = i;
	while (tmp_buff[len_temp] && tmp_buff[len_temp] != '\n')
	{
		len_temp++;
		j++;
	}
	rest = malloc(sizeof(char) * j + 1);
	j = 0;
	while (tmp_buff[i] && tmp_buff[i] != '\n')
		rest[j++] = tmp_buff[i++];
	rest[j] = '\0';
	return (rest);
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
	rest = stock_rest(tmp_buff);
	return (line);
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
}