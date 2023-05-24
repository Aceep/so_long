/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:33:13 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/24 03:20:51 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	wall_check(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x].value != '1'
				|| game->map[game->height - 1][x].value != '1')
			error_exit(E_WALL, game);
		x ++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0].value != '1'
				|| game->map[y][game->width - 1].value != '1')
			error_exit(E_WALL, game);
		y ++;
	}
	return (0);
}

int	check_type(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (!ft_ischarset(game->map[y][x].value, "10CEPXD"))
				error_exit_charset(E_TYPE, game, game->map[y][x].value);
			if (game->map[y][x].value == 'P')
				game->count.p ++;
			if (game->map[y][x].value == 'E')
				game->count.e ++;
			if (game->map[y][x].value == 'C')
				game->count.c ++;
			if (game->map[y][x].value == 'X')
				game->count.x ++;
			x ++;
		}
		y ++;
	}
	return (0);
}

void	check_rec(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i ++;
	if (i != game->width)
		error_exit(E_REC, game);
}

int	map_error(t_game *game)
{
	static int	error;

	if (!error)
		error = wall_check(game);
	if (!error)
		error = check_type(game);
	if (!error)
		error = path_check(game);
	if ( game->count.p != 1 )
		error_exit_count(E_COUNT, game, "No character or too much character");
	if ( game->count.e != 1 )
		error_exit_count(E_COUNT, game, "No exit or multiple exit");
	if ( game->count.c < 1 )
		error_exit_count(E_COUNT, game, "No collectible");
	return (error);
}

int	check_ber(char *av)
{
	char	*ext;

	ext = ft_strrchr(av, '.');
	if (ext != NULL)
		return (ft_strcmp(ext, ".ber\0") == 0);
	return (0);
}
