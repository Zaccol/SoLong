/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:07:37 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/01 06:14:11 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	error_message(char *message)
{
	ft_putstr(message);
	exit(EXIT_FAILURE);
}

void	free_map_exit(char **map, int line_failed, char *message)
{
	int i;

	i = 0;
	while (i < line_failed)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_putstr(message);
	exit(EXIT_FAILURE);
}

void	free_map(char **map, int line_count)
{
	int i;

	i = 0;
	while (i < line_count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}