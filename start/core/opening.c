/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:04:02 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/03 12:40:02 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	if_is_alpha(t_game *start, int i, int x, int y)
{
	int	val_let;

	if (ft_isalpha(i) == 1)
	{
		val_let = i - 'a';
		mlx_put_image_to_window(start->ptr, start->win,
			start->img.alphabet[val_let], x, y);
		x += 64;
	}
	return (x);
}

int	if_is_digit(t_game *start, char i, int x, int y)
{
	int	val_let;

	if (ft_isdigit(i) == 1)
	{
		val_let = i - '0';
		mlx_put_image_to_window(start->ptr, start->win,
			start->img.numbers[val_let], x, y);
		x += 64;
	}
	return (x);
}

void	put_landscape(t_game *start)
{
	if (start->end == -3)
		mlx_put_image_to_window(start->ptr, start->win,
			start->img.background[35], 0, 0);
	else
		put_background(start);
}

void	put_message(char *msg, t_game *start)
{
	int			i;
	int			x;
	static int	fno;
	int			y;

	y = 100;
	i = -1;
	x = 200;
	put_landscape(start);
	while (msg[++i] && msg[i] != '.')
	{
		x = if_is_alpha(start, msg[i], x, y);
		x = if_is_digit(start, msg[i], x, y);
		if ((x > 950 && ft_isalpha(msg[i + 1]))
			|| (!ft_isalpha(msg[i]) && !ft_isdigit(msg[i])))
		{
			y += 80;
			x = 200;
		}
	}
	if (++fno == 300 && start->end == -3)
	{
		mlx_clear_window(start->ptr, start->win);
		start->end = -2;
	}
}

int	opening_door(t_game *start)
{
	static int	fno;
	static int	slw;

	mlx_put_image_to_window(start->ptr, start->win, start->img.door[fno], 0, 0);
	if ((slw % 4) == 0)
		fno ++;
	slw ++;
	if (fno == 41)
	{
		mlx_clear_window(start->ptr, start->win);
		return (1);
	}
	return (0);
}
