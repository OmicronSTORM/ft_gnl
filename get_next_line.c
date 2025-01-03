/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:04 by jowoundi          #+#    #+#             */
/*   Updated: 2025/01/03 18:04:14 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuff(int fd, char *tmp_buff, char *rest)
{
	int		i;
	int		j;
	int		nbytes;
	char	*swap;

	j = 0;
	nbytes = 1;
	while (!ft_strchr(rest, '\n'))
	{
		nbytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (nbytes == -1)
			return (free(swap), free(rest), NULL);
		tmp_buff[nbytes] = '\0';
		rest = ft_strjoin(rest, tmp_buff);
		if (!rest)
			return (free(swap), NULL);
		if (nbytes == 0)
			break;
	}
	i = ft_strlen(rest);
	swap = malloc(sizeof(char) * (i + 1));
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
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		temp[j] = line [j];
		j++;
	}
	if (line[j] == '\n')
	{
		temp[j] = line[j];
		j++;
	}
	temp[j] = '\0';
	free(line);
	return (temp);
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
	while (tmp_buff[len_temp])
	{
		len_temp++;
		j++;
	}
	rest = malloc(sizeof(char) * j + 1);
	j = 0;
	while (tmp_buff[i])
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
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (free(rest), NULL);
	line = readbuff(fd, tmp_buff, rest);
	line = clear_line(line);
	if(!line)
		return (NULL);
	rest = stock_rest(tmp_buff);
	return (line);
}

int main()
{
	int fd;
	char *rest;

	fd = open("test.txt", O_RDONLY);
	rest = get_next_line(fd);
	printf("%s", rest);
	rest = get_next_line(fd);
	printf("%s", rest);
	rest = get_next_line(fd);
	printf("%s", rest);
	close(fd);
}
