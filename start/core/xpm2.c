/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:49:45 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/01 11:00:08 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	xpm_alphabet2(t_game *start)
{
	int	w;
	int	h;

	start->img.alphabet[17] = mlx_xpm_file_to_image(start->ptr, R, &w, &h);
	start->img.alphabet[18] = mlx_xpm_file_to_image(start->ptr, S, &w, &h);
	start->img.alphabet[19] = mlx_xpm_file_to_image(start->ptr, T, &w, &h);
	start->img.alphabet[20] = mlx_xpm_file_to_image(start->ptr, U, &w, &h);
	start->img.alphabet[21] = mlx_xpm_file_to_image(start->ptr, V, &w, &h);
	start->img.alphabet[22] = mlx_xpm_file_to_image(start->ptr, W, &w, &h);
	start->img.alphabet[23] = mlx_xpm_file_to_image(start->ptr, X, &w, &h);
	start->img.alphabet[24] = mlx_xpm_file_to_image(start->ptr, Y, &w, &h);
	start->img.alphabet[25] = mlx_xpm_file_to_image(start->ptr, Z, &w, &h);
	start->img.numbers[0] = mlx_xpm_file_to_image(start->ptr, A0, &w, &h);
	start->img.numbers[1] = mlx_xpm_file_to_image(start->ptr, A1, &w, &h);
	start->img.numbers[2] = mlx_xpm_file_to_image(start->ptr, A2, &w, &h);
	start->img.numbers[3] = mlx_xpm_file_to_image(start->ptr, A3, &w, &h);
	start->img.numbers[4] = mlx_xpm_file_to_image(start->ptr, A4, &w, &h);
	start->img.numbers[5] = mlx_xpm_file_to_image(start->ptr, A5, &w, &h);
	start->img.numbers[6] = mlx_xpm_file_to_image(start->ptr, A6, &w, &h);
	start->img.numbers[7] = mlx_xpm_file_to_image(start->ptr, A7, &w, &h);
	start->img.numbers[8] = mlx_xpm_file_to_image(start->ptr, A8, &w, &h);
	start->img.numbers[9] = mlx_xpm_file_to_image(start->ptr, A9, &w, &h);
}

void	xpm_background1(t_game *start)
{
	int	w;
	int	h;

	start->img.background[0] = mlx_xpm_file_to_image(start->ptr, B1, &w, &h);
	start->img.background[1] = mlx_xpm_file_to_image(start->ptr, B2, &w, &h);
	start->img.background[2] = mlx_xpm_file_to_image(start->ptr, B3, &w, &h);
	start->img.background[3] = mlx_xpm_file_to_image(start->ptr, B4, &w, &h);
	start->img.background[4] = mlx_xpm_file_to_image(start->ptr, B5, &w, &h);
	start->img.background[5] = mlx_xpm_file_to_image(start->ptr, B6, &w, &h);
	start->img.background[6] = mlx_xpm_file_to_image(start->ptr, B7, &w, &h);
	start->img.background[7] = mlx_xpm_file_to_image(start->ptr, B8, &w, &h);
	start->img.background[8] = mlx_xpm_file_to_image(start->ptr, B9, &w, &h);
	start->img.background[9] = mlx_xpm_file_to_image(start->ptr, B10, &w, &h);
	start->img.background[10] = mlx_xpm_file_to_image(start->ptr, B11, &w, &h);
	start->img.background[11] = mlx_xpm_file_to_image(start->ptr, B12, &w, &h);
	start->img.background[12] = mlx_xpm_file_to_image(start->ptr, B13, &w, &h);
	start->img.background[13] = mlx_xpm_file_to_image(start->ptr, B14, &w, &h);
	start->img.background[14] = mlx_xpm_file_to_image(start->ptr, B15, &w, &h);
	start->img.background[15] = mlx_xpm_file_to_image(start->ptr, B16, &w, &h);
	start->img.background[16] = mlx_xpm_file_to_image(start->ptr, B17, &w, &h);
	start->img.background[17] = mlx_xpm_file_to_image(start->ptr, B18, &w, &h);
	start->img.background[18] = mlx_xpm_file_to_image(start->ptr, B19, &w, &h);
	start->img.background[19] = mlx_xpm_file_to_image(start->ptr, B20, &w, &h);
}

void	xpm_background2(t_game *start)
{
	int	w;
	int	h;

	start->img.background[20] = mlx_xpm_file_to_image(start->ptr, B21, &w, &h);
	start->img.background[21] = mlx_xpm_file_to_image(start->ptr, B22, &w, &h);
	start->img.background[22] = mlx_xpm_file_to_image(start->ptr, B23, &w, &h);
	start->img.background[23] = mlx_xpm_file_to_image(start->ptr, B24, &w, &h);
	start->img.background[24] = mlx_xpm_file_to_image(start->ptr, B25, &w, &h);
	start->img.background[25] = mlx_xpm_file_to_image(start->ptr, B26, &w, &h);
	start->img.background[26] = mlx_xpm_file_to_image(start->ptr, B27, &w, &h);
	start->img.background[27] = mlx_xpm_file_to_image(start->ptr, B28, &w, &h);
	start->img.background[28] = mlx_xpm_file_to_image(start->ptr, B29, &w, &h);
	start->img.background[29] = mlx_xpm_file_to_image(start->ptr, B30, &w, &h);
	start->img.background[30] = mlx_xpm_file_to_image(start->ptr, B31, &w, &h);
	start->img.background[31] = mlx_xpm_file_to_image(start->ptr, B32, &w, &h);
	start->img.background[32] = mlx_xpm_file_to_image(start->ptr, B33, &w, &h);
	start->img.background[33] = mlx_xpm_file_to_image(start->ptr, B34, &w, &h);
	start->img.background[34] = mlx_xpm_file_to_image(start->ptr, B35, &w, &h);
	start->img.background[35] = mlx_xpm_file_to_image(start->ptr, LANDSCAPE, &w, &h);
}