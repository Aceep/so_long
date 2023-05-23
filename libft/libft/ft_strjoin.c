/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:56:10 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*dst;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	return (dst);
}
/*
int main(void)
{
	char *s1 = "Hello";
	char *s2 = ", je suis un test";
	ft_putstr(ft_strjoin(s1, s2));
	return (0);
}*/
