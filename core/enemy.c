/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:24:39 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/01 17:53:13 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ennemy(t_game *game)
{
	t_player	*current;

	current = game->enemy;
	while (current)
	{
		if (game->player.y == current->y && game->player.x == current->x)
			game->end = 2;
		current = current->next;
	}
}

void	anime_ennemy(t_game *game, int x, int y)
{
	static int	fno;
	static int	i;

	mlx_put_image_to_window(game->ptr, game->win, game->img.ennemy[fno],
		IMG_W * x, IMG_H * y);
	if (i == game->count.x)
	{
		fno ++;
		i = 0;
	}
	if (fno == 19)
		fno = 0;
	i ++;
}

void	ft_playerlist(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x].value == 'X')
				ft_plradd_back(&game->enemy, init_enemy(game, x, y));
			x++;
		}
		y++;
	}
}

t_player	*init_enemy(t_game *game, int x, int y)
{
	t_player	*enemy;
	int			i;

	i = 0;
	enemy = malloc(sizeof(t_player));
	enemy->x = x;
	enemy->y = y;
	enemy->action = -1;
	enemy->mv_count = 0;
	enemy->next = NULL;
	enemy->dir = 0;
	game->map[enemy->y][enemy->x].value = '0';
	return (enemy);
}

void	ft_plradd_back(t_player **lst, t_player *newnode)
{
	t_player	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}
