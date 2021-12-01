/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:24:40 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/01 06:20:01 by lzaccome         ###   ########.fr       */
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
	printf("line : %s\n", line);
	while (line)
	{
		free(line);
		(stuff->line_count)++;
		line = get_next_line(fd);
		printf("line : %s\n", line);
		// if (line_len != ft_strlen(line)) /* a ajouter aund les lignes sont recuperees */
		// 	error();
	}
	printf("i : %d\n", (stuff->line_count));
	// map = malloc((stuff->line_count) * stuff->line_len);
	map = malloc((stuff->line_count) * sizeof(char *));
	if (!map)
		error();
	return (map);
}

int	is_wrong_elem(char c, t_stuff *stuff)
{
	if (c == '0')
		return 0;
	else if (c == '1')
		return 0;
	else if (c == 'E')
	{
		stuff->exit++;
		return 0;
	}
	else if (c == 'P')
	{
		stuff->player++;
		if (stuff->player != 1)
			return 1;
		return 0;
	}
	else if (c == 'C')
	{
		stuff->collectible++;
		return 0;
	}
	return 1;
}

void	verif_map(char **map, t_stuff *stuff)
{
	if (stuff->collectible < 1)
		free_map_exit(map, stuff->line_count, "Error : no collectible\n");
	if (stuff->exit < 1)
		free_map_exit(map, stuff->line_count, "Error : no exit\n");
	if (stuff->player == 0)
		free_map_exit(map, stuff->line_count, "Error : no player\n");
}

void	parse_map(char **map, t_stuff *stuff)
{
	int i;
	int j;

	i = 0;
	while(map && stuff && i < stuff->line_count && map[i])
	{
		j = 0;
		while (i < stuff->line_count && map[i][j])
		{
			printf("\nchar : %c\nline : %d\ncol : %d\n\n", map[i][j], i, j);
			if ((i == 0 || i == stuff->line_count - 1) && map[i][j] != '1')
				free_map_exit(map, stuff->line_count, "Error : unclosed map\n");
			else 
				if ((j == 0 || j == stuff->line_len - 1) && map[i][j] != '1')
					free_map_exit(map, stuff->line_count, "Error : unclosed map\n");
				else if (is_wrong_elem(map[i][j], stuff))
					free_map_exit(map, stuff->line_count, "Error : invalid element in map\n");
			j++;
		}
		i++;
	}
	verif_map(map, stuff);
	return ;		
}

void	get_map(int fd, char **map, t_stuff *stuff)
{
	// int line_len;
	int	i;

	i = 0;
	map[i] = get_next_line(fd);
	printf("map : %s\n", map[i]);
	// line_len = ft_strlen(map[i]);
	i++;
	while (i < stuff->line_count)
	{
		map[i] = get_next_line(fd);
		printf("map : %s\n", map[i]);
		if (ft_strlen(map[i]) != stuff->line_len)
			free_map_exit(map, i, "Error : unrectangular map\n");
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
	int len;
	int i;
	char *ext;

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
	t_stuff stuff;
	char	**map;
	int i;

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
	
	while (i < stuff.line_count)
	{
		printf("map1 : %s\n", map[i]);
		i++;
	}
	free_map(map, stuff.line_count);
	return (1);
}