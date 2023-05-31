/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dico.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:03:54 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/31 14:03:56 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_letter	*new_letter(char **gnl_ret, int i)
{
	t_letter	*new;

	new = malloc(sizeof(t_letter));
	new->idx = i;
	new->letter = gnl_ret[0];
	new->file = gnl_ret[1];
	new->next = NULL;
	return (new);
}

void	dico_add_back(t_letter **dico, t_letter *new)
{
	t_letter	*start;

	start = *dico;
	if (*dico)
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
	else
		*dico = new;
}

void	free_gnl_split(char **split)
{
	free(split[0]);
	free(split[1]);
	free(split);
}

int	create_dico(t_game *start)
{
	char	**gnl_ret;
	int		i;
	int		fd;
	char	*gnl;

	fd = open("graph/Alphabet/dico", O_RDONLY);
	if (fd < 0)
		return (E_RD);
	gnl = get_next_line(fd);
	gnl_ret = ft_split(gnl, ' ');
	while (gnl_ret)
	{
		free(gnl);
		dico_add_back(&start->dico, new_letter(gnl_ret, i));
		free_gnl_split(gnl_ret);
		gnl = get_next_line(fd);
		gnl_ret = ft_split(gnl, ' ');
		i ++;
	}
	return (0);
}
