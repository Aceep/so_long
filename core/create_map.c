/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:34 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/27 14:39:16 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_dim(t_game *game, char *file_map)
{
	int		fd;
	char	*line;

	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		error_exit(E_RD, game);
	line = get_next_line(fd);
	if (!line)
		error_exit(E_EMPTY, game);
	game->width = ft_strlen(line) - 1;
	game->height = 0;
	while (line)
	{
		game->height ++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->width >= 40 || game->height >= 22)
		error_exit(E_OVER, game);
	game->end = START_SCREEN;
}

t_map	**init_map(t_game *game)
{
	int		x;
	int		y;
	t_map	**map;

	map = malloc(sizeof(t_map *) * game->height);
	if (!map)
		error_exit(E_MEM, game);
	y = 0;
	while (y < game->height)
	{
		map[y] = ft_calloc(1, sizeof(t_map) * game->width);
		if (!map[y])
			error_exit(E_MEM, game);
		x = 0;
		while (x < game->width)
		{
			map[y][x].x = x;
			map[y][x++].y = y;
		}
		y ++;
	}
	return (map);
}

void	put_map_value(t_game *game, char *file_map)
{
	int		fd;
	char	*line;
	int		y;

	fd = open_file(file_map, game);
	y = -1;
	while (++y < game->height)
	{
		line = get_next_line(fd);
		check_rec(line, game);
		if (!line)
			error_exit(E_GNL, game);
		assign_value(game, y, line);
		free(line);
	}
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
}

void	put_choice_value(t_game *game)
{
	char	*tmp;
	int		fd;

	fd = open("choice", O_RDONLY);
	tmp = get_next_line(fd);
	free(tmp);
	tmp = get_next_line(fd);
	game->choice = ft_atoi(tmp);
	free(tmp);
}

t_game	*create_game(char *file_map, int c)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		error_exit(E_MEM, game);
	map_dim(game, file_map);
	game->map = init_map(game);
	put_map_value(game, file_map);
	if (map_error(game))
		error_exit(map_error(game), game);
	game->end = 0;
	game->ptr = mlx_init();
	if (!game->ptr)
		error_exit(E_MLX, game);
	game->win = mlx_new_window(game->ptr,
			IMG_W * game->width, IMG_H * game->height, "So_long");
	if (!game->win)
		error_exit(E_MLX, game);
	xpm_init(game);
	generate_map(game);
	ft_playerlist(game);
	charac_choice(c, game);
	init_player(game);
	return (game);
}
