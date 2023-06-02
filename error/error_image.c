#include "../includes/so_long.h"

int    image_error(t_game  *game)
{
    void    **p;
    int     i;

    p = (void **)&game->img;
    i = 0;
    while (i < IMG_NB)
    {
        if (!p[i++])
            return (1);
    }
    return (0);
}