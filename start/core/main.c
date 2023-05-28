/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:56:15 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/28 09:22:57 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exit_start(t_game *start)
{
	int		fd;
	char	*choice;

	free_game_data_start(start);
	if (start->map_choice != NULL)
	{
		fd = open("choice", O_WRONLY | O_APPEND | O_CREAT, 0644);
		choice = ft_itoa(start->cursor.action);
		ft_putstr_fd("maps/", fd);
		ft_putstr_fd(start->map_choice, fd);
		ft_putstr_fd(choice, fd);
		free(start->map_choice);
		close (fd);
		free(choice);
	}
	free(start);
	exit(1);
}

int	start_game(t_game *start)
{
	int		ret;

	start = ft_calloc(1, sizeof(t_game));
	start->ptr = mlx_init();
	if (!start->ptr)
		error_exit(E_MLX, start);
	start->win = mlx_new_window(start->ptr, 498, 338, "So_long");
	if (!start->win)
		error_exit(E_MLX, start);
	start->end = -3;
	cursor_init(start);
	all_xpm_for_start(start);
	play_start(start);
	ret = start->cursor.action;
	return (ret);
}

int	main(void)
{
	t_game	*start;

	start = malloc(sizeof(t_game));
	start_game(start);
	start_screen(start);
}
