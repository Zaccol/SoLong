/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:30:52 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/11 20:31:04 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	win_cond_right(t_combo *combo)
{
	if (combo->map[combo->stuff->y][combo->stuff->x + 1] != 'E' ||
		(combo->map[combo->stuff->y][combo->stuff->x + 1] == 'E' &&
		combo->stuff->collectible == 0))
		return (1);
	return (0);
}

int	win_cond_up(t_combo *combo)
{
	if (combo->map[combo->stuff->y - 1][combo->stuff->x] != 'E' ||
		(combo->map[combo->stuff->y - 1][combo->stuff->x] == 'E' &&
		combo->stuff->collectible == 0))
		return (1);
	return (0);
}

int	win_cond_left(t_combo *combo)
{
	if (combo->map[combo->stuff->y][combo->stuff->x - 1] != 'E' ||
		(combo->map[combo->stuff->y][combo->stuff->x - 1] == 'E' &&
		combo->stuff->collectible == 0))
		return (1);
	return (0);
}

int	win_cond_dowm(t_combo *combo)
{
	if (combo->map[combo->stuff->y + 1][combo->stuff->x] != 'E' ||
		(combo->map[combo->stuff->y + 1][combo->stuff->x] == 'E' &&
		combo->stuff->collectible == 0))
		return (1);
	return (0);
}
