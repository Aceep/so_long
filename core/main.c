/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:40 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/26 17:12:45 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	print_map(t_game *game)
// {
// 	int			i;
// 	int			j;
// 	t_player	*current;

// 	i = 0;
// 	current = game->enemy;
// 	while (i < game->height)
// 	{
// 		j = 0;
// 		while (j < game->width)
// 		{
// 			if (current && i == current->y && j == current->x)
// 			{
// 				ft_printf("X");
// 				current = current->next;
// 			}
// 			else if (i == game->player.y && j == game->player.x)
// 				ft_printf("P");
// 			else
// 				ft_printf("%c", game->map[i][j].value);
// 			j ++;
// 		}
// 		write(1, "\n", 1);
// 		i ++;
// 	}
// 	write(1, "\n", 1);
// }

char	*remove_backslashn(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i ++;
	map[i] = '\0';
	return (map);
}

int	choice_file(char *av)
{
	t_game	*game;
	char	*map;
	int		fd;

	fd = open("choice", O_RDONLY);
	map = get_next_line(fd);
	map = remove_backslashn(map);
	if (map != NULL)
	{
		if (check_ber(map) != 1)
			error_exit(E_EXT, 0);
		game = create_game(map, 0);
		while (map)
		{	
			free(map);
			map = get_next_line(fd);
		}
		play(game);
		return (free_game(game), 0);
	}	
	else
		return (error_exit(E_ARG, NULL), 1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2 && av[1][0] == 'o')
		choice_file(av[1]);
	else if (ac == 2)
	{
		if (check_ber(av[1]) != 1)
			error_exit(E_EXT, 0);
		game = create_game(av[1], 1);
		play(game);
		return (free_game(game), 0);
	}	
	else
		return (error_exit(E_ARG, NULL), 1);
	return (0);
}
