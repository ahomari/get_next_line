/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:06:56 by ahomari           #+#    #+#             */
/*   Updated: 2023/12/14 19:07:46 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fun(int fd, char *buff, char *tmp)
{
	int		read_line;
	char	*line;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
			return (free(tmp), NULL);
		else if (read_line == 0)
			break ;
		buff[read_line] = '\0';
		if (!tmp)
			tmp = ft_strdup("");
		line = tmp;
		tmp = ft_strjoin(line, buff);
		free(line);
		line = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (tmp);
}

static char	*ft_skip(char *line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	// printf("value de i : %zu\n", i);
	if (line[i] == '\0')
		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*tmp == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	line = read_fun(fd, buff, tmp);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	tmp = ft_skip(line);
	return (line);
}