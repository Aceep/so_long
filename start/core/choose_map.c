/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:56:39 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/26 17:06:12 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	choose_map(t_game *start, int c, int key)
{
	char		*map;
	int			fd;
	static int	i;
	int			x;

	x = 0;
	i += c;
	if (i >= 20)
		i = 19;
	else if (i < 0)
		i = 0;
	fd = open("maps/list_map", O_RDONLY);
	map = get_next_line(fd);
	while (x < i)
	{
		free(map);
		map = get_next_line(fd);
		x ++;
	}
	if (map)
		mlx_string_put(start->ptr, start->win,
			500 - 2 * 64, 150, 16711680, map);
	if (key > 0)
		start->map_choice = ft_strdup(map);
	while (map)
	{
		free(map);
		map = get_next_line(fd);
	}
	close (fd);
}
