/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:06 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/13 19:09:07 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuff(int fd, char *tmp_buff)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = tmp_buff;
	// printf("%s\n", temp);
	while (!ft_strchr(tmp_buff, '\n'))
	{
		temp = ft_strjoin(temp, tmp_buff);
		read(fd, tmp_buff, BUFFER_SIZE);
	}
	j = ft_strlen(temp);
	while (tmp_buff[i] != '\n')
		{
			temp[j++] = tmp_buff[i++];
		}
	temp[j] = '\0';
	// printf("%s\n", temp);
	return (temp);
}
char	*re_rest(char *tmp_buff)
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
	rest = malloc(sizeof(char) * j);
	j = 0;
	while (tmp_buff[i])
		rest[j++] = tmp_buff[i++];
	printf("rest:\n%s\n", rest);
	return (rest);
	// dans cette fonction je vais ajuster le reste pour qu'il soit correct pour le prochain appel de gnl
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*rest;
	static char	tmp_buff[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = readbuff(fd, tmp_buff);
	printf("line:\n%s\n", line);
	printf("tmp_buff:\n%s\n", tmp_buff);
	if (!tmp_buff || tmp_buff[0] == '\0')
		return (NULL);
	rest = re_rest(tmp_buff);
	// create_line();
	// nextline(tmp_buff);
	return (line);
}
int main()
{
	int fd;
	int i;
	char *line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	// printf("%s\n", line);
	return (0);
}
