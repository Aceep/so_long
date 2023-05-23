/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:45:47 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/17 16:49:38 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map **map, int height)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (y < height && map[y])
		free(map[y++]);
	free(map);
}

void	destroy_image_v2(void *mlx_ptr, void *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx_ptr, img);
}

void	destroy_images(t_game *data)
{
	void			**p;
	int				i;

	p = (void **)&data->img;
	i = 0;
	while (i < IMG_NB)
		destroy_image_v2(data->ptr, p[i++]);
}

void	free_game_data(t_game *game)
{
	if (game->ptr)
	{
		destroy_images(game);
		if (game->win)
		{
			mlx_clear_window(game->ptr, game->win);
			mlx_destroy_window(game->ptr, game->win);
		}
		mlx_destroy_display(game->ptr);
		free(game->ptr);
	}
}

void	free_enemy_stack(t_player **enemy)
{
	t_player *tmp;

	if (!enemy || !(*enemy))
		return ;
	while (*enemy)
	{
		tmp = (*enemy)->next;
		free(*enemy);
		*enemy = tmp;
	}

}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_game_data(game);
	free_enemy_stack(&game->enemy);
	free_map(game->map, game->height);
	free(game);
}
