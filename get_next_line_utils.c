/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:24:18 by ahomari           #+#    #+#             */
/*   Updated: 2023/12/15 18:11:19 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	printf("start %d\n", start);
	//printf("len %zu\n", len);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	printf("start %d\n", start);
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == cc)
		return ((char *)s + i);
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i_s1;
	int		i_s2;

	i_s1 = 0;
	i_s2 = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1 && s1[i_s1])
	{
		ptr[i_s1] = s1[i_s1];
		i_s1++;
	}
	while (s2 && s2[i_s2])
	{
		ptr[i_s1 + i_s2] = s2[i_s2];
		i_s2++;
	}
	ptr[i_s1 + i_s2] = '\0';
	return (ptr);
}
