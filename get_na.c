/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_na.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:23:28 by araiteb           #+#    #+#             */
/*   Updated: 2022/11/13 17:53:50 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
static char *remain;

char *get_line(int fd,char *line)
{
	char *str;
	int i;
	int len;
	char *ret;
	if (!line)
		return(NULL);
	if(remain)
	{
		str = ft_strdup(remain);
		str = ft_strjoin(str,line);
	}
	else
		str = ft_strdup(line);
	while(!ft_strchr(line,'\n') && (i = read(fd,line,BUFFER_SIZE)) > 0)
	{
		str = ft_strjoin(str,line);
	}
	if(ft_strchr(str,'\n'))
	{
		len = ft_strlen(str)- ft_strlen(ft_strchr(str,'\n'));
		ret = ft_substr(str,0,len+1);
		remain = ft_substr(str,len+1,ft_strlen(str));
		free(str);
		free(line);
		return(ret);
	}
	else  //if( i == 0)
	{
		//printf("line -->%s",line);
		return(str);
	}
}
char *get_next_line(int fd)
{
	char *line;
	char *rev;
	int i;
	line = ft_calloc((BUFFER_SIZE+1),sizeof(char));
	
	if( fd < 0 || (i = read(fd,line,BUFFER_SIZE) <= 0 ))
		return(NULL); 
	//printf("line __>%d\n",i);
	//sleep(1);
	rev = get_line(fd,line);
	free(line);
	line = NULL;
	return(rev);
}
int main()
 {
 	int fd = open("file.txt",O_RDONLY);
	 
 char *line ;//= get_next_line(fd);
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
	line = get_next_line(fd);
	while (line)
	{
		printf("%s",line);
		line = get_next_line(fd);
	}
 }