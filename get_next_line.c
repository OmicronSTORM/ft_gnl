/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:06 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/17 16:45:39 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuff(int fd, char *tmp_buff, char	*rest)
{
	int		i;
	int		j;
	char	*temp;
	char	*swap;

	i = 0;
	j = 0;
	swap = ft_strdup("");
	temp = rest;
	if (!temp)
		temp = ft_strdup("");
	while (!ft_strchr(tmp_buff, '\n'))
	{
		temp = ft_strjoin(temp, tmp_buff);
		read(fd, tmp_buff, BUFFER_SIZE);
	}
	while (tmp_buff[i] && tmp_buff[i] != '\n')
		swap[j++] = tmp_buff[i++];
	swap[j] = '\0';
	temp = ft_strjoin(temp, swap);
	printf("REPONSE:\n%s\n", temp);
	// printf("tmp_buff: \n%s\n", tmp_buff);
	return (temp);
}
char	*stock_rest(char *tmp_buff, char *rest)
{
	int	i;
	int	j;
	int	len_temp;
	char	*tmp;

	i = 0;
	j = 0;
	while (tmp_buff[i] && tmp_buff[i] != '\n')
		i++;
	if (tmp_buff[i] && tmp_buff[i] == '\n')
		i++;
	while (tmp_buff[i])
		rest[j++] = tmp_buff[i++];
	// printf("%s\n", rest);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	rest[BUFFER_SIZE];
	char		tmp_buff[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = readbuff(fd, tmp_buff, rest);
	if (!tmp_buff || tmp_buff[0] == '\0')
		return (NULL);
	stock_rest(tmp_buff, rest);
	read(fd, tmp_buff, BUFFER_SIZE);
	return (line);
}
int main()
{
	int fd;
	int i;
	char *line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}
