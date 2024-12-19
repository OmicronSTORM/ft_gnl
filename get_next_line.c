/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:06 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/19 18:59:54 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc(char *temp, char *rest)
{
	int	i;

	i = ft_strlen(rest);
	temp = malloc(sizeof(char) * i);
	temp = rest;
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
				temp = ft_strjoin(temp, tmp_buff);
			if (bytes_read == 0)
				return (temp);
		}
		while (tmp_buff[i] && tmp_buff[i] != '\n')
			swap[j++] = tmp_buff[i++];
		if (tmp_buff[i] == '\n')
			{
			swap[j] = tmp_buff[i];
			j++;
			}
		swap[j] = '\0';
		temp = ft_strjoin(temp, swap);
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
	len_temp = i;
	while (tmp_buff[len_temp] && tmp_buff[len_temp] != '\n')
	{
		len_temp++;
		j++;
	}
	rest = malloc(sizeof(char) * j);
	j = 0;
	while (tmp_buff[i] && tmp_buff[i] !=  '\n')
		rest[j++] = tmp_buff[i++];
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	char		tmp_buff[BUFFER_SIZE];

	if (!rest)
		rest = ft_strdup("");
	printf("check 1 ok\n");
	sleep(1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = readbuff(fd, tmp_buff, rest);
	if (!tmp_buff || tmp_buff[0] == '\0')
		return (NULL);
	rest = stock_rest(tmp_buff, rest);
	// printf("rest: %s", rest);
	// printf("tmp_buff before: %s\n-----\n", tmp_buff);
	// printf("tmp_buff: %s\n-----\n", tmp_buff);
	// printf("%s", line);
	// printf("__________________________________________\n\n");
	return (line);
}
int main()
{
	int fd;
	int i;
	char *line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	// while (1)
	// {
		line = get_next_line(fd);
	// 	if (!line)
	// 		break;
		printf("%s", line);
		// line = get_next_line(fd);
		// printf("%s", line);
	// 	free(line);
	// }
	return (0);
	close(fd);
}
