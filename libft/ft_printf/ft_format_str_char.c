/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:07:29 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:33:40 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	put_char(unsigned int c)
{
	ft_putchar(c);
	return (1);
}

int	put_str(char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"), 6);
	ft_putstr(s);
	return (ft_strlen(s));
}
