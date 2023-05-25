/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:25:30 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/15 13:26:21 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood(t_map **map, t_map *player)
{
	map[player->y][player->x].acc = 1;
	if (map[player->y][player->x + 1].value != '1'
			&& map[player->y][player->x + 1].value != 'X'
			&& map[player->y][player->x + 1].acc == 0)
		flood(map, &map[player->y][player->x + 1]);
	if (map[player->y + 1][player->x].value != '1'
			&& map[player->y + 1][player->x].value != 'X'
			&& map[player->y + 1][player->x].acc == 0)
		flood(map, &map[player->y + 1][player->x]);
	if (map[player->y][player->x - 1].value != '1'
			&& map[player->y][player->x - 1].value != 'X'
			&& map[player->y][player->x - 1].acc == 0)
		flood(map, &map[player->y][player->x - 1]);
	if (map[player->y - 1][player->x].value != '1'
			&& map[player->y - 1][player->x].value != 'X'
			&& map[player->y - 1][player->x].acc == 0)
		flood(map, &map[player->y - 1][player->x]);
}

int	path_check(t_game *game)
{
	t_map	*start;
	int		x;
	int		y;

	start = find(game, 'P');
	flood(game->map, start);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (ft_ischarset(game->map[y][x].value, "EC"))
			{
				if (game->map[y][x].acc != 1)
					return (E_PATH);
			}
			x++;
		}
		y++;
	}
	return (0);
}
