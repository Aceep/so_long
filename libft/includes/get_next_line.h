/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:26:03 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/25 15:27:19 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_read(int fd, char **buffer, char **line, char **prev_read);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(const char *s);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(const char *str);
char	*get_end(char **prev_read);
char	*get_line(char **prev_read);

#endif
