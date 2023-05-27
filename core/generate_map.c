/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:43:54 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/27 14:39:36 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	assign_value(t_game *game, int y, char *line)
{
	int	x;

	x = 0;
	while (x < game->width)
	{
		game->map[y][x].value = line[x];
		game->map[y][x++].acc = 0;
	}
}

int	open_file(char *file_map, t_game *game)
{
	int	fd;

	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		error_exit(E_RD, game);
	return (fd);
}

void	wall_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		game->map[0][x].img = game->img.wall;
		game->map[game->height - 1][x].img = game->img.wall;
		x ++;
	}
	y = 1;
	while (y < game->height - 1)
	{
		game->map[y][0].img = game->img.wall;
		game->map[y][game->width - 1].img = game->img.wall;
		y ++;
	}
}

void	floor_map(t_game *game)
{
	int	x;
	int	y;

	y = 1;
	while (y < game->height - 1)
	{
		x = 1;
		while (x < game->width - 1)
		{
			if (game->map[y][x].value == '0')
				game->map[y][x].img = game->img.floor;
			if (game->map[y][x].value == 'C')
				game->map[y][x].img = game->img.collectible;
			if (game->map[y][x].value == 'P')
				game->map[y][x].img = game->img.floor;
			if (game->map[y][x].value == '1')
				game->map[y][x].img = game->img.wall;
			if (game->map[y][x].value == 'E')
				game->map[y][x].img = game->img.exit;
			if (game->map[y][x].value == 'X')
				game->map[y][x].img = game->img.floor;
			x ++;
		}
		y ++;
	}
}

void	generate_map(t_game *game)
{
	wall_map(game);
	floor_map(game);
}
