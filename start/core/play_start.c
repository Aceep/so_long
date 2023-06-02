/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:58:04 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/01 10:19:15 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_choose_map(t_game *start, int key)
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
	return (0);
}

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
		key_choose_map(start, key);
	return (0);
}

int	loop_hook_start(t_game *start)
{
	static int	i;
	static int	end;

	if (++i != 1500)
		return (0);
	if (start->end == -3 && end == 0)
		end = opening_door(start);
	else if (start->end == -3 && end == 1)
		put_message("welcome to solong", start);
	if (start->end == -2)
		start_screen(start);
	if (start->end == -1)
		choose_map(start, 0, 0);
	if (start->end == 0)
		exit_start(start);
	i = 0;
	return (0);
}

void	play_start(t_game *start)
{
	mlx_hook(start->win, 17, 0, exit_start, start);
	mlx_key_hook(start->win, key_hook_start, start);
	mlx_loop_hook(start->ptr, loop_hook_start, start);
	mlx_loop(start->ptr);
}
