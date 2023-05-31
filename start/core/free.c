/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:45:47 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/23 20:17:09 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	destroy_image_v2s(void *mlx_ptr, void *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx_ptr, img);
}

void	destroy_imagess(t_game *data)
{
	void			**p;
	int				i;

	p = (void **)&data->img;
	i = 0;
	while (i < IMG_NB_START)
		destroy_image_v2s(data->ptr, p[i++]);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_dico(&game->dico);
	free_game_data_start(game);
	free(game);
}

void	free_game_data_start(t_game *start)
{
	if (start->ptr)
	{
		destroy_imagess(start);
		if (start->win)
		{
			mlx_clear_window(start->ptr, start->win);
			mlx_destroy_window(start->ptr, start->win);
		}
		mlx_destroy_display(start->ptr);
		free(start->ptr);
	}
}

void	free_dico(t_letter **dico)
{
	t_letter	*tmp;

	if (!dico || !(*dico))
		return ;
	while (*dico)
	{
		tmp = (*dico)->next;
		free(*dico);
		*dico = tmp;
	}
}
