/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:39:29 by araiteb           #+#    #+#             */
/*   Updated: 2022/11/12 18:27:40 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include<fcntl.h>
#include<string.h>
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
int	ft_toupper(int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(const void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif