/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:32:26 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*tab;

	if (nitems != 0 && ((size * nitems) / nitems != size))
		return (NULL);
	tab = (void *)malloc(size * nitems);
	if (!tab)
		return (NULL);
	return (ft_bzero(tab, size * nitems), tab);
}
/*
int main(void)
{
	ft_calloc(SIZE_MAX, SIZE_MAX);
}*/