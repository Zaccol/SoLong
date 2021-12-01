/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:20:57 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/01 05:38:45 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strclen(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strcdup(char *s, char c)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strclen(s, c);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		free(s);
		exit (0);
	}
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcjoin(char *s1, char *s2, char c)
{
	char	*join;
	size_t	len;
	int		s1_len;
	int		i;
	int		y;

	s1_len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		s1_len = ft_strlen(s1);
	len = (s1_len + ft_strclen(s2, c));
	join = malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	y = -1;
	while (s1[++y])
		join[i++] = s1[y];
	while (*s2 && *s2 != c)
		join[i++] = *(s2++);
	join[i] = '\0';
	if (s1)
		free(s1);
	return (join);
}

char	*ft_strchr(char *s, char c)
{
	while (s && *s && *s != c)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}
