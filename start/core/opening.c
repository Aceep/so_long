#include "../includes/so_long.h"

void    opening_door(t_game *start)
{
  static int  fno;
  static int  slw;
  int x;
  int y;

  mlx_put_image_to_window(start->ptr, start->win, start->img.door[fno], 0, 0);
  if ((slw % 5) == 0)
    fno ++;
  slw ++;
  if (fno == 41)
  {
    start->end = -2;
    mlx_clear_window(start->ptr, start->win);
  }
}