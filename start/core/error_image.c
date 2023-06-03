#include "../includes/so_long.h"

int    image_errors(t_game  *start)
{
    void    **p;
    int     i;

    p = (void **)&start->img;
    i = 0;
    while (i < IMG_NB_START)
    {
        if (!p[i++])
            return (1);
    }
    return (0);
}