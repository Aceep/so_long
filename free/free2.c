/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:50:11 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/26 16:52:01 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_game_data(game);
	free_enemy_stack(&game->enemy);
	free_map(game->map, game->height);
	free(game);
}

void	free_gnl(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
