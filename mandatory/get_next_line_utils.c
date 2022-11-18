/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:40:15 by araiteb           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:23 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(const void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dst || src)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		i = 0;
		if (d == s || n == 0)
			return (d);
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (d);
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (void *)malloc(size * count);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	l1;
	size_t	l2;

	if (!s1)
		s1 = ft_strdup("");
	l2 = ft_strlen(s2);
	l1 = ft_strlen(s1);
	new = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!new)
		return (0);
	ft_memcpy(new, s1, l1);
	ft_memcpy((new + l1), s2, l2);
	new[l1 + l2] = '\0';
	free(s1);
	return (new);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)(s))[i] = '\0';
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if ((start + len) >= lens)
	{
		new = (char *)malloc(((lens - start) + 1) * sizeof(char));
		if (!new)
			return (0);
		ft_memcpy(new, (s + start), lens - start + 1);
		new[lens - start] = '\0';
		return (new);
	}
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (0);
	ft_memcpy(new, (s + start), len);
	new[len] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

int	ft_index(const char *s, char c)
{
	unsigned int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*tp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	tp = (char *)malloc((len + 1) * sizeof(char));
	if (!tp)
		return (NULL);
	while (*s)
		tp[i++] = *s++;
	tp[i] = '\0';
	return (tp);
}
