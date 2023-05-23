/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:43:13 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_nb(int size, char *nbr, long long int i)
{
	nbr[size] = '\0';
	while (i)
	{
		size --;
		nbr[size] = (i % 10) + '0';
		i /= 10;
	}
	if (nbr[1] != '\0' && size == 1)
		nbr[0] = '-';
	else if (nbr[1] == '\0' && size == 1)
		nbr[0] = '0';
}

char	*ft_itoa(int n)
{
	char			*nbr;
	long long int	i;
	size_t			size;

	i = n;
	if (i <= 0)
	{
		i = -i;
		size = 1;
	}
	else
		size = 0;
	while (n)
	{
		n /= 10;
		size ++;
	}
	nbr = (char *)malloc(sizeof(char) * (size + 1));
	if (!(nbr))
		return (0);
	ft_nb(size, nbr, i);
	return (nbr);
}

void	ft_nbu(int size, char *nbr, unsigned long long int i)
{
	nbr[size] = '\0';
	while (i)
	{
		size --;
		nbr[size] = (i % 10) + '0';
		i /= 10;
	}
	if (nbr[1] != '\0' && size == 1)
		nbr[0] = '-';
	else if (nbr[1] == '\0' && size == 1)
		nbr[0] = '0';
}

char	*ft_utoa(long long n)
{
	char					*nbr;
	unsigned long long int	i;
	size_t					size;

	i = n;
	if (i <= 0)
	{
		i = -i;
		size = 1;
	}
	else
		size = 0;
	while (n)
	{
		n /= 10;
		size ++;
	}
	nbr = (char *)malloc(sizeof(char) * (size + 1));
	if (!(nbr))
		return (0);
	ft_nb(size, nbr, i);
	return (nbr);
}

/*#include <limits.h>
#include <stdio.h>
int	main(void)
{
	int n = INT_MIN;
	printf("\n%ld\n", ft_strlen(ft_itoa(n)));
	return (0);
}*/
