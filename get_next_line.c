/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:04 by jowoundi          #+#    #+#             */
/*   Updated: 2025/01/08 15:06:40 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuff(int fd, char *tmp_buff, char *rest)
{
	int		i;
	int		nbytes;
	char	*swap;

	nbytes = 1;
	while (!ft_strchr(rest, '\n'))
	{
		nbytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (nbytes == -1)
			return (free(rest), NULL);
		tmp_buff[nbytes] = '\0';
		rest = ft_strjoin(rest, tmp_buff);
		if (!rest)
			return (NULL);
		if (nbytes == 0)
			break ;
	}
	i = ft_strlen(rest);
	swap = malloc(sizeof(char) * (i + 1));
	if (!swap)
		return (NULL);
	swap = ft_strcpy(rest, swap);
	free(rest);
	return (swap);
}

char	*clear_line(char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = -1;
	if (line[0] == 0)
		return (free(line), NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	while (++j < i)
		temp[j] = line[j];
	temp[j] = '\0';
	return (temp);
}

char	*stock_rest(char *temp)
{
	int		i;
	int		j;
	int		len_temp;
	char	*rest;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] && temp[i] == '\n')
		i++;
	len_temp = i;
	while (temp[len_temp])
	{
		len_temp++;
		j++;
	}
	rest = malloc(sizeof(char) * j + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (temp[i])
		rest[j++] = temp[i++];
	rest[j] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		tmp_buff[BUFFER_SIZE + 1];
	static char	*rest;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	temp = readbuff(fd, tmp_buff, rest);
	if (!temp)
		return (NULL);
	line = clear_line(temp);
	if (!line)
		return (free(line), NULL);
	rest = stock_rest(temp);
	free(temp);
	return (line);
}

// # include <stdio.h>
// # include <fcntl.h>

// int main()
// {
// 	int fd;
// 	char *rest;

// 	fd = open("test.txt", O_RDONLY);
// 	rest = get_next_line(fd);
// 	if (rest)
// 		printf("%s", rest);
// 	free(rest);
// 	while (rest)
// 	{
// 		rest = get_next_line(fd);
// 		if (rest)
// 			printf("%s", rest);
// 		free(rest);
// 	}
// 	close(fd);
// }
