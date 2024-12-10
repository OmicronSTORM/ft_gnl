/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:06 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/10 18:03:29 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	readbuff(int fd, char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = "";
	while (!ft_strchr(line, '\n'))
	{
		temp = ft_strjoin(temp, line);
		read(fd, line, BUFFER_SIZE);
	}
	j = ft_strlen(temp);
	while (line[i] != '\n')
		{
			temp[j++] = line[i++];
		}
	temp[j] = '\0';
	printf("%s\n", temp);
}

void	nextline(char *tmp_buff)
{
	int	i;
	int	j;
	int	len_tmp;
	char	*str;
	char	*tmp;
	
	str = "";
	i = 0;
	j = 0;
	if (!tmp_buff)
		return ;
	while (tmp_buff[i])
		i++;
	printf("%d\n", i);
	i = 0;
	str = tmp_buff;
	printf("%s\n", str);
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] && str[i] == '\n')
		i++;
	len_tmp = i;
	while (str[len_tmp])
	{
		j++;
		len_tmp++;
	}
	printf("%d\n", j);
	printf("%d\n", i);
	tmp = malloc(sizeof(char) * j);
	j = 0;
	// printf("%s\n", tmp);
	while(str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	printf("%s\n", tmp);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	tmp_buff[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbuff(fd, tmp_buff);
	if (!tmp_buff || tmp_buff[0] == '\0')
		return (NULL);
	nextline(tmp_buff);
	return (NULL);
}
int main()
{
	int fd;
	int i;
	
	i = 0;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
