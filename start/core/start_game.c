/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:08 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/01 11:39:34 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	start_screen(t_game *start)
{
	int	x;

	x = 0;
	put_background(start);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[4], 1000 / 2 - 2 * IMG_W, 100);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[0], 1000 / 2 - 2 * IMG_W, 150);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[1], 1000 / 2 - IMG_W, 150);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[2], 1000 / 2, 150);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[3], 1000 / 2 + IMG_W, 150);
	// while (x < 20)
	// {
	// 	mlx_put_image_to_window(start->ptr, start->win,
	// 		start->img.preview[5], x * IMG_W, start->cursor.y);
	// 	x ++;
	// }
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.cursor, start->cursor.x, start->cursor.y);
}

void	cursor_move_left(t_game *game)
{
	if (game->cursor.x > 1000 / 2 - 2 * IMG_W)
	{
		game->cursor.x -= IMG_W;
		game->cursor.action -= 1;
	}
}

void	cursor_move_right(t_game *game)
{
	if (game->cursor.x < 1000 / 2 + IMG_W)
	{
		game->cursor.x += IMG_W;
		game->cursor.action += 1;
	}
}

void	cursor_init(t_game *game)
{
	game->cursor.x = 1000 / 2 - 2 * IMG_W;
	game->cursor.y = 250;
	game->cursor.action = 0;
}
