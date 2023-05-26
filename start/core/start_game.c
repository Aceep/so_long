/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:08 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/26 17:01:26 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	start_screen(t_game *start)
{
	int	x;

	x = 0;
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[4], 500 - 2 * 64, 150);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[0], 500 - 2 * 64, 200);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[1], 500 - 1 * 64, 200);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[2], 500, 200);
	mlx_put_image_to_window(start->ptr, start->win,
		start->img.preview[3], 564, 200);
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
	if (game->cursor.x > 500 - 2 * 64)
	{
		game->cursor.x -= IMG_W;
		game->cursor.action -= 1;
	}
}

void	cursor_move_right(t_game *game)
{
	if (game->cursor.x < 564)
	{
		game->cursor.x += IMG_W;
		game->cursor.action += 1;
	}
}

void	cursor_init(t_game *game)
{
	game->cursor.x = 500 - 2 * 64;
	game->cursor.y = 280;
	game->cursor.action = 0;
}
