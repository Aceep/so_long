#include "../../includes/so_long.h"

void    start_screen(t_game *start)
{
	int x;

	x = 0;
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
}
