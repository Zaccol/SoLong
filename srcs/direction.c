/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:01:14 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/10 21:44:47 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// texture exit bloquante si collectible encore sur la map. ajouter une condition sur la texture exit pour fermer 
// la fenetre si tous les collect ont ete ramasser 

int	direction(int keycode, t_combo *combo)
{
	if (keycode == 65307)
		free_mlx(combo->mlx);
	if (keycode == 100 && combo->map[combo->stuff->y][combo->stuff->x + 1] != '1')
	{
		if (combo->map[combo->stuff->y][combo->stuff->x + 1] != 'C')
			combo->stuff->collectible--;
		combo->map[combo->stuff->y][combo->stuff->x] = '0';
		combo->map[combo->stuff->y][combo->stuff->x + 1] = 'P';
		combo->stuff->x++;
		printf("%d\n", combo->count++);
		put_txt(combo->map, *combo->mlx, *combo->stuff);
		return (0);
	}
	if (keycode == 119 && combo->map[combo->stuff->y - 1][combo->stuff->x] != '1')
	{
		if (combo->map[combo->stuff->y - 1][combo->stuff->x] != 'C')
			combo->stuff->collectible--;
		combo->map[combo->stuff->y][combo->stuff->x] = '0';
		combo->map[combo->stuff->y - 1][combo->stuff->x] = 'P';
		combo->stuff->y--;
		printf("%d\n", combo->count++);
		put_txt(combo->map, *combo->mlx, *combo->stuff);
		return (0);
	}
	if (keycode == 97 && combo->map[combo->stuff->y][combo->stuff->x - 1] != '1')
	{
		if (combo->map[combo->stuff->y][combo->stuff->x - 1] != 'C')
			combo->stuff->collectible--;
		combo->map[combo->stuff->y][combo->stuff->x] = '0';
		combo->map[combo->stuff->y][combo->stuff->x - 1] = 'P';
		combo->stuff->x--;
		printf("%d\n", combo->count++);
		put_txt(combo->map, *combo->mlx, *combo->stuff);
		return (0);
	}
	if (keycode == 115 && combo->map[combo->stuff->y + 1][combo->stuff->x] != '1')
	{
		if (combo->map[combo->stuff->y + 1][combo->stuff->x] != 'C')
			combo->stuff->collectible--;
		combo->map[combo->stuff->y][combo->stuff->x] = '0';
		combo->map[combo->stuff->y + 1][combo->stuff->x] = 'P';
		combo->stuff->y++;
		printf("%d\n", combo->count++);
		put_txt(combo->map, *combo->mlx, *combo->stuff);
		return (0);
	}
	return (0);
}