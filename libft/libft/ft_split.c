/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:55:36 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/24 14:35:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nb_line(char const *s, char c)
{
	int	i;
	int	nb_line;

	i = 0;
	nb_line = 0;
	while (s[i])
	{
		if ((s[i] != c && (s[i + 1] == c || s[i + 1] == '\0')))
			nb_line ++;
		i ++;
	}
	return (nb_line);
}

void	ft_line(char **str, char const *s, int nb_line, char c)
{
	int	j;
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s ++;
		else
		{
			j = 0;
			while (*(s + j) != '\0' && *(s + j) != c)
				j ++;
			if (i < nb_line)
				str[i] = ft_substr(s, 0, j);
			i ++;
			s += j;
		}
	}
	str[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		nb_line;
	char	**str;

	if (!s)
		return (NULL);
	nb_line = ft_nb_line(s, c);
	str = (char **)malloc(sizeof(char *) * (nb_line + 1));
	if (!(str))
		return (NULL);
	ft_line(str, s, nb_line, c);
	return (str);
}

/*int	main(void)
{
	char *splitme = strdup("Tripouille ");
   char **tab = ft_split(splitme, ' ');
	return (0);
}*/