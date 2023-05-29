#include "../includes/so_long.h"

void    put_message(char *msg, t_game *start)
{
  int i;
  int val_let;
  t_letter  *tmp;

  tmp = start->dico;
  msg = ft_tolowercase(msg);
  while (msg[i])
  {
    val_let = msg[i] - 'a';
    while (tmp)
    {
      if (tmp->idx == val_let)
        //mlx_put_image_to_window(start->ptr, start->win, 0, 0, start->img.alphabet[val_let]
      tmp = tmp->next;
    }
  }
}
void    opening_door(t_game *start)
{
  static int  fno;
  static int  slw;
  int x;
  int y;

  mlx_put_image_to_window(start->ptr, start->win, start->img.door[fno], 0, 0);
  if ((slw % 6) == 0)
    fno ++;
  slw ++;
  if (fno == 41)
  {
    start->end = -2;
    mlx_clear_window(start->ptr, start->win);
  }
 // put_message("Welcome to so long", start);
}