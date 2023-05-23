/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:40 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/17 16:20:03 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_game *game)
{
	int	i;
	int	j;
	t_player	*current;

	i = 0;
	current = game->enemy;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{

			if ( current && i == current->y && j == current->x)
			{
				ft_printf("X");
				current = current->next;
			}
			else if (i == game->player.y && j == game->player.x)
				ft_printf("P");
			else
				ft_printf("%c", game->map[i][j].value);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
	write(1, "\n", 1);
}

void	game_option_choice(t_game *game)
{
	ft_printf("Enemy patrol activation ?\n");
	if (ft_strchr(get_next_line(0), '1') != NULL)
		game->opt.patrol = 1;
	else
		game->opt.patrol = 0;
}

char *remove_backslashn(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i ++;
	map[i] = '\0';
	return (map);
}
int	main(int ac, char **av)
{
	t_game	*game;
	char	*map;

	int fd = open("choice", O_RDONLY);
	map = get_next_line(fd);
	map = remove_backslashn(map);
	if (map != NULL)
	{
		if (check_ber(map) != 1)
			error_exit(E_EXT, 0);
		game = create_game(map);
		while (map)
		{	
			free(map);
			map = get_next_line(fd);
		}
		//game_option_choice(game);
		play(game);
		return (free_game(game), 0);
	}	
	else
		return (error_exit(E_ARG, NULL), 1);
	return (0);
}
