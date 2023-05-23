/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:16:33 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:33:40 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg_info;
	size_t		w;

	va_start(arg_info, str);
	w = 0;
	while (*(str) != '\0')
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			w ++;
		}
		else
		{
			str ++;
			if (check_arg(&w, arg_info, str) != 0)
				return (0);
		}
		str ++;
	}
	return (w);
}
