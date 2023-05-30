#include "../includes/so_long.h"

int    put_message(char *msg, t_game *start)
{
  int i;
  int val_let;
  int x;
    i = 0;
    x = 0;
    while (msg[i])
    {
      val_let = (char)msg[i] - 'a';
    //ft_printf("%d", val_let);
       mlx_put_image_to_window(start->ptr, start->win, start->img.alphabet[val_let], x, 50);
       i ++;
       x += 50;
    }
  return (0);
}
int    opening_door(t_game *start)
{
  static int  fno;
  static int  slw;
  int y;

  mlx_put_image_to_window(start->ptr, start->win, start->img.door[fno], 0, 0);
  //if ((slw % 6) == 0)
    fno ++;
  slw ++;
  if (fno == 41)
  {
    mlx_clear_window(start->ptr, start->win);
    return (1);
  }
  return (0);
}