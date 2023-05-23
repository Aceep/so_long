/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:47:22 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*in_new;
	t_list	*in_old;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	if (!(new_list))
		return (NULL);
	in_new = new_list;
	in_old = lst->next;
	while (in_old)
	{
		in_new->next = ft_lstnew((*f)(in_old->content));
		if (!(in_new))
		{
			ft_lstdelone(new_list, del);
			return (NULL);
		}	
		in_new = in_new->next;
		in_old = in_old->next;
	}
	return (new_list);
}
