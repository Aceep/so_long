/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:43:45 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/17 16:24:12 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	enemy_move_right(t_game *game, t_player *current)
{
	static char  previous_value;
	void	*previous_img;
	
	previous_img = game->map[current->y][current->x + 1].img;
	previous_value = game->map[current->y][current->x + 1].value;
	if (current->x + 1 == game->player.x && current->y == game->player.y)
		game->end = 2;
	current->x += 1;
	if (game->map[current->y][current->x + 1].value == '1')
			current->dir = 1;
	return (0);
}


int	enemy_move_left(t_game *game, t_player *current)
{
	static char  previous_value;
	void	*previous_img;
	
	previous_img = game->map[current->y][current->x - 1].img;
	previous_value = game->map[current->y][current->x - 1].value;
	if (current->x - 1 == game->player.x && current->y == game->player.y)
		game->end = 2;
	current->x -= 1;
	if (game->map[current->y][current->x - 1].value == '1')
			current->dir = 0;
	return (0);
}

void	check_oppo(t_player *current, t_game *game)
{
	t_player	*compare;

	compare = game->enemy;
	while (compare)
	{
		if (current->y == compare->y && (compare->x == current->x + 1|| compare->x == current->x + 2))
			current->dir = 1;
		else if (current->y == compare->y && (compare->x == current->x - 1 || compare->x == current->x - 2))
			current->dir = 0;
		compare = compare->next;
	}
}
int	enemy_patrol(t_game *game)
{
	int				x;
	static t_player	*current;


	current = game->enemy;
	while (current)	
	{
		if ((game->map[current->y][current->x + 1].value != '1'
			&& game->map[current->y][current->x + 1].value != 'X') && current->dir == 0)
			enemy_move_right(game, current);
		else if ((game->map[current->y][current->x - 1].value != '1'
				&& game->map[current->y][current->x - 1].value != 'X') && current->dir == 1)
			enemy_move_left(game, current);
		check_oppo(current, game);
		current = current->next;
	}
	return (0);
}
