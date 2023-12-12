/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmedomari <ahmedomari@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:06:56 by ahomari           #+#    #+#             */
/*   Updated: 2023/12/10 13:43:02 by ahmedomari       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *tmp;
	char		*line;
	char		*buff;
	int			read_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buff[read_line] = '\0';
		if (!tmp)
			tmp = ft_strdup("");
			
		

	}
}

size_t ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}