/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:47:02 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/17 15:45:46 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef PATROL
#  define PATROL 0 // 1 = on / 0 = off
#  define START_SCREEN 0 //-1 = on / 0 = off
#  define ENEMY_SPEED 1000 //1000 = Extrem / 2000 = Hard / 3000 = Medium / 4000 = Easy
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "../mlx_linux/mlx.h"

# define ESC_K	65307
# define ENTER	65293

//Key Code WASD
# define K_W	119
# define K_A	97
# define K_S	115
# define K_D	100

//Key Code Arrow
# define K_U	65362
# define K_DO	65364
# define K_L	65361
# define K_R	65363

# define IMG_W 64
# define IMG_H 64

//Start Screen and Preview
# define CURSOR "start/graph/white-up-arrow-icon-image.xpm"
# define P_BLUE "start/graph/Preview_Character/Preview_blue.xpm"
# define P_RED "start/graph/Preview_Character/Preview_red.xpm"
# define P_GREEN "start/graph/Preview_Character/Preview_green.xpm"
# define P_YELLOW "start/graph/Preview_Character/Preview_yellow.xpm"
# define INSTRUCT_START "start/graph/Preview_Character/Start_instructions.xpm"
# define S_BLACK "start/graph/Preview_Character/black.xpm"

# define IMG_NB 32

typedef enum e_config_error
{
	E_SUCCESS = 0,
	E_ARG,
	E_EXT,
	E_RD,
	E_MEM,
	E_EMPTY,
	E_GNL,
	E_WALL,
	E_MLX,
	E_TYPE,
	E_COUNT,
	E_IMG,
	E_REC,
	E_PATH,
	E_OVER,
}t_error;

typedef struct s_map
{
	int			x;
	int			y;
	char		value;
	void		*img;
	int			acc;
}t_map;

typedef struct s_image
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*character[8];
	void	*exit;
	void	*end[7];
	void	*ennemy[6];
	void	*cursor;
	void	*preview[6];
}t_image;

typedef struct s_player
{
	int			x;
	int			y;
	int			object;
	int			action;
	int			mv_count;
	void		*img;
	int			dir;
	struct s_player *next;
}t_player;

typedef struct s_count
{
	int			p;
	int			e;
	int			c;
	int			x;
}t_count;

typedef struct s_option
{
	int		patrol;
}t_option;

typedef struct s_game
{
	void		*ptr;
	void		*win;
	int			width;
	int			height;
	t_map		**map;
	t_player	player;
	t_count		count;
	t_image		img;
	t_player	*enemy;
	int			end;
	t_option	opt;
	t_player	cursor;
}t_game;

//Create Map
t_game		*create_game(char *file_map);
t_map		**init_map(t_game *game);
void		put_map_value(t_game *game, char *file_map);
void		map_dim(t_game *game, char *file_map);

//Init Game
void		init_player(t_game *game);
t_map		*find(t_game *game, int c);

//Check_Map
int			check_ber(char *av);
int			map_error(t_game *game);
int			wall_check(t_game *game);
void		check_rec(char *line, t_game *game);
int			path_check(t_game *game);

//Error
void		error_exit(int error_type, t_game *game);

//Free
void		free_map(t_map **map, int height);
void		free_game(t_game *game);
void	free_enemy_stack(t_player **enemy);

//Play
int			key_hook(int key, t_game *game);
void		play(t_game *game);
void		end_screen(t_game *game);

//Move 
void		move_right(t_game *game);
void		move_left(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		print_map(t_game *game);
int			exit_game(t_game *game);

//Images
void		xpm_init(t_game *game);
void	xpm_preview(t_game *game);

//Map
void		display_map(t_game *game);
void		generate_map(t_game *game);

//Move Enemy
void		ennemy(t_game *game);
void		anime_ennemy(t_game *game, int x, int y);
int			enemy_patrol(t_game *game);
int			get_enemy_position(t_game *game);
void		ft_plradd_back(t_player **lst, t_player *newnode);
t_player	*init_enemy(t_game *game, int x, int y);
void		ft_playerlist(t_game *game);

//Start Screen
void		start_screen(t_game *start);
void		cursor_init(t_game  *game);
void    cursor_move_right(t_game *game);
void    cursor_move_left(t_game *game);
int    start_game(void);
#endif 