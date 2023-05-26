/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:58:04 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/26 16:58:05 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_hook_start(int key, t_game *start)
{
	if (key == ESC_K)
		exit_start(start);
	if (start->end == -2)
	{
		if (key == K_A || key == K_L)
			cursor_move_left(start);
		if (key == K_D || key == K_R)
			cursor_move_right(start);
		if (key == ENTER)
		{
			start->end = -1;
			mlx_clear_window(start->ptr, start->win);
		}
	}
	else if (start->end == -1)
	{
		if (key == K_W || key == K_U)
		{
			mlx_clear_window(start->ptr, start->win);
			choose_map(start, -1, 0);
		}
		if (key == K_S || key == K_DO)
		{
			mlx_clear_window(start->ptr, start->win);
			choose_map(start, 1, 0);
		}
		if (key == ENTER)
		{
			start->end = 0;
			choose_map(start, 0, key);
		}
	}
	return (0);
}

int	loop_hook_start(t_game *start)
{
	if (start->end == -2)
		start_screen(start);
	else if (start->end == -1)
		choose_map(start, 0, 0);
	else
		exit_start(start);
	return (0);
}

void	play_start(t_game *start)
{
	mlx_hook(start->win, 17, 0, exit_start, start);
	mlx_key_hook(start->win, key_hook_start, start);
	mlx_loop_hook(start->ptr, loop_hook_start, start);
	mlx_loop(start->ptr);
}
