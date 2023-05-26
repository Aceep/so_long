/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:49:45 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/26 16:59:03 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	xpm_preview(t_game *start)
{
	int	w;
	int	h;

	start->img.preview[0] = mlx_xpm_file_to_image(start->ptr, P_YELLOW, &w, &h);
	start->img.preview[1] = mlx_xpm_file_to_image(start->ptr, P_RED, &w, &h);
	start->img.preview[2] = mlx_xpm_file_to_image(start->ptr, P_GREEN, &w, &h);
	start->img.preview[3] = mlx_xpm_file_to_image(start->ptr, P_BLUE, &w, &h);
	start->img.preview[4] = mlx_xpm_file_to_image(start->ptr,
			INSTRUCT_START, &w, &h);
	start->img.preview[5] = mlx_xpm_file_to_image(start->ptr, S_BLACK, &w, &h);
	start->img.cursor = mlx_xpm_file_to_image(start->ptr, CURSOR, &w, &h);
}
