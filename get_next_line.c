/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:06 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/11 18:47:38 by jowoundi         ###   ########.fr       */
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
	temp = line;
	// printf("%s\n", temp);
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
	// printf("%s\n", temp);
}
// void	start_next_line(char *tmp_buff)
// {
// 	int	i;
// 	int	j;
// 	int	len_tmp;
// 	char	*str;
// 	char	*tmp;
	
// }

void	next_line_bis(char **tmp_buff, char *str, int len_tmp, int i)
{
	int	j;
	char	*tmp;
	
	j = 0;
	while (str[len_tmp])
	{
		len_tmp++;
		j++;
	}
	tmp = malloc(sizeof(char) * j);
	if (!tmp)
		return ;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	*tmp_buff = tmp;
}

void	nextline(char *tmp_buff)
{
	int	i;
	int	j;
	int	len_tmp;
	char	*str;
	
	str = "";
	i = 0;
	j = 0;
	if (!tmp_buff)
		return ;
	while (tmp_buff[i])
		i++;
	i = 0;
	str = tmp_buff;
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] && str[i] == '\n')
		i++;
	len_tmp = i;
	next_line_bis(&tmp_buff, str, len_tmp, i);
	printf("%s\n", tmp_buff);
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
