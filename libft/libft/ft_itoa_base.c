/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:30:41 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_len(long long add, char *base)
{
	int			n;
	long long	base_len;

	base_len = ft_strlen(base);
	n = 1;
	while (add >= base_len)
	{
			add /= base_len;
			n ++;
	}
	return (n);
}

char	*ft_itoa_base(long long add, char *base)
{
	char	*str;
	int		base_len;
	int		add_len;

	base_len = ft_strlen(base);
	add_len = ft_len(add, base);
	str = ft_calloc((add_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (add_len)
	{
		add_len -= 1;
		str[add_len] = base[add % base_len];
		add /= base_len;
	}
	return (str);
}

size_t	ft_ulen(unsigned long long int add, char *base)
{
	int				n;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	n = 1;
	while (add >= base_len)
	{
			add /= base_len;
			n ++;
	}
	return (n);
}

char	*ft_utoa_base(unsigned long long int add, char *base)
{
	char				*str;
	int					base_len;
	unsigned int		add_len;

	base_len = ft_strlen(base);
	add_len = ft_ulen(add, base);
	str = ft_calloc((add_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (add_len)
	{
		add_len -= 1;
		str[add_len] = base[add % base_len];
		add /= base_len;
	}
	return (str);
}
