/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:47:02 by alycgaut          #+#    #+#             */
/*   Updated: 2023/06/02 00:59:22 by aceep            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef PATROL
#  define PATROL 1
// 1 = on / 0 = off
#  define START_SCREEN -1 
//-1 = on / 0 = off
#  define ENEMY_SPEED 3000 
//1000 = Extrem / 2000 = Hard / 3000 = Medium / 4000 = Easy
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include "start.h"

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

extern size_t	choice;

//Environnement
# define BRICK "graph/BRICK_1A.xpm"
# define GRASS "graph/grass.xpm"
# define EXIT "graph/HEDGE_1C.xpm"
# define CHERRY "graph/gem.xpm"

//Ingame Character
# define DINO "graph/Ingame_Character/Yellow/Main-character-So_Long.xpm"
# define DINO_LEFT "graph/Ingame_Character/Yellow/Main-So_Long_Left.xpm"
# define DINO_RED "graph/Ingame_Character/Red/Character_red.xpm"
# define DINO_RED_LEFT "graph/Ingame_Character/Red/Character_red_left.xpm"
# define DINO_GREEN "graph/Ingame_Character/Green/Character_green.xpm"
# define DINO_GREEN_LEFT "graph/Ingame_Character/Green/Character_green_left.xpm"
# define DINO_BLUE "graph/Ingame_Character/Blue/Character_blue.xpm"
# define DINO_BLUE_LEFT "graph/Ingame_Character/Blue/Character_blue_left.xpm"

//End Screen
# define WINNER "graph/End_screen/Winner.xpm"
# define BLACK "graph/End_screen/black.xpm"
# define LOSE "graph/End_screen/Lose.xpm"
# define BLUE "graph/End_screen/End_blue.xpm"
# define RED "graph/End_screen/End_red.xpm"
# define GREEN "graph/End_screen/End_green.xpm"
# define YELLOW "graph/End_screen/End_yellow.xpm"
# define TELEPORT "graph/End_screen/Teleportation.xpm"

//Opposum
# define GOLEM "graph/Enemy/0_Golem_Walking_000.xpm"
# define GOLEM2 "graph/Enemy/0_Golem_Walking_001.xpm"
# define GOLEM3 "graph/Enemy/0_Golem_Walking_002.xpm"
# define GOLEM4 "graph/Enemy/0_Golem_Walking_003.xpm"
# define GOLEM5 "graph/Enemy/0_Golem_Walking_004.xpm"
# define GOLEM6 "graph/Enemy/0_Golem_Walking_005.xpm"
# define GOLEM7 "graph/Enemy/0_Golem_Walking_006.xpm"
# define GOLEM8 "graph/Enemy/0_Golem_Walking_007.xpm"
# define GOLEM9 "graph/Enemy/0_Golem_Walking_008.xpm"
# define GOLEM10 "graph/Enemy/0_Golem_Walking_009.xpm"
# define GOLEM11 "graph/Enemy/0_Golem_Walking_010.xpm"
# define GOLEM12 "graph/Enemy/0_Golem_Walking_011.xpm"
# define GOLEM13 "graph/Enemy/0_Golem_Walking_012.xpm"
# define GOLEM14 "graph/Enemy/0_Golem_Walking_013.xpm"
# define GOLEM15 "graph/Enemy/0_Golem_Walking_014.xpm"
# define GOLEM16 "graph/Enemy/0_Golem_Walking_015.xpm"
# define GOLEM17 "graph/Enemy/0_Golem_Walking_016.xpm"
# define GOLEM18 "graph/Enemy/0_Golem_Walking_017.xpm"
# define GOLEM19 "graph/Enemy/0_Golem_Walking_018.xpm"
# define GOLEM20 "graph/Enemy/0_Golem_Walking_019.xpm"

//Start Screen and Preview
# define CURSOR "graph/white-up-arrow-icon-image.xpm"
# define P_BLUE "graph/Preview_Character/Preview_blue.xpm"
# define P_RED "graph/Preview_Character/Preview_red.xpm"
# define P_GREEN "graph/Preview_Character/Preview_green.xpm"
# define P_YELLOW "graph/Preview_Character/Preview_yellow.xpm"
# define INSTRUCT_START "graph/Preview_Character/Start_instructions.xpm"
# define S_BLACK "graph/Preview_Character/black.xpm"

# define NUCLEAR "graph/Nuclear_Explod/Nuclear_explosion1.xpm"
# define NUCLEAR1 "graph/Nuclear_Explod/Nuclear_explosion2.xpm"
# define NUCLEAR2 "graph/Nuclear_Explod/Nuclear_explosion3.xpm"
# define NUCLEAR3 "graph/Nuclear_Explod/Nuclear_explosion4.xpm"
# define NUCLEAR4 "graph/Nuclear_Explod/Nuclear_explosion5.xpm"
# define NUCLEAR5 "graph/Nuclear_Explod/Nuclear_explosion6.xpm"
# define NUCLEAR6 "graph/Nuclear_Explod/Nuclear_explosion7.xpm"
# define NUCLEAR7 "graph/Nuclear_Explod/Nuclear_explosion8.xpm"
# define NUCLEAR8 "graph/Nuclear_Explod/Nuclear_explosion9.xpm"
# define NUCLEAR9 "graph/Nuclear_Explod/Nuclear_explosion10.xpm"

# define IMG_NB 57

typedef enum e_config_error
{
	E_SUCCESS = 0,
	E_ARG_MANY,
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
	void	*end[8];
	void	*ennemy[20];
	void	*crash[10];
	void	*cursor;
	void	*preview[6];
	void	*door[41];
	void	*alphabet[26];
	void	*numbers[10];
	void	*background[36];
}t_image;

typedef struct s_player
{
	int				x;
	int				y;
	int				object;
	int				action;
	int				mv_count;
	void			*img;
	int				dir;
	struct s_player	*next;
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
	int			choice;
	char		*map_choice;
	t_letter	*dico;
}t_game;

//Create Map
t_game		*create_game(char *file_map, int c);
t_map		**init_map(t_game *game);
void		put_map_value(t_game *game, char *file_map);
void		map_dim(t_game *game, char *file_map);

//Init Game
void		init_player(t_game *game);
t_map		*find(t_game *game, int c);
void		charac_choice(int c, t_game *game);
int			open_file(char *file_map, t_game *game);
void		put_choice_value(t_game *game);
void		assign_value(t_game *game, int y, char *line);

//Check_Map
int			check_ber(char *av);
int			map_error(t_game *game);
int			wall_check(t_game *game);
void		check_rec(char *line, t_game *game);
int			path_check(t_game *game);

//Error
void		error_exit(int error_type, t_game *game);
void		error_exit_charset(int error_type, t_game *game, char c);
void		error_exit_count(int error_type, t_game *game, char *c);

//Free
void		free_map(t_map **map, int height);
void		free_game(t_game *game);
void		free_enemy_stack(t_player **enemy);
void		free_game(t_game *game);
void		free_game_data(t_game *game);

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
void		xpm_preview(t_game *game);

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

//Bonus
char		*remove_backslashn(char *map);
void		put_again(char *ag);
void		big_bang(t_game *game);
void		image_end(t_game *game);
#endif 