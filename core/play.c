/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:54 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/02 00:31:39 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_move(t_game *game)
{
	char		*nv;

	nv = ft_itoa(game->player.mv_count);
	if (game->end == 0)
		mlx_string_put(game->ptr, game->win, 10, 20, 0x00FF0000, nv);
	free(nv);
}

void	display_map(t_game *game)
{
	int			x;
	int			y;
	t_player	*current;

	y = -1;
	current = game->enemy;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (current && y == current->y && x == current->x)
			{
				anime_ennemy(game, x, y);
				current = current->next;
			}
			else
				mlx_put_image_to_window(game->ptr,
					game->win, game->map[y][x].img, IMG_W * x, IMG_H * y);
			if (y == game->player.y && x == game->player.x && game->end == 0)
				mlx_put_image_to_window(game->ptr, game->win, game->player.img,
					IMG_W * x, IMG_H * y);
		}
	}
	print_move(game);
}

int	key_hook(int key, t_game *game)
{
	int	fd;

	if (key == ESC_K)
		exit_game(game);
	if (game->end == 0)
	{
		if (key == K_W || key == K_U)
			move_up(game);
		if (key == K_A || key == K_L)
			move_left(game);
		if (key == K_S || key == K_DO)
			move_down(game);
		if (key == K_D || key == K_R)
			move_right(game);
	}
	if (key == ENTER && (game->end == 1 || game->end == 2))
	{
		fd = open("again", O_WRONLY | O_APPEND | O_CREAT, 0644);
		ft_putstr_fd("1", fd);
		close (fd);
		exit_game(game);
	}
	return (0);
}

int	loop_hook(t_game *game)
{
	static int	i;

	if (game->end > 0)
	{
		if (game->end == 2)
			big_bang(game);
		end_screen(game);
	}
	if ((++i % 1000) != 0)
		return (0);
	if (game->end == 0)
	{
		if (game->count.x > 0 && PATROL == 1 && (i % ENEMY_SPEED) == 0)
		{	
			enemy_patrol(game);
			i = 0;
		}
		display_map(game);
	}
	return (0);
}

void	play(t_game *game)
{
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->ptr, loop_hook, game);
	mlx_loop(game->ptr);
}
