#include "../includes/so_long.h"

int    put_message(char *msg, t_game *start)
{
  int i;
  int val_let;
  int x;
  static int  fno;
  int y;

  y = 50;
  i = 0;
  x = 0;
  while (msg[i])
  {
    val_let = (char)msg[i] - 'a';
    //ft_printf("%d", val_let);
    if (ft_isalpha(msg[i]) == 1)
      mlx_put_image_to_window(start->ptr, start->win, start->img.alphabet[val_let], x, y);
    if (x >= 350 || !ft_isalpha(msg[i]))
    {
      y += 60;
      x = 0;
    }  
    i ++;
    x += 54;
  }
  fno ++;
  if (fno == 1500)
  {
    mlx_clear_window(start->ptr, start->win);
    start->end = -2;
  }
  return (0);
}

int    opening_door(t_game *start)
{
  static int  fno;
  static int  slw;
  int y;

  mlx_put_image_to_window(start->ptr, start->win, start->img.door[fno], 0, 0);
  if ((slw % 10) == 0)
    fno ++;
  slw ++;
  if (fno == 41)
  {
    mlx_clear_window(start->ptr, start->win);
    //start->end =-2;
    return (1);
  }
  return (0);
}