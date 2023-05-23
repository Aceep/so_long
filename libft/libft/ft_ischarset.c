/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:49:58 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/10 14:51:21 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ischarset(int c, const char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i ++;
	}
	return (0);
}

// int main(void)
// {
//     char *str = "PEC";
//     char *str2 = "Jsuis";
//     int i;

//     i = 0;
//     while (str2[i] && ft_ischarset(str2[i], str) == 0)
//         i ++;
//     printf("%d", ft_ischarset(str2[i], str));
// }
