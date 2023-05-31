/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:48 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/26 16:49:26 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

struct s_errdesc
{
	int		code;
	char	*msg;
} errdesc[] = {
	{E_SUCCESS, 0},
	{E_ARG_MANY, "Error:\nInvalid number of arguments : Too many arguments"},
	{E_ARG, "Error:\nInvalid number of arguments : Need an argument"},
	{E_EXT, "Error:\nInvalid file extension"},
	{E_RD, "Error:\nFile not found"},
	{E_MEM, "Error:\nAllocation failed"},
	{E_EMPTY, "Error:\nMap is empty"},
	{E_GNL, "Error:\nError in get_next_line fonction"},
	{E_WALL, "Error:\nMap not surrounded by walls"},
	{E_MLX, "Error:\nMLX failed"},
	{E_TYPE, "Error:\nMap invalid : characters not authoried"},
	{E_COUNT, "Error:\nMap invalid : not good number of character"},
	{E_IMG, "Error:\nImage error"},
	{E_REC, "Error:\nMap is invalid : not rectangular"},
	{E_PATH, "Error:\nMap is invalid : no valid path"},
	{E_OVER, "Error:\nMap too big"},
};

void	error_exit(int error_type, t_game *game)
{
	ft_printf("\033[1;31m%s\n\033[0m", errdesc[error_type].msg);
	if (game)
		free_game(game);
	if (choice != 0)
		put_again("-1");
	exit(EXIT_FAILURE);
}

void	error_exit_charset(int error_type, t_game *game, char c)
{
	ft_printf("\033[1;31m%s : %c\n\033[0m", errdesc[error_type].msg, c);
	if (game)
		free_game(game);
	if (choice != 0)
		put_again("-1");
	exit(EXIT_FAILURE);
}

void	error_exit_count(int error_type, t_game *game, char *c)
{
	ft_printf("\033[1;31m%s : %s\n\033[0m", errdesc[error_type].msg, c);
	if (game)
		free_game(game);
	if (choice != 0)
		put_again("-1");
	exit(EXIT_FAILURE);
}
