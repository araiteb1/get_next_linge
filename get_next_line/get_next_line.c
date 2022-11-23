/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:30:19 by araiteb           #+#    #+#             */
/*   Updated: 2022/11/23 15:42:58 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *line)
{
	char	*str;
	int		i;

	str = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	i = 1;
	while (i > 0 && ft_index(line, '\n') == -1)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i == -1)
		{
			free(str);
			free(line);
			return (NULL);
		}
		str[i] = '\0';
		line = ft_strjoin(line, str);
	}
	free(str);
	return (line);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		len;

	len = 0;
	if (*str == '\0')
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	line = ft_substr(str, 0, len + 1);
	return (line);
}

char	*ft_remain(char *line)
{
	char	*str;
	int		start;

	start = ft_index(line, '\n');
	if (start == -1)
		start = ft_strlen(line);
	if (line[start] && line[start] == '\n')
		start++;
	if (line[start] == '\0')
	{
		free(line);
		return (NULL);
	}
	str = ft_substr(line, start, (ft_strlen(line) - start));
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain = ft_read_line(fd, remain);
	if (!remain)
		return (NULL);
	ret = ft_get_line(remain);
	remain = ft_remain(remain);
	return (ret);
}

/*int main()
{
	int fd = open("file.te", O_RDONLY);
	printf("[%s]",get_next_line(fd));
	printf("[%s]",get_next_line(fd));
	// printf("[%s]",get_next_line(fd));
	// printf("[%s]",get_next_line(fd));
	// printf("[%s]",get_next_line(fd));
}*/