/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:19 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/02 00:58:01 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	image_end(t_game *game)
{
	mlx_put_image_to_window(game->ptr,
		game->win, game->img.end[game->choice],
		(game->width * IMG_W) / 2 - IMG_W,
		game->height * IMG_H / 2 - 96);
	if (game->end == 1)
	{
		mlx_put_image_to_window(game->ptr, game->win, game->img.end[5],
			(game->width * IMG_W) / 2 - IMG_W,
			game->height * IMG_H / 4 * 3);
		mlx_put_image_to_window(game->ptr,
			game->win, game->img.end[7],
			(game->width * IMG_W) / 2 - IMG_W,
			game->height * IMG_H / 2 - 3 * IMG_H);
	}
	if (game->end == 2)
		mlx_put_image_to_window(game->ptr, game->win, game->img.end[6],
			(game->width * IMG_W) / 2 - IMG_W,
			game->height * IMG_H / 4 * 3);
}

void	end_screen(t_game *game)
{
	static int	x;
	static int	y;

	free_enemy_stack(&game->enemy);
	if (x == game->width && y < game->height)
	{
		x = 0;
		y++;
	}
	if (y == game->height)
	{
		image_end(game);
	}
	else if (x < game->width)
	{
		game->map[y][x++].img = game->img.end[4];
		display_map(game);
	}
	mlx_string_put(game->ptr, game->win, (game->width * IMG_W) / 2 - 60,
		IMG_H * game->height - 2, 16711680, "Press ESC to quit");
}

int	exit_game(t_game *game)
{
	if (game->player.object == game->count.c
		&& game->map[game->player.y][game->player.x].value == 'E')
		ft_printf("\033[1;32mWin\n\033[0m");
	else
		ft_printf("\033[1;31mLose\n\033[0m");
	if (game)
		free_game(game);
	exit(0);
}
