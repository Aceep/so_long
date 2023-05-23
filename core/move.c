/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:23 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/10 14:40:20 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (game->map[player->y - 1][player->x].value != '1')
	{
		player->action = 1;
		ft_printf("%d move(s)\n", ++(game->player.mv_count));
		if (game->map[player->y - 1][player->x].value == 'C')
		{
			player->object ++;
			game->map[player->y - 1][player->x].value = '0';
			game->map[player->y - 1][player->x].img = game->img.floor;
		}
		player->y -= 1;
		if (game->map[player->y][player->x].value == 'E'
				&& player->object == game->count.c)
			game->end = 1;
		ennemy(game);
	}
}

void	move_left(t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (game->map[player->y][player->x - 1].value != '1')
	{
		player->action = 1;
		ft_printf("%d move(s)\n", ++(game->player.mv_count));
		if (game->map[player->y][player->x - 1].value == 'C')
		{
			player->object ++;
			game->map[player->y][player->x - 1].value = '0';
			game->map[player->y][player->x - 1].img = game->img.floor;
		}
		player->x -= 1;
		if (game->map[player->y][player->x].value == 'E'
				&& player->object == game->count.c)
			game->end = 1;
		player->img = game->img.character[game->choice + 4];
		ennemy(game);
	}
}

void	move_down(t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (game->map[player->y + 1][player->x].value != '1')
	{
		player->action = 1;
		ft_printf("%d move(s)\n", ++(game->player.mv_count));
		if (game->map[player->y + 1][player->x].value == 'C')
		{
			player->object ++;
			game->map[player->y + 1][player->x].value = '0';
			game->map[player->y + 1][player->x].img = game->img.floor;
		}
		player->y += 1;
		if (game->map[player->y][player->x].value == 'E'
				&& player->object == game->count.c)
			game->end = 1;
		ennemy(game);
	}
}

void	move_right(t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (game->map[player->y][player->x + 1].value != '1')
	{
		player->action = 1;
		ft_printf("%d move(s)\n", ++(game->player.mv_count));
		if (game->map[player->y][player->x + 1].value == 'C')
		{
			player->object ++;
			game->map[player->y][player->x + 1].value = '0';
			game->map[player->y][player->x + 1].img = game->img.floor;
		}
		player->x += 1;
		if (game->map[player->y][player->x].value == 'E'
				&& player->object == game->count.c)
			game->end = 1;
		player->img = game->img.character[game->choice];
		ennemy(game);
	}
}
