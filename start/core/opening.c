/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:04:02 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/31 14:04:04 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_message(char *msg, t_game *start)
{
	int			i;
	int			val_let;
	int			x;
	static int	fno;
	int			y;

	y = 50;
	i = 0;
	x = 0;
	put_background(start);
	while (msg[i] && msg[i] != '.')
	{
		val_let = (char)msg[i] - 'a';
		if (ft_isalpha(msg[i]) == 1)
			mlx_put_image_to_window(start->ptr, start->win,
				start->img.alphabet[val_let], x, y);
		if ((x >= 368 && ft_isalpha(msg[i + 1])) || !ft_isalpha(msg[i]))
		{
			y += 70;
			x = 0;
		}
		i ++;
		x += 64;
	}
	fno ++;
	if (fno == 1000)
	{
		mlx_clear_window(start->ptr, start->win);
		start->end = -2;
	}
	return (0);
}

int	opening_door(t_game *start)
{
	static int	fno;
	static int	slw;

	mlx_put_image_to_window(start->ptr, start->win, start->img.door[fno], 0, 0);
	if ((slw % 10) == 0)
		fno ++;
	slw ++;
	if (fno == 41)
	{
		mlx_clear_window(start->ptr, start->win);
		return (1);
	}
	return (0);
}
