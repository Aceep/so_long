/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:19 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/17 16:33:11 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	end_screen(t_game *game)
{
	static int	x;
	static int	y;

	game->player.img = game->img.end[4];
	free_enemy_stack(&game->enemy);
	if (x == game->width && y < game->height)
	{
		x = 0;
		y++;
	}
	if (y == game->height)
	{
		mlx_put_image_to_window(game->ptr, game->win, game->img.end[game->choice],
				(game->width * IMG_W)/2 - IMG_W, game->height * IMG_H / 2 - 96);
		if (game->end == 1)
			mlx_put_image_to_window(game->ptr, game->win, game->img.end[5],
				(game->width * IMG_W)/2 - IMG_W, game->height * IMG_H / 4 * 3);
		if (game->end == 2)
			mlx_put_image_to_window(game->ptr, game->win, game->img.end[6],
				(game->width * IMG_W)/2 - IMG_W, game->height * IMG_H / 4 * 3);
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
	if (game->player.object == game->count.c && game->map[game->player.y][game->player.x].value == 'E')
	{
		ft_printf("Win\n");

	}
	if (game)
		free_game(game);
	exit(1);
}
