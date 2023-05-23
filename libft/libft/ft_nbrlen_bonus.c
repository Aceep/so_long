/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:49:57 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nbrlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count ++;
	}
	while (n >= 10)
	{
		n /= 10;
		count ++;
	}
	count ++;
	return (count);
}
/*
int	main(void)
{
	int n = 123;
	int count = 0;
	ft_putnbr(ft_nbrlen(n, count));
	return (0);
}*/
