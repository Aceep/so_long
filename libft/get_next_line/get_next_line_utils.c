/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:46:07 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/25 15:24:29 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strchr_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i ++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	char	*dst;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	dst = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!(dst))
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		i ++;
		j ++;
	}
	dst[i] = '\0';
	free (s1);
	return (dst);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_strlen_gnl(s) - start;
	if (start > ft_strlen_gnl(s))
		size = 0;
	else if (len > size)
		len = size;
	else if (len < size)
		size = len;
	dst = (char *)(malloc(sizeof(char) * (size + 1)));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size && s[start])
	{
		dst[i] = s[start];
		i ++;
		start ++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strdup_gnl(const char *str)
{
	int		len;
	char	*cpy;
	int		i;

	i = 0;
	len = ft_strlen_gnl(str);
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i ++;
	}
	cpy[i] = '\0';
	return (cpy);
}
