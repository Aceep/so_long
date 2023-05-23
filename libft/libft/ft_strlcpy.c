/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:56:27 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	i;

	ret = ft_strlen(src);
	if (!dst || !src)
		return (0);
	i = 0;
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i ++;
	}
	if (size != 0)
		dst[i] = '\0';
	return (ret);
}
