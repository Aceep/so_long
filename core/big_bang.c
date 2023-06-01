#include "../includes/so_long.h"

void    big_bang(t_game *game)
{
    static int fno;
    static int slow;

    //ft_printf("OK");
    game->player.img = game->img.end[4];
    while (fno != 10)
    {
        mlx_put_image_to_window(game->ptr, game->win, game->img.crash[fno], game->player.x * IMG_W,
			game->player.y * IMG_H);
        if (slow % 10000 == 0)
            fno ++;
        slow ++;
    }
    mlx_clear_window(game->ptr, game->win);
}