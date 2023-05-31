/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:56:39 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/29 23:44:34 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_background(t_game *start)
{
	static int fno;
	static int	slw;

	mlx_put_image_to_window(start->ptr, start->win, start->img.background[0], 0, 0);
	if ((slw % 5) == 0)
		fno ++;
	slw ++;
	if (fno == 33)
		fno = 0;
}

char	*find_right_line(int fd, int i, char *map)
{
	int			x;

	x = 0;
	while (x < i)
	{
		map = get_next_line(fd);
		free(map);
		x ++;
	}
	map = get_next_line(fd);
	return (map);
}

void	choose_map(t_game *start, int c, int key)
{
	char		*map;
	int			fd;
	static int	i;

	i += c;
	if (i >= 20)
		i = 19;
	else if (i < 0)
		i = 0;
	fd = open("maps/list_map", O_RDONLY);
	map = find_right_line(fd, i, map);
	put_background(start);
	if (map)
		put_message(map, start);
		// mlx_string_put(start->ptr, start->win,
		// 	498 / 2, 150, 16711680, map);
	if (key == ENTER)
		start->map_choice = ft_strdup(map);
	while (map)
	{
		free(map);
		map = get_next_line(fd);
	}
	close (fd);
}
