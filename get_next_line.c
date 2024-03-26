/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:11:06 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/26 16:19:22 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = s;
	while (n > 0)
	{
		*a = 0;
		a++;
		n--;
	}
}

char	*ft_read_file(int fd, char *string)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_red;

	if (!string)
	{
		string = malloc(sizeof(char));
		if (!string)
			return (NULL);
		string[0] = '\0';
	}
	bytes_red = 1;
	while (bytes_red != 0 && !ft_strchr(string, '\n'))
	{
		bytes_red = read(fd, buffer, BUFFER_SIZE);
		if (bytes_red == -1)
		{
			free(string);
			return (NULL);
		}
		if (bytes_red == 0)
			break ;
		buffer[bytes_red] = '\0';
		string = ft_strjoin(string, buffer);
	}
	return (string);
}

char	*ft_extract_line(char *string)
{
	int		i;
	char	*last_str;

	i = 0;
	if (!string[i] || string[i] == '\0')
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

char	*ft_update_string(char *string)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == '\0')
	{
		free(string);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(string) - i) * sizeof(char));
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

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (read(fd, NULL, 0) < 0)
			return (NULL);
		return (ft_bzero(string, ft_strlen(string)), NULL);
	}
	string = ft_read_file(fd, string);
	if (!string)
		return (NULL);
	line = ft_extract_line(string);
	if (!line)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	string = ft_update_string(string);
	return (line);
}
