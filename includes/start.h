#ifndef START_H
# define START_H

# include "so_long.h"

typedef struct s_game t_game;

//Starter
int    start_game(void);

//Character choice
void    cursor_init(t_game  *game);
void    cursor_move_right(t_game *game);
void    cursor_move_left(t_game *game);
void    start_screen(t_game *start);

//Exit and Assignment
int	exit_start(t_game *start);

//Play Start Screen
int	key_hook_start(int key, t_game *start);
int	loop_hook_start(t_game *start);
void	play_start(t_game *start);

//Map Choice
void    choose_map(t_game *start, int c, int key);

//Free
void	free_game_data_start(t_game *start);
void	destroy_image_v2s(void *mlx_ptr, void *img);
void	destroy_imagess(t_game *data);
void	free_game(t_game *game);

#endif