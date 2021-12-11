/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:01:14 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/11 20:43:01 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	direction(int keycode, t_combo *combo)
{
	if (keycode == 65307)
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	else if (keycode == 100
		&& combo->map[combo->stuff->y][combo->stuff->x + 1] != '1' &&
			win_cond_right(combo))
		move_right(combo);
	else if (keycode == 119
		&& combo->map[combo->stuff->y - 1][combo->stuff->x] != '1' &&
		win_cond_up(combo))
		move_up(combo);
	else if (keycode == 97
		&& combo->map[combo->stuff->y][combo->stuff->x - 1] != '1' &&
		win_cond_left(combo))
		move_left(combo);
	else if (keycode == 115
		&& combo->map[combo->stuff->y + 1][combo->stuff->x] != '1' &&
		win_cond_dowm(combo))
		move_down(combo);
	return (0);
}

void	move_right(t_combo *combo)
{
	if (combo->map[combo->stuff->y][combo->stuff->x + 1] == 'C')
		combo->stuff->collectible--;
	combo->map[combo->stuff->y][combo->stuff->x] = '0';
	if (combo->map[combo->stuff->y][combo->stuff->x + 1] == 'E' &&
		combo->stuff->collectible == 0)
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	combo->map[combo->stuff->y][combo->stuff->x + 1] = 'P';
	combo->stuff->x++;
	printf("%d\n", combo->count++);
	put_txt(combo->map, *combo->mlx, *combo->stuff);
}

void	move_up(t_combo *combo)
{
	if (combo->map[combo->stuff->y - 1][combo->stuff->x] == 'C')
		combo->stuff->collectible--;
	combo->map[combo->stuff->y][combo->stuff->x] = '0';
	if (combo->map[combo->stuff->y - 1][combo->stuff->x] == 'E' &&
		combo->stuff->collectible == 0)
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	combo->map[combo->stuff->y - 1][combo->stuff->x] = 'P';
	combo->stuff->y--;
	printf("%d\n", combo->count++);
	put_txt(combo->map, *combo->mlx, *combo->stuff);
}

void	move_left(t_combo *combo)
{
	if (combo->map[combo->stuff->y][combo->stuff->x - 1] == 'C')
		combo->stuff->collectible--;
	combo->map[combo->stuff->y][combo->stuff->x] = '0';
	if (combo->map[combo->stuff->y][combo->stuff->x - 1] == 'E'
		&& combo->stuff->collectible == 0)
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	combo->map[combo->stuff->y][combo->stuff->x - 1] = 'P';
	combo->stuff->x--;
	printf("%d\n", combo->count++);
	put_txt(combo->map, *combo->mlx, *combo->stuff);
}

void	move_down(t_combo *combo)
{
	if (combo->map[combo->stuff->y + 1][combo->stuff->x] == 'C')
		combo->stuff->collectible--;
	combo->map[combo->stuff->y][combo->stuff->x] = '0';
	if (combo->map[combo->stuff->y + 1][combo->stuff->x] == 'E'
		&& combo->stuff->collectible == 0)
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	combo->map[combo->stuff->y + 1][combo->stuff->x] = 'P';
	combo->stuff->y++;
	printf("%d\n", combo->count++);
	put_txt(combo->map, *combo->mlx, *combo->stuff);
}
