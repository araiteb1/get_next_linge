/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_na.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:23:28 by araiteb           #+#    #+#             */
/*   Updated: 2022/11/13 16:31:45 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
char *get_line(int fd,char *line)
{
	char *str;
	
	if (!line)
		return(NULL);
	str = ft_strdup(line);
	while(!ft_strchr(line,'\n') && (i = read(fd,line,BUFFER_SIZE) > 0))
	{
		
	}
}
char *get_next_line(int fd)
{
	char *line;
	char *rev;
	int i;
	if(fd < 0 || i = read(fd,line,BUFFER_SIZE) < 0)
		return(NULL);
	rev = get_line;
	return(rev);
}