/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmedomari <ahmedomari@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:24:18 by ahomari           #+#    #+#             */
/*   Updated: 2023/12/09 16:21:41 by ahmedomari       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
    size_t  n;

    n = count * size;
	ptr = (void *)(malloc(n));
	if (!ptr)
		return (NULL);
    while (n--)
    {
        ptr[n] = 0;
    }
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
    int     i_s1;
    int     i_s2;

    i_s1 = 0;
    i_s2 = 0;
	ptr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
    while (s1)
    {
        ptr[i_s1] = s1[i_s1];
        i_s1++; 
    }
    while (s2)
    {
        ptr[i_s1 + i_s2] = s2[i_s2];
        i_s2++;
    }
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
    int     i;

    i = 0;
	ptr = malloc((ft_strlen(s1) + 1)* sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
	return (ptr);
}

