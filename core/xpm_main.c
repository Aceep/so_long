/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:49:45 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/17 15:51:54 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	xpm_preview(t_game *start)
{
	int	w;
	int	h;

	start->img.preview[0] = mlx_xpm_file_to_image(start->ptr, P_YELLOW, &w, &h);	
	start->img.preview[1] = mlx_xpm_file_to_image(start->ptr, P_RED, &w, &h);	
	start->img.preview[2] = mlx_xpm_file_to_image(start->ptr, P_GREEN, &w, &h);	
	start->img.preview[3] = mlx_xpm_file_to_image(start->ptr, P_BLUE, &w, &h);
	start->img.preview[4] = mlx_xpm_file_to_image(start->ptr, INSTRUCT_START, &w, &h);
	start->img.preview[5] = mlx_xpm_file_to_image(start->ptr, S_BLACK, &w, &h);
	start->img.cursor = mlx_xpm_file_to_image(start->ptr, CURSOR, &w, &h);
}

void	xpm_ingame_character(t_game *game)
{
	int	w;
	int	h;

	game->img.character[0] = mlx_xpm_file_to_image(game->ptr, DINO, &w, &h);
	game->img.character[1] = mlx_xpm_file_to_image(game->ptr, DINO_RED, &w, &h);
	game->img.character[2] = mlx_xpm_file_to_image(game->ptr, DINO_GREEN, &w, &h);
	game->img.character[3] = mlx_xpm_file_to_image(game->ptr, DINO_BLUE, &w, &h);
	game->img.character[4] = mlx_xpm_file_to_image(game->ptr, DINO_LEFT, &w, &h);
	game->img.character[5] = mlx_xpm_file_to_image(game->ptr, DINO_RED_LEFT, &w, &h);
	game->img.character[6] = mlx_xpm_file_to_image(game->ptr, DINO_GREEN_LEFT, &w, &h);
	game->img.character[7] = mlx_xpm_file_to_image(game->ptr, DINO_BLUE_LEFT, &w, &h);
}

void	xpm_end_screen(t_game *game)
{
	int	w;
	int	h;

	game->img.end[0] = mlx_xpm_file_to_image(game->ptr, YELLOW, &w, &h);
	game->img.end[1] = mlx_xpm_file_to_image(game->ptr, RED, &w, &h);
	game->img.end[2] = mlx_xpm_file_to_image(game->ptr, GREEN, &w, &h);
	game->img.end[3] = mlx_xpm_file_to_image(game->ptr, BLUE, &w, &h);
	game->img.end[4] = mlx_xpm_file_to_image(game->ptr, BLACK, &w, &h);
	game->img.end[5] = mlx_xpm_file_to_image(game->ptr, WINNER, &w, &h);
	game->img.end[6] = mlx_xpm_file_to_image(game->ptr, LOSE, &w, &h);
}
void	xpm_init(t_game *game)
{
	int	w;
	int	h;

	xpm_preview(game);
	xpm_ingame_character(game);
	xpm_end_screen(game);
	game->img.floor = mlx_xpm_file_to_image(game->ptr, GRASS, &w, &h);
	game->img.wall = mlx_xpm_file_to_image(game->ptr, BRICK, &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->ptr, EXIT, &w, &h);
	game->img.collectible = mlx_xpm_file_to_image(game->ptr, CHERRY, &w, &h);
	game->img.ennemy[0] = mlx_xpm_file_to_image(game->ptr, OPPO, &w, &h);
	game->img.ennemy[1] = mlx_xpm_file_to_image(game->ptr, OPPO2, &w, &h);
	game->img.ennemy[2] = mlx_xpm_file_to_image(game->ptr, OPPO3, &w, &h);
	game->img.ennemy[3] = mlx_xpm_file_to_image(game->ptr, OPPO4, &w, &h);
	game->img.ennemy[4] = mlx_xpm_file_to_image(game->ptr, OPPO5, &w, &h);
	game->img.ennemy[5] = mlx_xpm_file_to_image(game->ptr, OPPO6, &w, &h);
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
