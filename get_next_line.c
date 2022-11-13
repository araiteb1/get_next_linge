// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: araiteb <marvin@42.fr>                     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/10 20:42:13 by araiteb           #+#    #+#             */
// /*   Updated: 2022/11/13 16:09:37 by araiteb          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

# include "get_next_line.h"

// static char *remain;

// void	ft_free(char *tmp)
// {
// 	if(tmp)
// 	{
// 		free(tmp);
// 		tmp = NULL;
// 	}
// }

// void  ft_remain(char *str,int len)
// {
// 	remain = ft_substr(str,len,ft_strlen(str));
	
// } 
// char *ft_read_contnent(int fd)
// {
// 	int i;
// 	char *line;
// 	char *str=NULL;
// 	int len;
// 	char *tmp;
// 	char *strf=NULL;
// 	if(fd < 0)
// 		return(NULL);
// 	line = ft_calloc ((BUFFER_SIZE +1 ), sizeof(char));
// 	if(!line || (i = read(fd,line,BUFFER_SIZE)) < 0)
// 	{
// 		ft_free(line);
// 		return(NULL);
// 	}
// 		//line[BUFFER_SIZE] = '\0';
// 	if (remain)
// 	{
// 		tmp = str;
// 		str = ft_strdup(remain);
// 		ft_free(remain);
// 		ft_free(tmp);
// 	}
// 	if(str)
// 	{
// 		tmp = str;
// 		str = ft_strjoin(str,line);
// 		ft_free(tmp);
// 	}	
// 	else
// 	{
// 		tmp = str;
// 		str = ft_strdup(line);
// 		ft_free(tmp);
// 	}
// 	while(!ft_strchr(line,'\n') && (i = read(fd,line,BUFFER_SIZE))> 0 || )
// 	{
// 		line[BUFFER_SIZE] = '\0';
// 		tmp = str;
// 		str = ft_strjoin(str,line);
// 		ft_free(tmp);
// 	}
// 	printf("out \n");
// 	if(ft_strchr(str,'\n'))
// 	{
// 		len = ft_strlen(str) - ft_strlen(ft_strchr(str,'\n'));
// 		strf = ft_substr(str,0,len+1);
// 		ft_remain(str,len+1);
// 	}
// 	if(!ft_strchr(str,'\n'))
// 		strf = str;
// 	ft_free(str);
// 	ft_free(line);
// 	return(strf);
// }
// char	*get_next_line(int fd)
// {
// //	char *line;
// //	int i;
// 	if(fd < 0)
// 		return(NULL);
// 	return(ft_read_contnent(fd));
// }
//  int main()
//  {
//  	int fd = open("file.txt",O_RDONLY);
	 
//  char *line ;//= get_next_line(fd);
// // 	// printf("%s",get_next_line(fd));
// // 	// printf("%s",get_next_line(fd));
// // 	// printf("%s",get_next_line(fd));
// // 	// printf("%s",get_next_line(fd));
// // 	// printf("%s",get_next_line(fd));
// // 	// printf("%s",get_next_line(fd));
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s",line);
// 		line = get_next_line(fd);
// 	}	//sleep(1);
//  }
static char *remain;

char *get_line(int fd,char *line)
{
	char *str = NULL;
	int i;
	int len;
	char *ret;
	char *tmp;

	//printf("line:%s\n",line);
	//printf("remain:%s\n",remain);
	if (line[0] =='\0' && !remain)
	{
		return(NULL);
	}
	if(remain != NULL)
	{
		tmp = str;
		str = ft_strdup(remain);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str,line);
		free(tmp);
		free(remain);
		remain = NULL;
	}
	else
	{
		tmp = str;
		str = ft_strdup(line);
		free(tmp);
	}
	while(!ft_strchr(line,'\n') && (i = read(fd,line,BUFFER_SIZE)) > 0)
	{
		tmp = str;
		str = ft_strjoin(str,line);
		free(tmp);
	}
	if(ft_strchr(str,'\n'))
	{
		len = ft_strlen(str)- ft_strlen(ft_strchr(str,'\n'));
		ret = ft_substr(str,0,len+1);
		tmp = remain;
		remain = ft_substr(str,len+1,ft_strlen(str));

		free(tmp);
		free(str);
		//free(line);
		// printf("str:%p\n",str);
		// printf("ret:%p\n",ret);
		// printf("line:%p\n",line);
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
		//printf("remain:%s\n",remain);
	line = ft_calloc((BUFFER_SIZE+1),sizeof(char));
	
	if( fd < 0 || (i = read(fd,line,BUFFER_SIZE) < 0 ))
	{
		free(line);
		line = NULL;
		//printf("line __>%d\n",i);
		return(NULL); 
	}
	//sleep(1);
	rev = get_line(fd,line);
	free(line);
	line = NULL;
	return(rev);
}
 int main()
 {
 	int fd = open("file.txt",O_RDONLY);
	 
// char *line ;//= get_next_line(fd);
	 printf("%s",get_next_line(fd));
	 printf("%s",get_next_line(fd));
	 //printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
	// line = get_next_line(fd);
 }