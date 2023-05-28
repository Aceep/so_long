#include "../includes/so_long.h"

void    opening_door(t_game *start)
{
    static int  fno;
    int x;
    int y;

    mlx_put_image_to_window(start->ptr, start->win, start->img.door[fno],
		600, 800);
    fno ++;
}