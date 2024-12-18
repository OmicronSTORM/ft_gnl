/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:30 by jowoundi          #+#    #+#             */
/*   Updated: 2024/12/18 15:01:44 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final_string;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	final_string = malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!final_string)
		return (0);
	while (s1[i])
	{
		final_string[i] = s1[i];
		i++;
	}
	while (s2[j])
		final_string[i++] = s2[j++];
	final_string[i] = '\0';
	return (final_string);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*mem;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	mem = malloc(sizeof(char) * size + 1);
	if (!mem)
		return (0);
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}