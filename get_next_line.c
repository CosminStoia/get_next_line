/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:11:06 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/25 22:40:45 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *string)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_red;

	if (!string)
		string = malloc(BUFFER_SIZE * sizeof(char));
	if (!string)
		return (NULL);
	bytes_red = 1;
	while (bytes_red)
	{
		bytes_red = read(fd, buffer, BUFFER_SIZE);
		if (bytes_red == -1)
			return (free(string), NULL);
		buffer[bytes_red] = '\0';
		string = ft_strjoin(string, buffer);
		if (ft_strchr(string, '\n'))
			break ;
	}
	return (string);
}

char	*ft_get_line(char *string)
{
	int		i;
	char	*last_str;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	last_str = (char *)malloc((i + 2) * sizeof(char));
	if (!last_str)
		return (NULL);
	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
	{
		last_str[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		last_str[i] = string[i];
		i++;
	}
	last_str[i] = '\0';
	return (last_str);
}

char	*ft_new_string(char *string)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(string) + 1) * sizeof(char));
	if (!str)
	{
		free(string);
		return (NULL);
	}
	i++;
	j = 0;
	while (string[i])
		str[j++] = string[i++];
	str[j] = '\0';
	free(string);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	string = ft_read_file(fd, string);
	if (!string)
		return (NULL);
	line = ft_get_line(string);
	if (!line)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	string = ft_new_string(string);
	return (line);
}