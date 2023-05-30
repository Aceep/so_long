/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolowercase_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:34:49 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/30 00:32:32 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_tolowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i ++;
	}
	return (str);
}

// int main(void)
// {
// 	char str[] = "Hello";
// 	ft_tolowercase(str);
// 	printf("%s", str);
// }