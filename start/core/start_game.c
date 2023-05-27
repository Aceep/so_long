/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:08 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/27 19:52:06 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	start_screen(t_game *start)
{
	int	x;

	x = 0;
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[4], 800 / 2 - 2 * IMG_W, 150);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[0], 800 / 2 - 2 * IMG_W, 200);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[1], 800 / 2 - IMG_W, 200);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[2], 800 / 2, 200);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[3], 800 / 2 + IMG_W, 200);
	while (x < 20)
	{
		mlx_put_image_to_window(start->ptr, start->win,
			start->img.preview[5], x * IMG_W, start->cursor.y);
		x ++;
	}
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.cursor, start->cursor.x, start->cursor.y);
}

void	cursor_move_left(t_game *game)
{
	if (game->cursor.x > 800 / 2 - 2 * IMG_W)
	{
		game->cursor.x -= IMG_W;
		game->cursor.action -= 1;
	}
}

void	cursor_move_right(t_game *game)
{
	if (game->cursor.x < 800 / 2 + IMG_W)
	{
		game->cursor.x += IMG_W;
		game->cursor.action += 1;
	}
}

void	cursor_init(t_game *game)
{
	game->cursor.x = 800 / 2 - 2 * IMG_W;
	game->cursor.y = 280;
	game->cursor.action = 0;
}
