/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:56:15 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/01 11:41:59 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exit_start(t_game *start)
{
	int		fd;
	char	*choice;

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
	free_game(start);
	exit(1);
}

int	start_game(t_game *start, char *again)
{
	int		ret;

	start->ptr = mlx_init();
	if (!start->ptr)
		error_exit(E_MLX, start);
	start->win = mlx_new_window(start->ptr, 1000, 679, "So_long");
	if (!start->win)
		error_exit(E_MLX, start);
	if (ft_atoi(again) == 0)
		start->end = -3;
	else if (ft_atoi(again) == 1)
		start->end = -2;
	cursor_init(start);
	all_xpm_for_start(start);
	if (image_errors(start))
		error_exit(E_IMG, start);
	play_start(start);
	ret = start->cursor.action;
	return (ret);
}

int	main(int ac, char **av)
{
	t_game	*start;

	if (ac == 2)
	{
		start = ft_calloc(1, sizeof(t_game));
		create_dico(start);
		start_game(start, av[1]);
	}
	return (0);
}
