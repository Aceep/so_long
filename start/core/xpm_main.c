/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:49:45 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/28 02:53:46 by aceep            ###   ########.fr       */
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

void	xpm_doors_1(t_game *start)
{
	int	w;
	int	h;

	start->img.door[0] = mlx_xpm_file_to_image(start->ptr, D_1, &w, &h);
	start->img.door[1] = mlx_xpm_file_to_image(start->ptr, D_2, &w, &h);
	start->img.door[2] = mlx_xpm_file_to_image(start->ptr, D_3, &w, &h);
	start->img.door[3] = mlx_xpm_file_to_image(start->ptr, D_4, &w, &h);
	start->img.door[4] = mlx_xpm_file_to_image(start->ptr, D_5, &w, &h);
	start->img.door[5] = mlx_xpm_file_to_image(start->ptr, D_6, &w, &h);
	start->img.door[6] = mlx_xpm_file_to_image(start->ptr, D_7, &w, &h);
	start->img.door[7] = mlx_xpm_file_to_image(start->ptr, D_8, &w, &h);
	start->img.door[8] = mlx_xpm_file_to_image(start->ptr, D_9, &w, &h);
	start->img.door[9] = mlx_xpm_file_to_image(start->ptr, D_10, &w, &h);
	start->img.door[10] = mlx_xpm_file_to_image(start->ptr, D_11, &w, &h);
	start->img.door[11] = mlx_xpm_file_to_image(start->ptr, D_12, &w, &h);
	start->img.door[12] = mlx_xpm_file_to_image(start->ptr, D_13, &w, &h);
	start->img.door[13] = mlx_xpm_file_to_image(start->ptr, D_14, &w, &h);
	start->img.door[14] = mlx_xpm_file_to_image(start->ptr, D_15, &w, &h);
	start->img.door[15] = mlx_xpm_file_to_image(start->ptr, D_16, &w, &h);
	start->img.door[16] = mlx_xpm_file_to_image(start->ptr, D_17, &w, &h);
	start->img.door[17] = mlx_xpm_file_to_image(start->ptr, D_18, &w, &h);
	start->img.door[18] = mlx_xpm_file_to_image(start->ptr, D_19, &w, &h);
	start->img.door[19] = mlx_xpm_file_to_image(start->ptr, D_20, &w, &h);
	start->img.door[20] = mlx_xpm_file_to_image(start->ptr, D_21, &w, &h);
	start->img.door[21] = mlx_xpm_file_to_image(start->ptr, D_22, &w, &h);
	start->img.door[22] = mlx_xpm_file_to_image(start->ptr, D_23, &w, &h);
	start->img.door[23] = mlx_xpm_file_to_image(start->ptr, D_24, &w, &h);
	start->img.door[24] = mlx_xpm_file_to_image(start->ptr, D_25, &w, &h);
	start->img.door[25] = mlx_xpm_file_to_image(start->ptr, D_26, &w, &h);
	start->img.door[26] = mlx_xpm_file_to_image(start->ptr, D_27, &w, &h);
	start->img.door[27] = mlx_xpm_file_to_image(start->ptr, D_28, &w, &h);
	start->img.door[28] = mlx_xpm_file_to_image(start->ptr, D_29, &w, &h);
	start->img.door[29] = mlx_xpm_file_to_image(start->ptr, D_30, &w, &h);
	start->img.door[30] = mlx_xpm_file_to_image(start->ptr, D_31, &w, &h);
	start->img.door[31] = mlx_xpm_file_to_image(start->ptr, D_32, &w, &h);
	start->img.door[32] = mlx_xpm_file_to_image(start->ptr, D_33, &w, &h);
	start->img.door[33] = mlx_xpm_file_to_image(start->ptr, D_34, &w, &h);
	start->img.door[34] = mlx_xpm_file_to_image(start->ptr, D_35, &w, &h);
	start->img.door[35] = mlx_xpm_file_to_image(start->ptr, D_36, &w, &h);
	start->img.door[36] = mlx_xpm_file_to_image(start->ptr, D_37, &w, &h);
	start->img.door[37] = mlx_xpm_file_to_image(start->ptr, D_38, &w, &h);
	start->img.door[38] = mlx_xpm_file_to_image(start->ptr, D_39, &w, &h);
	start->img.door[39] = mlx_xpm_file_to_image(start->ptr, D_40, &w, &h);
	start->img.door[40] = mlx_xpm_file_to_image(start->ptr, D_41, &w, &h);
}
void	all_xpm_for_start(t_game *start)
{
	xpm_doors_1(start);
	//xpm_doors_2(start);
	xpm_preview(start);
}