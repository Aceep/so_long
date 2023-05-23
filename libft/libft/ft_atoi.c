/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:31:36 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/25 14:31:31 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n'
		|| str[i] == '\f'
		|| str[i] == '\r'
		|| str[i] == '\v')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i ++;
	}
	return (sign * nb);
}

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	if (av[1])
// 	{
// 		printf("%d\n", atoi(av[1]));
// 		printf("%d\n", ft_atoi(av[1]));
// 	}
// 	return (0);
// }
