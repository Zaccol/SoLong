/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:14:29 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/01 05:34:56 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define BUFFER_SIZE 32

int	strchr_backslash(char *buf, int loop)
{
	int	i;

	i = 0;
	if (buf[i] == 0 && loop > 0)
		return (0);
	if (buf[i] == 0)
		return (1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	shift_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] == 0)
		return ;
	while (str[i] && str[i] != '\n')
		i++;
	if (i == BUFFER_SIZE)
	{
		str[0] = 0;
		return ;
	}
	i++;
	while (i < BUFFER_SIZE)
		str[j++] = str[i++];
	while (j < BUFFER_SIZE)
	{
		str[j] = '\0';
		j++;
	}
	return ;
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			ret_read;
	int			i;

	i = 0;
	ret_read = 0;
	line = NULL;
	line = ft_strcdup(buf, '\n');
	while (strchr_backslash(buf, i))
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read < 0)
			error();
		buf[ret_read] = 0;
		line = ft_strcjoin(line, buf, '\n');
		i++;
	}
	shift_str(buf);
	if (*buf == 0 && ret_read == 0 && ft_strclen(line, 0) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;
// 	int fd;
// 	char *s;

// 	fd = open("file1", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("fd error\n");
// 		return (0);
// 	}
// 	s = "";
// 	while (s)
// 	{
// 		s = get_next_line(fd);
// 		printf("write : %s\n", s);
// 		free(s);
// 	}
// 	return (1);
// }