/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:06 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/24 18:06:16 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc(char *temp, char *rest)
{
	int	i;

	i = ft_strlen(rest);
	temp = malloc(sizeof(char) * i);
	temp = rest;
	free(rest);
	return(temp);
	// int		i;
	// int		lenght;
	// char	*line;
	
	// lenght = ft_strlen(rest);
	// printf("%d\n", lenght);
	// line = malloc(sizeof(char) * lenght);
	// if (!line)
	// {
	// 	free(line);
	// 	line = NULL;
	// 	return (NULL);
	// }
	// line = rest;
	// return (line);
}
char	*readbuff(int fd, char *tmp_buff, char	*rest)
{
	int		i;
	int		j;
	int		bytes_read;
	char	*temp;
	char	*swap;

	i = 0;
	j = 0;
	bytes_read = 1;
	swap = ft_strdup("");
	temp = alloc(temp, rest);
	if (!temp)
		temp = ft_strdup("");
	while (!ft_strchr(tmp_buff, '\n'))
	{
		bytes_read = read(fd, tmp_buff, BUFFER_SIZE);
		tmp_buff[BUFFER_SIZE + 1] = '\0';
		temp = ft_strjoin(temp, tmp_buff);
		// printf("tmp_buff: %s\n",tmp_buff);
		if (bytes_read == 0)
			return (temp);
	}
	while (tmp_buff[i] && tmp_buff[i] != '\n')
		i++;
	if (tmp_buff[i] == '\n')
		i++;
	swap = malloc(sizeof(char) * i + 1);
	i = 0;
	while (tmp_buff[i] && tmp_buff[i] != '\n')
		swap[j++] = tmp_buff[i++];
	if (tmp_buff[i] == '\n')
		swap[j++] = tmp_buff[i++];
	swap[j] = '\0';
	temp = ft_strjoin(temp, swap);
	return (temp);
}

char	*stock_rest(char *tmp_buff)
{
	int	i;
	int	j;
	int	len_temp;
	char	*tmp;
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
	while (tmp_buff[i] && tmp_buff[i] !=  '\n')
		rest[j++] = tmp_buff[i++];
	if (tmp_buff[i] && tmp_buff[i] == '\n')
		rest[j] = tmp_buff[i];
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	char		tmp_buff[BUFFER_SIZE + 1];

	if (!rest)
		rest = ft_strdup("");
	printf("check 1 ok\n");
	sleep(1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = readbuff(fd, tmp_buff, rest);
	if (!tmp_buff || tmp_buff[0] == '\0')
		return (NULL);
	rest = stock_rest(tmp_buff);
	read(fd, tmp_buff, BUFFER_SIZE);
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
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
}
