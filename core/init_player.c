/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:33:03 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/10 14:41:44 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*find(t_game *game, int c)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x].value == c)
				return (&game->map[y][x]);
			x ++;
		}
		y ++;
	}
	return (NULL);
}

void	init_player(t_game *game)
{
	t_map	*player;

	player = find(game, 'P');
	game->player.x = player->x;
	game->player.y = player->y;
	game->player.action = -1;
	game->player.mv_count = 0;
	game->player.img = game->img.character[game->choice];
	game->map[player->y][player->x].value = '0';
	game->player.next = NULL;
}
