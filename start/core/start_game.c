#include "../../includes/so_long.h"

void    start_screen(t_game *start)
{
    int x;

    x = 0;
    //ft_printf("oj");
    mlx_put_image_to_window(start->ptr, start->win, start->img.preview[4], 500 - 2 * 64, 150);
    mlx_put_image_to_window(start->ptr, start->win, start->img.preview[0], 500 - 2 * 64, 200);
    mlx_put_image_to_window(start->ptr, start->win, start->img.preview[1], 500 - 1 * 64, 200);
    mlx_put_image_to_window(start->ptr, start->win, start->img.preview[2], 500, 200);
    mlx_put_image_to_window(start->ptr, start->win, start->img.preview[3], 564, 200);
    while (x < 20)
    {
       mlx_put_image_to_window(start->ptr, start->win, start->img.preview[5], x * IMG_W, start->cursor.y);
        x ++;
    }
    mlx_put_image_to_window(start->ptr, start->win, start->img.cursor, start->cursor.x, start->cursor.y);
}

void    cursor_move_left(t_game *game)
{
    if (game->cursor.x > 500 - 2 * 64)
    {
        
        game->cursor.x -= IMG_W;
        game->cursor.action -= 1;
    }
}

void    cursor_move_right(t_game *game)
{
    if (game->cursor.x < 564)
    {
        game->cursor.x += IMG_W;
        game->cursor.action += 1;
    }
}

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
	while (i < IMG_NB)
		destroy_image_v2s(data->ptr, p[i++]);
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

void    cursor_init(t_game  *game)
{
    game->cursor.x = 500 - 2 * 64;
    game->cursor.y = 280;
    game->cursor.action = 0;
}


int	exit_start(t_game *start)
{
    int fd ;
    char *choice;

    free_game_data_start(start);
    if (start->map_choice != NULL)
	{
		fd = open("choice", O_WRONLY | O_APPEND | O_CREAT, 0644);
    	//ft_printf("%s", start->map_choice);
    	choice = ft_itoa(start->cursor.action);
		ft_putstr_fd("maps/", fd);
		ft_putstr_fd(start->map_choice, fd);
   		ft_putstr_fd(choice, fd);
		free(start->map_choice);
    	close (fd);
    	free(choice);
	}
    free(start);
    exit(1);
}
void    choose_map(t_game *start, int c, int key)
{
	char *map;
	int fd;
	static int i;
	int x;

	x = 0;
	i += c;
	if (i >= 20)
		i = 19;
	else if (i < 0)
		i = 0;
	fd = open("maps/list_map", O_RDONLY);
	map = get_next_line(fd);
	//ft_printf("%s", map);
	while (x < i)
	{
		free(map);
		map = get_next_line(fd);
		x ++;
	}
	if (map)
		mlx_string_put(start->ptr, start->win, 500 - 2 * 64, 150, 16711680, map);
	if (key > 0)
		start->map_choice = ft_strdup(map);
	free(map);
	while ((map = get_next_line(fd)))
		free(map);
	close (fd);
}

int	key_hook_start(int key, t_game *start)
{
    if (key == ESC_K)
		exit_start(start);
    if (start->end == -2)
	{
		if (key == K_A || key == K_L)
			cursor_move_left(start);
		if (key == K_D || key == K_R)
			cursor_move_right(start);
		if (key == ENTER)
		{
			start->end = -1;
        	mlx_clear_window(start->ptr, start->win);
		}
    }
	else if (start->end == -1)
	{
		if (key == K_W || key == K_U)
		{
			mlx_clear_window(start->ptr, start->win);
			choose_map(start, -1, 0);
		}
		if (key == K_S || key == K_DO)
		{
			mlx_clear_window(start->ptr, start->win);
			choose_map(start, 1, 0);
		}
		if (key == ENTER)
		{
			start->end = 0;
			choose_map(start, 0, key);
		}
    }
    return (0);
}

int	loop_hook_start(t_game *start)
{
	if (start->end == -2)
		start_screen(start);
	else if (start->end == -1)
		choose_map(start, 0, 0);
    else
        exit_start(start);
    return (0);
}

void	play_start(t_game *start)
{
	mlx_hook(start->win, 17, 0, exit_start, start);
	mlx_key_hook(start->win, key_hook_start, start);
	mlx_loop_hook(start->ptr, loop_hook_start, start);
	mlx_loop(start->ptr);
}


int    start_game(void)
{
    t_game  *start;
    int     ret;

    start = ft_calloc(1, sizeof(t_game));
    start->ptr = mlx_init();
    if (!start->ptr)
		error_exit(E_MLX, start);
	start->win = mlx_new_window(start->ptr, 1000, 500, "So_long");
	if (!start->win)
		error_exit(E_MLX, start);
    start->end = -2;
    cursor_init(start);
    xpm_preview(start);
    play_start(start);
    ret = start->cursor.action;
    return (ret);
    //ft_printf("%d", game->cursor.action);
}