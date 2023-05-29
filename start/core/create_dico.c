#include "../../includes/so_long.h"

int    create_dico(void)
{
    char    **gnl_ret;
    int     i;
    int     fd;

    fd = open("graph/Alphabet/dico", O_RDONLY);
    if (fd < 0)
        return (E_RD);
    gnl_ret = ft_split(get_next_line(fd), ' ');
    ft_printf("%s\n%s", gnl_ret[0], gnl_ret[1]);
    while (gnl_ret)
    {

    }
}