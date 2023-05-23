/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:57:28 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	last = -1;
	i = 0;
	if ((char)c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	while (s[i])
	{
		while (s[i] != (char)c && s[i])
			i ++;
		if (s[i] == (char)c)
		{
			last = i;
			i ++;
		}
	}
	if (last == -1)
		return (NULL);
	return (&((char *)s)[last]);
}
