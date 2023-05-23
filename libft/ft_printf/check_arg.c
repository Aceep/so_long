/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:53:45 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:33:40 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_arg(size_t *wr, va_list arg_info, const char *str)
{
	if (*str == 'd' || *str == 'i')
		*wr += put_nbr((int)va_arg(arg_info, int));
	else if (*str == 'u')
		*wr += put_uns((unsigned int)va_arg(arg_info, unsigned int));
	else if (*str == 'c')
		*wr += put_char((int) va_arg(arg_info, int));
	else if (*str == 's')
		*wr += put_str((char *)va_arg(arg_info, char *));
	else if (*str == '%')
		*wr += put_char('%');
	else if (*str == 'p')
		*wr += put_ptr((void *)va_arg(arg_info, void *));
	else if (*str == 'x' || *str == 'X')
		*wr += put_hexa((unsigned int)va_arg(arg_info, unsigned int), *str);
	return (0);
}
