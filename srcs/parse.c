/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:51:23 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/11 19:56:22 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_wrong_elem(char c, t_stuff *stuff, int i, int j)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == 'E')
	{
		stuff->exit++;
		return (0);
	}
	else if (c == 'P')
	{
		stuff->player++;
		if (stuff->player != 1)
			return (1);
		stuff->x = j;
		stuff->y = i;
		return (0);
	}
	else if (c == 'C')
	{
		stuff->collectible++;
		return (0);
	}
	return (1);
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
	int		i;
	int		j;

	i = 0;
	while (map && stuff && i < stuff->line_count && map[i])
	{
		j = 0;
		while (i < stuff->line_count && map[i][j])
		{
			if ((i == 0 || i == stuff->line_count - 1) && map[i][j] != '1')
				free_map_exit(map, stuff->line_count, "Err: unclosed map\n");
			else
				if ((j == 0 || j == stuff->line_len - 1) && map[i][j] != '1')
					free_map_exit(map, stuff->line_count, "Err: unclosed map\n");
			else if (is_wrong_elem(map[i][j], stuff, i, j))
				free_map_exit(map, stuff->line_count, "Err: invalid element\n");
			j++;
		}
		i++;
	}
	verif_map(map, stuff);
	return ;
}
