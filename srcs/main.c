/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:24:40 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/11 19:55:17 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**malloc_map(int fd, t_stuff *stuff)
{
	char	**map;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	if (!line || line[0] == 0)
	{
		free(line);
		error();
	}
	stuff->line_len = ft_strlen(line);
	while (line)
	{
		free(line);
		(stuff->line_count)++;
		line = get_next_line(fd);
	}
	map = malloc((stuff->line_count) * sizeof(char *));
	if (!map)
		error();
	return (map);
}

void	get_map(int fd, char **map, t_stuff *stuff)
{
	int	i;

	i = 0;
	map[i] = get_next_line(fd);
	if (!map[i])
		free_map_exit(map, i, "Error : gnl failed\n");
	i++;
	while (i < stuff->line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			free_map_exit(map, i, "Error : gnl failed\n");
		if (ft_strlen(map[i]) != stuff->line_len)
			free_map_exit2(map, i, "Error : unrectangular map\n");
		i++;
	}
	parse_map(map, stuff);
	return ;
}

void	init_stuff(t_stuff *stuff)
{
	stuff->line_count = 0;
	stuff->line_len = 0;
	stuff->player = 0;
	stuff->collectible = 0;
	stuff->exit = 0;
	return ;
}

void	check_file(char *file_name)
{
	int		len;
	int		i;
	char	*ext;

	ext = "reb.";
	len = ft_strlen(file_name);
	i = 4;
	if (len < 5)
		error_message("Error : invalid file name\n");
	while (len >= 5 && file_name[len - i])
	{
		if (file_name[len - i] != ext[i - 1] || (file_name[len - 5] == '/'))
			error_message("Error : invalid file name\n");
		i--;
	}
}

int	main(int ac, char **av)
{
	int		fd;
	t_stuff	stuff;
	char	**map;
	int		i;

	i = 0;
	init_stuff(&stuff);
	if (ac != 2)
		error();
	check_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error();
	map = malloc_map(fd, &stuff);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error();
	get_map(fd, map, &stuff);
	display_map(map, stuff);
	free_map(map, stuff.line_count);
	return (1);
}
