/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_bang.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:58:49 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/02 08:59:14 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	big_bang(t_game *game)
{
	static int	fno;
	static int	slow;

	game->player.img = game->img.floor;
	display_map(game);
	while (fno != 10)
	{
		mlx_put_image_to_window(game->ptr, game->win, game->img.crash[fno],
			game->player.x * IMG_W, game->player.y * IMG_H);
		if (slow % 6000 == 0)
			fno ++;
		slow ++;
	}
	return (1);
}
