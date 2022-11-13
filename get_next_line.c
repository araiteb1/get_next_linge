/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:42:13 by araiteb           #+#    #+#             */
/*   Updated: 2022/11/13 16:09:37 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

static char *remain;

void	ft_free(char *tmp)
{
	if(tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

void  ft_remain(char *str,int len)
{
	remain = ft_substr(str,len,ft_strlen(str));
	
} 
char *ft_read_contnent(int fd)
{
	int i;
	char *line;
	char *str=NULL;
	int len;
	char *tmp;
	char *strf=NULL;
	if(fd < 0)
		return(NULL);
	line = ft_calloc ((BUFFER_SIZE +1 ), sizeof(char));
	if(!line || (i = read(fd,line,BUFFER_SIZE)) < 0)
	{
		ft_free(line);
		return(NULL);
	}
		//line[BUFFER_SIZE] = '\0';
	if (remain)
	{
		tmp = str;
		str = ft_strdup(remain);
		ft_free(remain);
		ft_free(tmp);
	}
	if(str)
	{
		tmp = str;
		str = ft_strjoin(str,line);
		ft_free(tmp);
	}	
	else
	{
		tmp = str;
		str = ft_strdup(line);
		ft_free(tmp);
	}
	while(!ft_strchr(line,'\n') && (i = read(fd,line,BUFFER_SIZE))> 0 || )
	{
		line[BUFFER_SIZE] = '\0';
		tmp = str;
		str = ft_strjoin(str,line);
		ft_free(tmp);
	}
	printf("out \n");
	if(ft_strchr(str,'\n'))
	{
		len = ft_strlen(str) - ft_strlen(ft_strchr(str,'\n'));
		strf = ft_substr(str,0,len+1);
		ft_remain(str,len+1);
	}
	if(!ft_strchr(str,'\n'))
		strf = str;
	ft_free(str);
	ft_free(line);
	return(strf);
}
char	*get_next_line(int fd)
{
//	char *line;
//	int i;
	if(fd < 0)
		return(NULL);
	return(ft_read_contnent(fd));
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
	}	//sleep(1);
 }