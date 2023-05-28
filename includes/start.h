/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:52:13 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/28 09:25:52 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_H
# define START_H

# include "so_long.h"

# define D_1 "graph/Jurassic_Doors/frame-01.xpm"
# define D_2 "graph/Jurassic_Doors/frame-02.xpm"
# define D_3 "graph/Jurassic_Doors/frame-03.xpm"
# define D_4 "graph/Jurassic_Doors/frame-04.xpm"
# define D_5 "graph/Jurassic_Doors/frame-05.xpm"
# define D_6 "graph/Jurassic_Doors/frame-06.xpm"
# define D_7 "graph/Jurassic_Doors/frame-07.xpm"
# define D_8 "graph/Jurassic_Doors/frame-08.xpm"
# define D_9 "graph/Jurassic_Doors/frame-09.xpm"
# define D_10 "graph/Jurassic_Doors/frame-10.xpm"
# define D_11 "graph/Jurassic_Doors/frame-11.xpm"
# define D_12 "graph/Jurassic_Doors/frame-12.xpm"
# define D_13 "graph/Jurassic_Doors/frame-13.xpm"
# define D_14 "graph/Jurassic_Doors/frame-14.xpm"
# define D_15 "graph/Jurassic_Doors/frame-15.xpm"
# define D_16 "graph/Jurassic_Doors/frame-16.xpm"
# define D_17 "graph/Jurassic_Doors/frame-17.xpm"
# define D_18 "graph/Jurassic_Doors/frame-18.xpm"
# define D_19 "graph/Jurassic_Doors/frame-19.xpm"
# define D_20 "graph/Jurassic_Doors/frame-20.xpm"
# define D_21 "graph/Jurassic_Doors/frame-21.xpm"
# define D_22 "graph/Jurassic_Doors/frame-22.xpm"
# define D_23 "graph/Jurassic_Doors/frame-23.xpm"
# define D_24 "graph/Jurassic_Doors/frame-24.xpm"
# define D_25 "graph/Jurassic_Doors/frame-25.xpm"
# define D_26 "graph/Jurassic_Doors/frame-26.xpm"
# define D_27 "graph/Jurassic_Doors/frame-27.xpm"
# define D_28 "graph/Jurassic_Doors/frame-28.xpm"
# define D_29 "graph/Jurassic_Doors/frame-29.xpm"
# define D_30 "graph/Jurassic_Doors/frame-30.xpm"
# define D_31 "graph/Jurassic_Doors/frame-31.xpm"
# define D_32 "graph/Jurassic_Doors/frame-32.xpm"
# define D_33 "graph/Jurassic_Doors/frame-33.xpm"
# define D_34 "graph/Jurassic_Doors/frame-34.xpm"
# define D_35 "graph/Jurassic_Doors/frame-35.xpm"
# define D_36 "graph/Jurassic_Doors/frame-36.xpm"
# define D_37 "graph/Jurassic_Doors/frame-37.xpm"
# define D_38 "graph/Jurassic_Doors/frame-38.xpm"
# define D_39 "graph/Jurassic_Doors/frame-39.xpm"
# define D_40 "graph/Jurassic_Doors/frame-40.xpm"
# define D_41 "graph/Jurassic_Doors/frame-41.xpm"

typedef struct s_game	t_game;

//Starter
int		start_game(t_game *start);
void    opening_door(t_game *start);

//Character choice
void	cursor_init(t_game *game);
void	cursor_move_right(t_game *game);
void	cursor_move_left(t_game *game);
void	start_screen(t_game *start);

//Exit and Assignment
int		exit_start(t_game *start);

//Play Start Screen
int		key_hook_start(int key, t_game *start);
int		loop_hook_start(t_game *start);
void	play_start(t_game *start);

//Map Choice
void	choose_map(t_game *start, int c, int key);

//Free
void	free_game_data_start(t_game *start);
void	destroy_image_v2s(void *mlx_ptr, void *img);
void	destroy_imagess(t_game *data);
void	free_game(t_game *game);

//Images
void	all_xpm_for_start(t_game *game);

#endif