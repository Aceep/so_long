/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:19:05 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:33:40 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	put_ptr(void *ptr_add)
{
	int						i;
	unsigned long long		add;
	char					*s;

	add = (unsigned long long) ptr_add;
	if (add == 0)
		return (ft_putstr("(nil)"), 5);
	ft_putstr("0x");
	i = 2;
	s = ft_utoa_base(add, "0123456789abcdef");
	i += ft_strlen(s);
	return (ft_putstr(s), free(s), i);
}
