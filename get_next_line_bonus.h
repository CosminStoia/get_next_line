/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:58:19 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/26 20:59:09 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int c);
void	ft_str_join(char *res, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	ft_bzero(void *s, size_t n);
char	*ft_read_file(int fd, char *string);
char	*ft_extract_line(char *string);
char	*ft_update_string(char *string);
char	*get_next_line(int fd);

#endif
